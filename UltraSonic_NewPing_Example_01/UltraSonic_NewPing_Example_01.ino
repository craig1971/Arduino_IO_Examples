/*
 * Posted on https://randomnerdtutorials.com
 * created by http://playground.arduino.cc/Code/NewPing
 * NewPing Docs: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
 * 
    Sensor Features
        Power Supply :+5V DC
        Quiescent Current : <2mA
        Working Current: 15mA
        Effectual Angle: <15°
        Ranging Distance : 2cm – 400 cm/1″ – 13ft
        Resolution : 0.3 cm
        Measuring Angle: 30 degree
        Trigger Input Pulse width: 10uS
        Dimension: 45mm x 20mm x 15mm

    https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
*/

#include <NewPing.h>
#include <QueueArray.h>

// Sonar Entities & Methods


#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 305 // cm  120 inches
#define TRIGGER_DISTANCE  60 //in
#define DELAY_DISTANCE     6 //in

#define SONAR_NONE        0
#define SONAR_LEAVING     1
#define SONAR_APPROACHING 2
#define SONAR_ALERT       3

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

// create a Queue of distances.
QueueArray <int> queue;

int lastAlertDistance = 999;

void dumpQueue() {
   while( !queue.isEmpty ()) {queue.pop();} 
}

void storeDistance(int dist) {
   if (queue.isFull()) { queue.pop(); }
   queue.push(dist);
}

int sonarCheck() {
   int result = SONAR_NONE;
   
   unsigned int distance = sonar.ping_in();
   unsigned int previous = 999;

   if (queue.count() > 0) {previous = queue.peek();}
   
   if (distance == 0 ) {
       dumpQueue(); Serial.println("no action");
       
   } else if (previous < distance) { 
       dumpQueue(); 
       storeDistance(distance); 
       //  Serial.print("leaving");Serial.print(previous);Serial.print(" ");Serial.println(distance);
       lastAlertDistance = distance;
       result = SONAR_LEAVING;
       
   } else if (previous == distance) { 
       storeDistance(distance); 
       
   } else if (previous > distance) { 
       storeDistance(distance);  
       //Serial.print("approaching ");Serial.print(previous);Serial.print(" ");Serial.println(distance);
       result = SONAR_APPROACHING;
   }
   
   if (queue.isFull() ){ 
    
       if (queue.peek() <= TRIGGER_DISTANCE) {
        
           if ((lastAlertDistance - distance) > DELAY_DISTANCE ) {
              lastAlertDistance = distance;
              // Serial.print("ALERT"); Serial.print(distance); Serial.println(" in");
              result = SONAR_ALERT;              
           }
       }
   }   
   return result; 
}

 
#define LED_PIN 8
#define LED_PIN2 7

void setup() {
   Serial.begin(9600);
   
   // initialize digital pin LED_PIN as an output.
   pinMode(LED_PIN, OUTPUT);
   pinMode(LED_PIN2, OUTPUT);
  
   Serial.println("starting");
   
   digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(1000);                       // wait for a second
   digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
   delay(1000);                       // wait for a second
   digitalWrite(LED_PIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(1000);                       // wait for a second
   digitalWrite(LED_PIN2, LOW);    // turn the LED off by making the voltage LOW
   delay(1000);                       // wait for a second
   digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(1000);                       // wait for a second
   digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
   delay(1000);                       // wait for a second
}
 

void loop() {
   delay(200);
   int targetStatus = sonarCheck();
int distance = 0;
int previous = 0;

   switch (targetStatus) {
      case SONAR_NONE:   
         break;
      case SONAR_LEAVING:   
         Serial.print("leaving");Serial.print(previous);Serial.print(" ");Serial.println(distance);
         
         digitalWrite(LED_PIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
         delay(500);                         // wait for a 1/2 second
         digitalWrite(LED_PIN2, LOW);    // turn the LED off by making the voltage LOW
         break;
      case SONAR_APPROACHING:   
         Serial.print("approaching ");Serial.print(previous);Serial.print(" ");Serial.println(distance);
         digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
         delay(500);                         // wait for a 1/2 second
         digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
         break;
      case SONAR_ALERT:  
         Serial.print("ALERT"); Serial.print(distance); Serial.println(" in");
         digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(LED_PIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
         delay(500);                         // wait for a 1/2 second
         digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
         digitalWrite(LED_PIN2, LOW);    // turn the LED off by making the voltage LOW
         break;
   }
  
}





