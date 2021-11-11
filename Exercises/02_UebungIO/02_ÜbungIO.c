// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
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
    
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(d/2);                      
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(d/2);    
  }                  
}