#define pwm_Pin 7    // Output to Opto Triac pin
#define sync_Pin 3   // zero cross input 

volatile int dimming = 110;    // Dimming level (0-128)



void setup() 
{
  pinMode(pwm_Pin, OUTPUT);   // Set AC Load pin as output
  digitalWrite(pwm_Pin, LOW); // Start with the AC Load OFF
  
  attachInterrupt(digitalPinToInterrupt(sync_Pin), zero_crosss_int, RISING);
  
  flashOnboardLED(0, 3);
}

void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
{
  // Firing angle calculation : 1 full wave at 50Hz = 1/50 = 0.02000s = 20.00ms = 20,0000us (microseconds)  
  //                                        at 60Hz = 1/60 = 0.01666s = 16.66ms = 16,6666us
  // Every zerocrossing : occurs twice per cycle
  //                                  1/2 cycle time for 50Hz -> 10.00ms = 10,000us
  //                                  1/2 cycle time for 60Hz ->  8.33ms =  8,333us

  // Original Logic 
  int dimtime = (65*dimming);    // For 50Hz use 100; For 60Hz use 65    
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(pwm_Pin, HIGH);   // triac firing
  delayMicroseconds(8.33);       // triac On propogation delay (For 50Hz use 10; for 60Hz use 8.33)  
  digitalWrite(pwm_Pin, LOW);    // triac Off

  
}


void loop() { 
  sosPattern(); 
   //singleStepPattern(); 
   //flashOnboardLED(0, 3);
}

void sosPattern() {

    dimming =   0; digitalWrite(13,1); delay(300);
    dimming = 128; digitalWrite(13,0); delay(500);
    dimming =   0; digitalWrite(13,1); delay(300);
    dimming = 128; digitalWrite(13,0); delay(500);
    dimming =   0; digitalWrite(13,1); delay(300);
    dimming = 128; digitalWrite(13,0); delay(500);
    
    dimming =   0; digitalWrite(13,1); delay(1000);
    dimming = 128; digitalWrite(13,0); delay(500);
    dimming =   0; digitalWrite(13,1); delay(1000);
    dimming = 128; digitalWrite(13,0); delay(500);
    dimming =   0; digitalWrite(13,1); delay(1000);
    dimming = 128; digitalWrite(13,0); delay(500);
    
    dimming =   0; digitalWrite(13,1); delay(300);
    dimming = 128; digitalWrite(13,0); delay(500);
    dimming =   0; digitalWrite(13,1); delay(300);
    dimming = 128; digitalWrite(13,0); delay(500);
    dimming =   0; digitalWrite(13,1); delay(300);
    dimming = 128; digitalWrite(13,0); delay(500);
    
    delay(2500);
}

void bigStepPattern() {       

  // Bring the light's brightness up
  for (int i=128;i>=0;i=i-24)
  {
    dimming = i;
    delay(500);
  }              
  dimming = 0;
  
  // Bring the light's brightness down  
  for (int i=0;i<=128;i=i+24)
  {
    dimming = i;
    delay(500);
  }
  dimming = 128;
}


// Original Example Logic
void singleStepPattern() {
  
  // Bring the light's brightness up  
  for (int i=120;i>10;i--)
  {
    dimming=i;
    delay(10);
  }
  /*
  dimming = 0;
  delay(3000);
  dimming = 75;
  delay(3000);
  dimming = 0;
  delay(3000);
  */
  // Bring the light's brightness down
  /*
  for (int i=0;i<128;i++)
  {
    dimming=i;
    delay(10);
  }
  */
  //dimming = 128;
  
}

void flashOnboardLED(int longSequence, int shortSequence) {  

    for (int a=0; a<longSequence;a++) {
      delay(1000);
      digitalWrite(13,1);
      delay(750);
      digitalWrite(13,0);
    }
  

    for (int a=0; a<shortSequence;a++) {
      delay(500);
      digitalWrite(13,1);
      delay(250);
      digitalWrite(13,0);
    }
  
}

