#include <NRF52_MBED_TimerInterrupt.h>
#include <NRF52_MBED_ISR_Timer.h>

const byte interruptPin = 2;

volatile uint8_t buttonFlag = 0;
volatile uint8_t isTimerEnabled = 0;

const uint16_t TIMER_INTERVAL_MS = 20;
NRF52_MBED_Timer ITimer(NRF_TIMER_3);

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
        // start 20ms timer
        if(ITimer.attachInterruptInterval(TIMER_INTERVAL_MS*1000, timer_handle_interrupts)) {
            Serial.print(F("Starting ITimer3 OK"));
        } else {
            Serial.print(F("Starting ITimer3 Failed"));
        }
        isTimerEnabled = 1;
    }
}

// timer ISR
void timer_handle_interrupts() {
    static uint8_t buttonCounter = 0;
    if(digitalRead(interruptPin)) {
        buttonCounter++;
    }

    if(buttonCounter >= 5) {
        buttonFlag = 1;
        ITimer.stopTimer();
        isTimerEnabled = 0;
        buttonCounter = 0;
    }
}