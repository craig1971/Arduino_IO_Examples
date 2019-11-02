//ZERO----2 
//DIMMER----11 


int i; 
int ZDpin=0; 

void setup(){ 
  Serial.begin(9600); 
  pinMode(A0,INPUT);   // Z-D Pin  
  //pinMode(0,INPUT);   // Z-D Pin 
  pinMode(10,OUTPUT);  // Used as Interupt semaphore 
  pinMode(11,OUTPUT);  // PWM
  pinMode(13,OUTPUT);  // Onboard LED

  
  for (int a=0; a<5;a++) {
    delay(1000);
    digitalWrite(13,1);
    delay(750);
    digitalWrite(13,0);
  }
  
} 

void light() { 
  delay(3); 
  digitalWrite(10,1); 
} 

void loop() { 
  i=digitalRead(10); 
  digitalWrite(13,0); 
  digitalWrite(10,0); 
  attachInterrupt(ZDpin,light,RISING); 
  
  delay(20); 
  
  if (i==1) { 
   delay(3); 
   digitalWrite(13,1); 
   pwm(); 
  } 
} 

void pwm() { 
  for (int a=0; a<=255;a++) { 
    analogWrite(11,a); 
    delay(8); 
  } 
  
  for (int a=255; a>=0;a--) { 
    analogWrite(11,a); 
    delay(8); 
  } 
  
  delay(800); 
} 


