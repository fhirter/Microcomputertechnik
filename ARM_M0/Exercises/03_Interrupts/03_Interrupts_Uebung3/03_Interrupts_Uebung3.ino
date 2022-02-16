#include <NRF52_MBED_TimerInterrupt.h>
#include <NRF52_MBED_ISR_Timer.h>

const byte interruptPin = 2;

volatile uint8_t buttonFlag = 0;
volatile uint8_t isTimerEnabled = 0;
volatile uint8_t buttonCounter = 0;

const uint16_t TIMER_INTERVAL_MS = 20;
NRF52_MBED_Timer ITimer(NRF_TIMER_3);

void setup() {
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, FALLING);
    Serial.begin(9600);

    while(1) {
      if(buttonFlag == 1) {
          Serial.print("button pressed");
          Serial.println(digitalRead(interruptPin));
          buttonFlag = 0;
      }
    }
}

void loop() {

}

// button ISR
void buttonISR() {
    if(!isTimerEnabled) {
        // start 20ms timer
        if(ITimer.attachInterruptInterval(TIMER_INTERVAL_MS*1000, timerISR)) {
            Serial.print(F("Starting ITimer3 OK"));
        } else {
            Serial.print(F("Starting ITimer3 Failed"));
        }
        isTimerEnabled = 1;
    }
}

// timer ISR
void timerISR() {
    if(digitalRead(interruptPin) == 0) {
        buttonCounter++;
    }

    if(buttonCounter >= 5) {
        buttonFlag = 1;
        // disabling interrupt (detachInterrupt) is not working.
        isTimerEnabled = 0;
        buttonCounter = 0;
    }
}
