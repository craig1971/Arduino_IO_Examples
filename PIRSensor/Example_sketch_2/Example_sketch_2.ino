/*****************************************************************************/
//  Function: If the sensor detects movement in its detecting range,
//        the LED is turned on. Otherwise, the LED is turned off.
//  Hardware: Grove - PIR Motion Sensor, Grove - LED
//  Arduino IDE: Arduino-1.6.3
//  Author:  Frankie.Chu    
//  Date:    Jan 21,2013
//  Version: v1.0
//  by www.seeedstudio.com
//      Modified by: RadioShack Corporation
//      Date: July 18, 2013
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
/*******************************************************************************/

const unsigned int BAUD_RATE = 19200;

void setup()
{
  Serial.begin(BAUD_RATE);
    pinMode(7, INPUT);  // Sensor pin, input
  pinMode(13,OUTPUT); // LED pin, output. This line will probably change, depending on what kind of output you want.
   Serial.println("Ready");
}

void loop() {
  int sensorValue = digitalRead(7);       // Read the sensor.

  if(sensorValue == HIGH) {                //Only, if the sensor detects motion...
    digitalWrite(13,HIGH);          // Turn on the LED. Depending on your project, you will replace this section with whatever you want motion to trigger.
    Serial.print("Movement");                   // Print the word "Movement" in the Serial Monitor (Tools > Serial Monitor)
    Serial.println(" ");                        // Space and a line break in the Serial Monitor.  
delay(1000);                                    // Delay 1 second (1000 milliseconds)
}
  else {                                   //If the sensor does not detect movement...
  digitalWrite(13,LOW);                  // Turn off the LED. Replace this section with whatever you want to happen when no motion is detected.
}
}

