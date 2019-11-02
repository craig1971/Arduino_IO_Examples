
/* ===============================================================
      Project: 4 Channel 5V Relay Module
       Author: Scott C
      Created: 7th Sept 2014
  Arduino IDE: 1.0.5
      Website: http://arduinobasics.blogspot.com.au
  Description: Explore the difference between NC and NO terminals.
================================================================== */

 /* 
  Connect 5V on Arduino to VCC on Relay Module
  Connect GND on Arduino to GND on Relay Module 
  
  Connect GND on Arduino to the Common Terminal (middle terminal) on Relay Module. */
 
 #define CH1 2   // Connect Digital Pin 8 on Arduino to CH1 on Relay Module
 #define CH2 3   // Connect Digital Pin 7 on Arduino to CH3 on Relay Module
 #define CH3 4   // Connect Digital Pin 7 on Arduino to CH3 on Relay Module
 #define CH4 5   // Connect Digital Pin 7 on Arduino to CH3 on Relay Module
 
 
 
 void setup(){
  
   // Setup all the relay Pins
   pinMode(CH1, OUTPUT);
   pinMode(CH2, OUTPUT);
   pinMode(CH3, OUTPUT);
   pinMode(CH4, OUTPUT);
   
   
   // Turn OFF any power to the Relay channels
   openRelay(CH1);
   openRelay(CH2);
   openRelay(CH3);
   openRelay(CH4);
   
   delay(1000); //Wait 1 second before starting sequence
 }
 
 void loop(){
  
   closeRelay(CH1); 
   delay(1000);
   
   openRelay(CH1);  
   closeRelay(CH2); 
   delay(1000);
   
   openRelay(CH2);   
   closeRelay(CH3); 
   delay(1000);
   
   openRelay(CH3); 
   closeRelay(CH4); 
   delay(1000);
   
   openRelay(CH4); 
   delay(1000);
   
   closeRelay(CH1); 
   closeRelay(CH2); 
   closeRelay(CH3);  
   closeRelay(CH4); 
   delay(1000);
   
   openRelay(CH1);  
   openRelay(CH2); 
   openRelay(CH3); 
   openRelay(CH4); 
   delay(1000);   
   
 }

/* 
 *  Sets the Normally Open (NO) terminal to OPEN
 *  Normally Closed will become Closed
 */
 void openRelay(int channel) {
  digitalWrite(channel, HIGH);
 }

/* 
 *  Sets the Normally Open (NO) terminal to Closed.
 *  Normally Closed will become OPEN
 */
 void closeRelay(int channel) {
  digitalWrite(channel, LOW);
 }



 
