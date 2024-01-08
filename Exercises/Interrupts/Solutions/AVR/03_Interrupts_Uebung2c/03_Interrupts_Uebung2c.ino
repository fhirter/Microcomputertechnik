volatile bool enable_blinking = 1;
volatile bool blinkFlag = 1;
volatile bool state = 0;

const uint8_t BUTTON_PIN = PD3;

void setup() {
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    init_button_interrupt_int1();
    init_timer_interrupt(delay_time_s);

    sei(); // enable global interrupts

    enable_blinking = 1;
}

void loop() {
    if(blinkFlag == 1) {
        if (enableBlinking == 1) {
            digitalWrite(LED_BUILTIN, state);
            state = !state;
            blinkFlag = 0;
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}

// button interrupt routine
ISR(INT1_vect) {
    enable_blinking = !enable_blinking;
}

// timer interrupt routine
ISR(TIMER1_COMPA_vect){
    blinkFlag = 1;
}

void init_button_interrupt_int1() {
    // set button as input, enable pullup
    DDRD &= ~(1<<BUTTON_PIN);
    PORTD |= (1<<BUTTON_PIN);

    EICRA |= (1<<ISC11);  // falling edge
    EICRA &= ~(1<<ISC10);

    EIMSK |= (1<< INT1); // enable interrupt for INT1
}

void init_timer_interrupt(float time_s) {
    uint16_t prescaler = 256;

    uint16_t counter_value = time_s*16e6/prescaler;

    //set timer1 interrupt at 1Hz
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0

    // set compare match register
    OCR1A = counter_value;

    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS12 bit for 256 prescaler clock source
    TCCR1B |= (1 << CS12);

    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
}
