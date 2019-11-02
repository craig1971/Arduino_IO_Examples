int led = 13;
const int sensorPin = A0;    // pin that the sensor is attached to
int blinkDelay = 1000;
unsigned long delayStart = 0; // the time the delay started

int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() {
  pinMode(led, OUTPUT);   // initialize the digital pin as an output.
  digitalWrite(led, HIGH); // turn led on
  delayStart = millis();   // start delay
}

void loop() {
  
  // check if delay has timed out after 10sec == 10000mS
  if ( (millis() - delayStart) >= blinkDelay) {
    delayStart = millis();    
    digitalWrite(led, (digitalRead(led) ? LOW : HIGH) ); // invert LED state

  }
  
  //  Other loop code here . . .
  
  // read the potentiometer
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 200, 1000);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 200, 1000);

  blinkDelay = sensorValue;
}
