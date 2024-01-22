#include "timer-api.h"

const byte interruptPin = 2;
volatile bool enableBlinking = 1;
volatile bool state = 1;

unsigned long referenceTime = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    Serial.begin(9600);

    referenceTime = micros();

    timer_init_ISR_1Hz(TIMER_DEFAULT);
}

void loop() {
    delay(10000);     // deltaTime does not depend on this delay
}

// button ISR
void blink() {
    enableBlinking = !enableBlinking;
}

// timer ISR
void timer_handle_interrupts(int timer) {
    unsigned long currentTime = micros();
    unsigned long deltaTime = currentTime - referenceTime;

    Serial.println(deltaTime, DEC);

    if (enableBlinking == 1) {
        digitalWrite(LED_BUILTIN, state);
        state = !state;
        referenceTime = currentTime;        // reset time
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
}