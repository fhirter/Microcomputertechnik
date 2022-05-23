#include <Arduino_FreeRTOS.h>
#include <queue.h>

#include <avr/sleep.h>
#include <avr/power.h>

void TaskRun( void *pvParameters );
void TaskReadInputs( void *pvParameters );
QueueHandle_t voltagesQueue;

typedef struct {
	float battery;
	float panel;
} Voltages;


void setup() { 
  // initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
		
	// create a queue with 10 entries, each holding a Voltages struct.
	voltagesQueue = xQueueCreate( 10, sizeof( Voltages ) );

	if(voltagesQueue == NULL){
		Serial.println("Error creating the queue");
	}
	
	xTaskCreate(
		TaskRun	/* Function that implements the task. */
		,  "Run Task"  /* Text name for the task. */
		,  128   	/* Stack size in words, not bytes. */
		,  NULL		/* Parameter passed into the task. */
		,  2  		/* Priority at which the task is created. */
		,  NULL );	/* Used to pass out the created task's handle. */
		
	xTaskCreate(
		TaskReadInputs	/* Function that implements the task. */
		,  "Read Inputs"  /* Text name for the task. */
		,  128   	/* Stack size in words, not bytes. */
		,  NULL		/* Parameter passed into the task. */
		,  1  		/* Priority at which the task is created. */
		,  NULL );	/* Used to pass out the created task's handle. */
}

void loop() {
	
}

void TaskRun( void *pvParameters ) {
	Voltages voltages;
	
	while(1) {	
		xQueueReceive(voltagesQueue, &voltages, portMAX_DELAY);
		
		if(voltages.panel > 5) {
			Serial.println("Panel Voltage > 5V");

			if(voltages.battery > 12) {	
				Serial.println("Battery Voltage > 12V");
			} else {
				Serial.println("Battery Voltage < 12V");
			}
		}
				
		vTaskDelay( 1000 / portTICK_PERIOD_MS );	//wait vor 1s
	}
}

void TaskReadInputs( void *pvParameters ) {
	Voltages voltages = {0 , 0};
	
	while(1) {
		Serial.println("####### Reading Inputs #######");

		voltages.battery = analogRead(A7)* (5.0 / 1023.0)*4*0.9453; 
		voltages.panel = analogRead(A6)* (5.0 / 1023.0)*10*1.0652;

		Serial.print("Battery Voltage: ");
		Serial.println(voltages.battery);

		Serial.print("Panel Voltage: ");
		Serial.println(voltages.panel);
		
		xQueueSend(voltagesQueue, &voltages, portMAX_DELAY);
		
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}
}