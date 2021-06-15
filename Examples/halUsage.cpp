#include "../HAL/Arduino.h"
#include "../HAL/Print.h"

volatile bool enable_blinking = true;
volatile bool update_timer = true;
const uint8_t BUTTON_PIN = 2;   //PD2;
const uint8_t BUTTON_PIN2 = 3; //PD3;

void setupIO() {
    // todo: implement Serial Mock
//    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUTTON_PIN2, INPUT_PULLUP);

//    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggle_blinking, FALLING);
//    init_button_interrupt_int1();

    interrupts(); // enable global interrupts

    enable_blinking = 1;
}
void readSensors() {
    int sensorValue = analogRead(A0);

    float voltage = sensorValue*(5.0 / 1023.0);
    float frequency = 1.9 * voltage + 0.8;

//    Serial.println("Hello World");

    float delay_time_s = (1/frequency);

    if(voltage < 0.1) {
        digitalWrite(LED_BUILTIN, LOW);
    } else if(voltage > 4.9) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
        if(update_timer) {
//            Serial.println(delay_time_s);
//            init_timer_interrupt(delay_time_s);
//            update_timer = false;
        }
    }
}
