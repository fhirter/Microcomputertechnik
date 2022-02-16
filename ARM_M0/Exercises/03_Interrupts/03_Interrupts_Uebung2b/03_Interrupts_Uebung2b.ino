#include <NRF52_MBED_TimerInterrupt.h>
#include <NRF52_MBED_ISR_Timer.h>

volatile bool enableBlinking = 1;
volatile bool state = 1;

const byte INTERRUPT_PIN = 2;
const uint16_t TIMER_INTERVAL_MS = 2000;

volatile unsigned long referenceTime = micros();
volatile unsigned long deltaTime = 0;

void timerISR();
void buttonISR();

void setup() {
    NRF52_MBED_Timer ITimer(NRF_TIMER_3);
    if(ITimer.attachInterruptInterval(TIMER_INTERVAL_MS*1000, timerISR)) {
        Serial.print(F("Starting ITimer3 OK"));
    } else {
        Serial.print(F("Starting ITimer3 Failed"));
    }

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), buttonISR, FALLING);

    while(1) {
        Serial.println(deltaTime);
    }
}

void loop() {

}

void buttonISR() {
    enableBlinking = !enableBlinking;
}

void timerISR() {
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