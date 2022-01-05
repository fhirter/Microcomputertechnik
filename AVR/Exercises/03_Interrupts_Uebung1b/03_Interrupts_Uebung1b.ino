const byte interruptPin = 2;
volatile byte state = 0;

// the setup function runs once when you press reset or power the board
void setup() {
// initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    Serial.begin(9600);
}

void loop() {
    float d = 1000;

    Serial.println(state);

    if (state == 1) {
        digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
        delay(d / 2);
    }
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    delay(d / 2);
}

void blink() {
    state = !state;
}