/* 
 *  Misst die Zeit für eine grosse Anzahl an Multiplikationen sowie Additionen,
 *  um zu zeigen, dass erstere länger Dauert. 
*/

void setup() {
    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  unsigned long start_time, stop_time;

  volatile uint32_t result;
  volatile uint32_t op1 = 3;
  volatile uint32_t op2 = 3;

  volatile float result_f;
  volatile float op1_f = 3;
  volatile float op2_f = 3;
  
  start_time = micros();
  for(unsigned long i=0;i<100000;i++) {
    result = op1+op2;
  }  
  stop_time = micros();
  
  Serial.print("Integer Addition: ");
  Serial.println(stop_time - start_time);           


  start_time = micros();
  for(unsigned long i=0;i<100000;i++) {
    result_f = op1_f+op2_f;
  }
  stop_time = micros();
  
  Serial.print("Floating Point Addition: ");
  Serial.println(stop_time - start_time);

  delay(1000);
}
