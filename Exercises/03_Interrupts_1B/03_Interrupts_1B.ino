
volatile bool enable_blinking = 1;
volatile bool update_timer = 1;
const uint8_t BUTTON_PIN = PD2;
const uint8_t BUTTON_PIN2 = PD3;

void setup() {
  Serial.begin(9600);
  // initialize digital pin PORT B 5 as an output.
  DDRB |= (1 << DDB5);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  
  //  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggle_blinking, FALLING);
  init_button_interrupt_int1();

  sei(); // enable global interrupts
  
  enable_blinking = 1;
}

void loop() { 
  int sensorValue = analogRead(A0);
  
  float voltage = sensorValue*(5.0 / 1023.0);
  float frequency = 1.9*voltage+0.8;
    
  float delay_time_s = (1/frequency);
 
  if(voltage < 0.1) {
    digitalWrite(LED_BUILTIN, LOW);
  } else if(voltage > 4.9) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else { 
	if(update_timer == 1) {
	  Serial.println(delay_time_s);
	  init_timer_interrupt(delay_time_s);
	  update_timer = 0;
	}
  }     
}

void toggle_blinking() {
  enable_blinking = !enable_blinking;
}

// button interrupt routine
ISR(INT1_vect) {
 toggle_blinking();
}

// timer interrupt routine
ISR(TIMER1_COMPA_vect){
  if(enable_blinking == 1) {
  //digitalWrite(13, !digitalRead(13));
    PORTB ^= (1 << PORTB5);
  } else {
     PORTB &= ~(1 << PORTB5);
  }
  update_timer = 1;
}

void init_button_interrupt_int1() {
  // set button as input, enable pullup
  DDRD &= ~(1<<PD3);
  PORTD |= (1<<PD3);

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
