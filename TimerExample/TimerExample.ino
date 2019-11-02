int led = 13;
unsigned long delayStart = 0; // the time the delay started

void setup() {
  pinMode(led, OUTPUT);   // initialize the digital pin as an output.
  digitalWrite(led, HIGH); // turn led on
  delayStart = millis();   // start delay
}

void loop() {
  
  // check if delay has timed out after 10sec == 10000mS
  if ( (millis() - delayStart) >= 10000) {
    delayStart = millis();    
    digitalWrite(led, (digitalRead(led) ? LOW : HIGH) ); // invert LED state

  }
  
  //  Other loop code here . . .
  
}
