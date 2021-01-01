//
// Created by fabian on 01.01.21.
//

#include "Arduino.h"

int main() {
    setup();

    while(1) {
        loop();
    }

}

void sei() {

}


void pinMode(uint8_t pin, uint8_t mode) {

}

int analogRead(uint8_t pin) {
    return rand();
}

void analogWrite(uint8_t pin, int val) {
    char str[80];

    sprintf(str, "analog value: %d", val);
    puts(str);
}

void digitalWrite(uint8_t pin, uint8_t val) {
    char str[80];

    sprintf(str, "digital value: %d", val);
    puts(str);
}

int digitalRead(uint8_t pin) {

}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {

}

void detachInterrupt(uint8_t interruptNum) {

}