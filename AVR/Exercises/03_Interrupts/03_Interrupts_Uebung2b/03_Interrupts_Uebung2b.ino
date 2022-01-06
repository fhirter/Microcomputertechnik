#include "timer-api.h"

// Untested!


const byte interruptPin = 2;
volatile bool enableBlinking = 1;
volatile bool state = 1;

unsigned long referenceTime = 0;

unsigned long prevTime = 0;

// the setup function runs once when you press reset or power the board
void setup() {
// initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    Serial.begin(9600);

    referenceTime = micros();

    timer_init_ISR_1Hz(TIMER_DEFAULT);
}

void loop() {
    float d = 1000000;

    delay(100);     // deltaTime does not depend on this delay
}

void blink() {
    enableBlinking = !enableBlinking;
}

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