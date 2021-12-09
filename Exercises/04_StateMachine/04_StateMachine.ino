#include <NRF52_MBED_TimerInterrupt.h>
#include <NRF52_MBED_ISR_Timer.h>

enum state_t {
    ST_OPEN,
    ST_CLOSING,
    ST_CLOSED,
    ST_OPENING
};

struct inputs_t {
    bool trainArriving;
    bool trainPassed;
    bool gateOpen;
    bool gateClosed;
};

struct outputs_t {
  bool gate;
  bool lights;
};

const uint16_t TIMER_INTERVAL_MS = 2000;

state_t getNextState(state_t state, inputs_t inputs);
void setOutputs(state_t currentState, outputs_t outputs);
void timerISR();

enum state = ST_OPEN;
st_inputs = inputs;
st

void setup() {
  NRF52_MBED_Timer ITimer(NRF_TIMER_3);
  ITimer.attachInterruptInterval(TIMER_INTERVAL_MS, timerISR);
}
void loop() {
  enum state = getNextState(state, inputs);
  setOuptu

}

enum state_t getNextState(state_t currentState, inputs_t inputs) {
  state_t nextState = ST_OPEN;
  switch(currentState) {
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

void setOutputs(state_t currentState, outputs_t outputs) {
  switch(currentState) {
    case ST_OPEN:
      outputs.lights = 0;
      break;
    case ST_CLOSING:
      outputs.lights = 1;
      outputs.gate = 1;
      break;
    case ST_CLOSED:
      outputs.lights = 1;
      break;
    case ST_OPENING:
      outputs.lights = 1;
      outputs.gate = 0;
      break;
    default:
      break;
  }
}

void timerISR() {

}
