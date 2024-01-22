#include "timer-api.h"

const byte interruptPin = 2;

volatile uint8_t buttonFlag = 0;
volatile uint8_t isTimerEnabled = 0;

void setup() {
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    Serial.begin(9600);
}

void loop() {
    if(buttonFlag == 1) {
        Serial.println("button pressed");
        buttonFlag = 0;
    }
}

// button ISR
void blink() {
    if(!isTimerEnabled) {
        // initialize and start 20ms timer
        timer_init_ISR_50Hz(TIMER_DEFAULT);
        isTimerEnabled = 1;
    }
}

// timer ISR
void timer_handle_interrupts(int timer) {
    static uint8_t buttonCounter = 0;
    if(digitalRead(interruptPin) == 0) {
        buttonCounter++;
        Serial.print(buttonCounter);
    }

    if(buttonCounter >= 5) {
        buttonFlag = 1;
        timer_stop_ISR(TIMER_DEFAULT);
        isTimerEnabled = 0;
        buttonCounter = 0;
    }
}