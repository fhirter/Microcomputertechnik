#include "HAL/Print.h"

const uint8_t BUTTON_PIN2 = 3; //PD3;

void cExamples() {
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
