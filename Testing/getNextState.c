#include "getNextState.h"

// inputs: {gate open, gate close, train arriving, train passed}
enum State_t getNextState(enum State_t state, bool *inputs) {
    bool gateOpen = *(inputs+0);
    bool gateClose = *(inputs+1);
    bool trainArriving = *(inputs+2);
    bool trainPassed = *(inputs+3);

    enum State_t nextState = state;

    switch(state) {
        case ST_OPEN:
            if(trainArriving) {
                nextState = ST_CLOSING;
            }
            break;

        case ST_OPENING:
            if(gateOpen) {
                nextState = ST_OPEN;
            }
            break;

        case ST_CLOSED:
            if(trainPassed) {
                nextState = ST_OPENING;
            }
            break;

        case ST_CLOSING:
            if(gateClose) {
                nextState = ST_CLOSED;
            }
            break;
    }
    return nextState;
}