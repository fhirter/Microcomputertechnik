//
// Created by Fabian on 09.12.21.
//

#include "stateMachine.h"

const int ALARM_LEVEL1 = 10000;
const int ALARM_LEVEL2 = 5000;
const int ALARM_LEVEL3 = 2000;

enum alarmState {
    ST_NO_ALARM,
    ST_ALARM_LEVEL_1,
    ST_ALARM_LEVEL_2,
    ST_ALARM_LEVEL_3
};

enum alarmState getNextState(alarmState currentState, int ppmValue) {
    enum alarmState nextState = ST_NO_ALARM;
    if (ppmValue >= ALARM_LEVEL1) {
        nextState = ST_ALARM_LEVEL_1;
    } else if (ppmValue >= ALARM_LEVEL2) {
        nextState = ST_ALARM_LEVEL_2;
    } else if (ppmValue >= ALARM_LEVEL3) {
        nextState = ST_ALARM_LEVEL_3;
    } else {
        nextState = ST_NO_ALARM;
    }
    return nextState;
}

void setOutput(enum alarmState currentState) {
    switch(currentState) {
        case ST_ALARM_LEVEL_1:
            buzzerOn(1);
            break;
        case ST_ALARM_LEVEL_2:
            buzzerOn(0.5);
            break;
        default:
            break;
    }
}
