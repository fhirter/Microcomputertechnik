const byte interruptPin = 2;
volatile bool enableBlinking = 1;
volatile bool state = 1;

unsigned long referenceTime = 0;

unsigned long prevTime = 0;

// the setup function runs once when you press reset or power the board
void setup() {
// initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    Serial.begin(9600);

    referenceTime = micros();
}

void loop() {
    float d = 1000000;

    unsigned long currentTime = micros();
    unsigned long deltaTime = currentTime - referenceTime;

    delay(100);     // deltaTime depends on this delay

    if(deltaTime > d) {
        if (enableBlinking == 1) {
            digitalWrite(LED_BUILTIN, state);
            Serial.println(deltaTime, DEC);
            state = !state;
            referenceTime = currentTime;        // reset time
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}

void blink() {
    enableBlinking = !enableBlinking;
}