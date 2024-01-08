//
// Created by fabian on 24.08.21.
//

#ifndef ARDUINOHAL_GETNEXTSTATE_H
#define ARDUINOHAL_GETNEXTSTATE_H
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

enum State_t {
    ST_OPEN,
    ST_OPENING,
    ST_CLOSED,
    ST_CLOSING
};

enum State_t getNextState(enum State_t, bool *);

#ifdef __cplusplus
}
#endif

#endif //ARDUINOHAL_GETNEXTSTATE_H
