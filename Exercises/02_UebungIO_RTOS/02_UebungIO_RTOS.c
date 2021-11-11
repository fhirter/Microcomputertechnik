/**
 * Copy Paste into Arduino IDE to run this file.
 */


#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <task.h>
#include <semphr.h>

// Constants
const uint8_t INTERRUPT_PIN = 2;

// Types
enum States {
    ST_OFF,
    ST_ON,
    ST_BLINK,
    ST_DARK
};

// Tasks
void TaskStateMachine(void *pvParameters);

void TaskReadInputs(void *pvParameters);

// ISR
void switch_isr(void);

// Task Handlers
TaskHandle_t xStateMachineTaskHandle;
TaskHandle_t xReadInputsTaskHandle;

// Queue Handlers
QueueHandle_t xVoltageQueue;

// the setup function runs once when you press reset or power the board
void setup() {

    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);

    while (!Serial) { ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
    }

    Serial.println("Setup");

    // Lege den Interruptpin als Inputpin mit Pullupwiderstand fest
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);

    // Execute the interrupt service routine (ISR) "switch_isr" on falling edge of "INTERRUPT_PIN"
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), switch_isr, FALLING);

    // Create queue for Voltage Value
    xVoltageQueue = xQueueCreate(1, sizeof(float));

    // Set up two tasks to run independently.
    xTaskCreate(
            TaskStateMachine,
            "Blink",   // A name just for humans
            128,       // Stack Size
            NULL,
            1,         // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
            &xStateMachineTaskHandle    // Task Handle
    );

    xTaskCreate(
            TaskReadInputs,
            "Read Inputs",
            128,     // Stack size
            NULL,
            2,         // Priority
            &xReadInputsTaskHandle
    );

    // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop() {
    //  Serial.println("idle");
}

/*---------------------- Tasks ---------------------*/
void TaskStateMachine(void *pvParameters) {
    Serial.println("Starting Task 'TaskBlink'");


    States state = ST_OFF;
    float voltage;

    pinMode(LED_BUILTIN, OUTPUT);

    uint32_t buttonNotificationCount;

    while (1) {
        // clear notification count on exit, don't wait
        buttonNotificationCount = ulTaskNotifyTake(pdTRUE, 0);

        xQueueReceive(xVoltageQueue, &voltage, (TickType_t) 0);

        // State Transition Logic)
        switch (state) {
            case ST_OFF:
                if (buttonNotificationCount > 0 ) {
                    state = ST_DARK;
                }
                break;

            case ST_BLINK:
                if (buttonNotificationCount > 0) {
                    state = ST_OFF;
                } else if (voltage < 0.1) {
                    state = ST_DARK;
                } else if (voltage > 4.9) {
                    state = ST_ON;
                }
                break;

            case ST_ON:
                if (buttonNotificationCount > 0) {
                    state = ST_OFF;
                } else if (voltage <= 4.9) {
                    state = ST_BLINK;
                }
                break;

            case ST_DARK:
                if (voltage >= 0.1) {
                    state = ST_BLINK;
                }
                break;

            default:
                state = ST_OFF;
        }

        // Outputs
        switch (state) {
            case ST_OFF:
                Serial.println("OFF");

                digitalWrite(LED_BUILTIN, LOW);

                vTaskDelay(10);

                break;
            case ST_DARK:
                Serial.println("DARK");

                digitalWrite(LED_BUILTIN, LOW);

                vTaskDelay(10);

                break;

            case ST_ON:
                Serial.println("ON");

                digitalWrite(LED_BUILTIN, HIGH);

                vTaskDelay(10);

                break;

            case ST_BLINK:
                Serial.println("BLINK");

                float frequency = 1.9 * voltage + 0.8;
                float d = (1 / frequency) * 1000;
                digitalWrite(LED_BUILTIN, HIGH);               // turn the LED on
                vTaskDelay(d / (portTICK_PERIOD_MS * 2));     // wait
                digitalWrite(LED_BUILTIN, LOW);                // turn the LED off
                vTaskDelay(d / (portTICK_PERIOD_MS * 2));

                break;
        }
    }
}

/**
* Read Inputs Voltage and Button. Send values to blink task
*
* Notifications from ISR are processed immediatly, voltage is being read every 100ms.
*
*/
void TaskReadInputs(void *pvParameters) {  // This is a task.
    Serial.println("Starting Task 'TaskReadInputs'");

    float voltage;

    uint32_t buttonNotificationCount;

    while (1) {
        int sensorValue = analogRead(A0);

        voltage = sensorValue * (5.0 / 1023.0);

        // send voltage value to queue, don't wait if queue is full
        xQueueSendToFront(xVoltageQueue, (void *) &voltage, (TickType_t) 0);

        // clear notification count on exit
        // wait for 100ms for a notification.
        buttonNotificationCount = ulTaskNotifyTake(pdTRUE, (TickType_t) 100 / portTICK_PERIOD_MS);

        // Debouncing:
        // if button isr sends notifications read button value 5 times with 10ms delay inbetween.
        // When button state was 0 each time, send notification to State Machine Task
        if (buttonNotificationCount > 0) {
            uint8_t counter = 0;
            for (uint8_t i = 0; i < 5; i++) {
                vTaskDelay(10 / portTICK_PERIOD_MS);
                if (digitalRead(INTERRUPT_PIN) == 0) {
                    counter++;
                }
            }
            if (counter == 5) {
                xTaskNotifyGive(xStateMachineTaskHandle);
            }
        }
    }
}

/*---------------------- ISR ---------------------*/
void switch_isr(void) {
    static BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    vTaskNotifyGiveFromISR(xReadInputsTaskHandle, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken) {
        taskYIELD();
    }
}