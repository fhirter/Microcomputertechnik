#include <NRF52_MBED_TimerInterrupt.h>
#include <NRF52_MBED_ISR_Timer.h>

enum State {
    ST_OPEN,
    ST_CLOSING,
    ST_CLOSED,
    ST_OPENING
};

struct Inputs {
    uint8_t trainArriving = 0;
    uint8_t trainPassed = 0;
    uint8_t gateOpen = 0;
    uint8_t gateClosed = 0;
};

struct Outputs {
    uint8_t gate = 0;
    uint8_t lights = 0;
};
volatile uint8_t interruptFlag = 0;

const uint16_t TIMER_INTERVAL_MS = 2000;

State getNextState(State state, struct Inputs inputs);
void setOutputs(State currentState, struct Inputs outputs);
void timerISR();
void initInterrupt();

struct Inputs inputs;

void setup() {
    Serial.begin(9600);

    enum State state = ST_OPEN;

    randomSeed(analogRead(0));

    struct Outputs outputs;

    NRF52_MBED_Timer ITimer(NRF_TIMER_3);
    if (ITimer.attachInterruptInterval(TIMER_INTERVAL_MS * 1000, timerISR)) {
        Serial.print(F("Starting ITimer3 OK"));
    } else {
        Serial.print(F("Starting ITimer3 Failed"));
    }
    Serial.println("fubar");

    while (1) {
        char output[51];
        if (interruptFlag == 1) {
            Serial.println("trainArriving - gateClosed - gateOpen - trainPassed");
            sprintf(output, "      %d            %d          %d           %d", inputs.trainArriving, inputs.gateClosed, inputs.gateOpen, inputs.trainPassed);
            Serial.println(output);

            state = getNextState(state, inputs);
            Serial.println(state);
            setOutputs(state, outputs);

            Serial.println("\n\n");

            interruptFlag = 0;
        }
    }
}

void loop() {
    // never gets called
}

enum State getNextState(State currentState, struct Inputs inputs) {
    State nextState = currentState;
    switch (currentState) {
        case ST_OPEN:
            if (inputs.trainArriving) {
                nextState = ST_CLOSING;
            }
            break;
        case ST_CLOSING:
            if (inputs.gateClosed) {
                nextState = ST_CLOSED;
            }
            break;
        case ST_CLOSED:
            if (inputs.trainPassed) {
                nextState = ST_OPENING;
            }
            break;
        case ST_OPENING:
            if (inputs.gateOpen) {
                nextState = ST_OPEN;
            }
            break;
        default:
            break;
    }
    return nextState;
}

void setOutputs(State currentState, struct Outputs outputs) {
    switch (currentState) {
        case ST_OPEN:
            outputs.lights = 0;
            Serial.println(F("Lights Off"));
            break;
        case ST_CLOSING:
            outputs.lights = 1;
            outputs.gate = 1;
            Serial.println(F("Lights On, Gate Closing"));
            break;
        case ST_CLOSED:
            outputs.lights = 1;
            Serial.println(F("Lights On"));
            break;
        case ST_OPENING:
            outputs.lights = 1;
            outputs.gate = 0;
            Serial.println(F("Lights On, Gate Opening"));
            break;
        default:
            break;
    }
}

// NRF52 MBED Timer ISR
void timerISR() {
    interruptFlag = 1;
    inputs = {
      round(random(2)),
      round(random(2)),
      round(random(2)),
      round(random(2))
    };
}
