#include <NRF52_MBED_TimerInterrupt.h>
#include <NRF52_MBED_ISR_Timer.h>


const byte interruptPin = 2;
volatile bool enableBlinking = 1;
volatile bool state = 1;

unsigned long referenceTime = 0;
unsigned long deltaTime = 0;

const uint16_t TIMER_INTERVAL_MS = 1000;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    Serial.begin(9600);

    referenceTime = micros();

    NRF52_MBED_Timer ITimer(NRF_TIMER_3);
    if(ITimer.attachInterruptInterval(TIMER_INTERVAL_MS*1000, timer_handle_interrupts)) {
        Serial.print(F("Starting ITimer3 OK"));
    } else {
        Serial.print(F("Starting ITimer3 Failed"));
    }
}

void loop() {
    delay(TIMER_INTERVAL_MS);     // deltaTime does not depend on this delay

    Serial.println(deltaTime, DEC);
}

// button ISR
void blink() {
    enableBlinking = !enableBlinking;
}

// timer ISR
void timer_handle_interrupts() {
    unsigned long currentTime = micros();
    deltaTime = currentTime - referenceTime;

    if (enableBlinking == 1) {
        digitalWrite(LED_BUILTIN, state);
        state = !state;
        referenceTime = currentTime;        // reset time
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
}