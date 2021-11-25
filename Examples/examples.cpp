#include "examples.h"
#include <cstdint>
#include <iostream>

enum state_t {
    ST_OPEN,
    ST_CLOSED,
};

// commit test

state_t getNextState(state_t state, uint8_t input);

int main() {
    cExamples();

    enum state_t state = ST_CLOSED;

    for(uint8_t input = 0; input < 10; input++) {
        state = getNextState(state, input);
    }
}

void cExamples() {
    // arrays
    uint8_t numbers[] = {17, 0, 3};
    uint8_t foo[10];
    char string[] = "Hallo, Welt!\n";

    uint8_t invalid = numbers[4];

    struct person {
        char *first_name;
        char last_name[20];
        uint16_t year_of_birth;
        double height;
    };

    struct person fabian = {"fabian", "hirter", 1910, 120};

    // pointer
    int value = 50;
    int array[3] = {5,3,4};
    int *pointer1;  // kann eine Adresse aufnehmen, die auf einen Wert vom Typ Integer zeigt
    int *pointer2;
    pointer1 = &value;     // Adresse einer Variablen
    pointer2 = array;      // array wird zum pointer auf das erste element

    // pointer arithmetik und zugriff auf element mit [n] sind gleichwertig.
    int fubar1 = array[2];
    int fubar2 = *(pointer2+2);

    *pointer1 = 5; // wert an adresse schreiben
}

enum state_t getNextState(state_t currentState, uint8_t input) {
    enum state_t nextState;

    switch (currentState) {
        case ST_OPEN:
            // do something
            printf("%d", ST_OPEN);


            if(input % 2) {
                nextState = ST_CLOSED;
            }

            break;
        case ST_CLOSED:
            printf("%d", ST_CLOSED);
            // do something else

            if(!(input%2)) {
                nextState = ST_OPEN;
            }
            break;
        default:
            break;
    }
    return nextState;
}
