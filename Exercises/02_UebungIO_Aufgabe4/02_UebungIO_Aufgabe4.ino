void setup() {
  // initialize digital pin PORT B 5 as an output.
  DDRB |= (1 << DDB5);
  
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  
  float voltage = sensorValue*(5.0 / 1023.0);

  if(voltage < 0.1) {
    digitalWrite(LED_BUILTIN, LOW);
  } else if(voltage > 4.9) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else { 
    float frequency = 1.9*voltage+0.8;
    
    float d = (1/frequency)*1000;
    Serial.println(d);
    
    PORTB |= (1 << PORTB5);
    delay(d/2);                      
    
    PORTB &= ~(1 << PORTB5);
    delay(d/2);    
  }                  
}
