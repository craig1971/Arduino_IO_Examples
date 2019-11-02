#include <IRremote.h>

int LED_PIN    = 7;
int RECV_PIN   = 5;

int lastTime = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}


void loop() {
  
  if ((int)irrecv.decode(&results)) {
    
    switch(results.value)
    {
      case 0xFFFFFFFF:
      Serial.println(".");
      break;
      
      case 0x92DF9279:
      Serial.println("#1 button " + results.decode_type );
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      break;
      
      case 0x87CDD0EF:
      Serial.println("#2 button");
      break;
      
      case 0x37788763:
      Serial.println("#3 button");
      break; 
    
      default:
      Serial.print("Unknown Button Code : ");
      Serial.println(results.value, HEX);
      break;
    }

    irrecv.resume(); // Receive the next value    
  }
  

  
}
