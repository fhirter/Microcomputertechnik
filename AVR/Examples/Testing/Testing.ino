// Adapted from:
// https://github.com/mmurdoch/arduinounit/blob/master/examples/basic/basic.ino

#include <AUnit.h>
#include "getNextState.h"

// ST_OPEN -> ST_CLOSING -> ST_CLOSED -> ST_OPENING -> ST_OPEN -> etc
test(trainArriving) {
    bool gateOpen = 0;
    bool gateClose = 0;
    bool trainArriving = 1;
    bool trainPassed = 0;

    bool inputs[4] = { gateOpen, gateClose, trainArriving, trainPassed };

    enum State_t currentState = ST_OPEN;
    enum State_t nextState = ST_OPEN;

    nextState = getNextState(currentState, inputs);

    assertEqual(nextState, ST_CLOSING);
}

test(gateClosed) {
    bool gateOpen = 0;
    bool gateClose = 1;
    bool trainArriving = 0;
    bool trainPassed = 0;

    bool inputs[4] = { gateOpen, gateClose, trainArriving, trainPassed };

    enum State_t currentState = ST_CLOSING;
    enum State_t nextState;

    nextState = getNextState(currentState, inputs);

    assertEqual(nextState, ST_CLOSED);
}

test(trainPassed) {
    bool gateOpen = 0;
    bool gateClose = 0;
    bool trainArriving = 0;
    bool trainPassed = 1;

    bool inputs[4] = { gateOpen, gateClose, trainArriving, trainPassed };

    enum State_t currentState = ST_CLOSED;
    enum State_t nextState;

    nextState = getNextState(currentState, inputs);

    assertEqual(nextState, ST_OPENING);
}

test(gateOpened) {
    bool gateOpen = 1;
    bool gateClose = 0;
    bool trainArriving = 0;
    bool trainPassed = 0;

    bool inputs[4] = { gateOpen, gateClose, trainArriving, trainPassed };

    enum State_t currentState = ST_OPENING;
    enum State_t nextState;

    nextState = getNextState(currentState, inputs);

    assertEqual(nextState, ST_OPEN);
}

void setup() {
    delay(1000); // wait for stability on some boards to prevent garbage Serial
    Serial.begin(115200); // ESP8266 default of 74880 not supported on Linux
    while (!Serial); // for the Arduino Leonardo/Micro only

    Serial.println(F("----------------------------------------------------------------------------"));

}

void loop() {
    aunit::TestRunner::run();
}

