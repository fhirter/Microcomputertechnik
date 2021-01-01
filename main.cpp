#include <iostream>
#include "Arduino.h"
#include "Print.h"

volatile bool enable_blinking = true;
volatile bool update_timer = true;
const uint8_t BUTTON_PIN = 2;   //PD2;
const uint8_t BUTTON_PIN2 = 3; //PD3;

void setup() {
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUTTON_PIN2, INPUT_PULLUP);

//    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggle_blinking, FALLING);
//    init_button_interrupt_int1();

    interrupts(); // enable global interrupts

    enable_blinking = 1;
}

void loop() {
    int sensorValue = analogRead(A0);

    float voltage = sensorValue*(5.0 / 1023.0);
    float frequency = 1.9 * voltage + 0.8;

    Serial.println("Hello World");

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

    typedef enum {
        ST_OPEN,
        ST_CLOSED,
    } state_t;

    state_t currentState = ST_OPEN;

    for(uint8_t i = 0;i<10;i++) {
        if(i%2) {
            currentState = ST_OPEN;
        } else {
            currentState = ST_CLOSED;
        }
        switch (currentState) {
            case ST_OPEN:
                // do something
                printf("%d", ST_OPEN);
                break;
            case ST_CLOSED:
                printf("%d", ST_CLOSED);
                // do something else
                break;
            default:
                break;
        }
    }

    // arrays
    uint8_t numbers[] = {17, 0, 3};
    char string[] = "Hallo, Welt!\n";

    struct person {
        char *first_name;
        char last_name[20];
        int year_of_birth;
        double height;
    };

    struct person fabian = {"fabian", "hirter", 1986, 180};

    // pointer
    int value = 0;
    int array[10];
    int *pointer1;  // kann eine Adresse aufnehmen, die auf einen Wert vom Typ Integer zeigt
    int *pointer2;
    pointer1 = &value;     //  Adresse einer Variablen
    pointer2 = array;          /* mit Feld */

    *pointer1 = 5; // wert an adresse schreiben
}
