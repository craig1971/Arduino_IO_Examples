// VCC -- 5V.
// GND -- GND.
//Z-c  -- D2.
//PWM  -- D3.
//outB -- A0.



#define pwm_Pin 7
#define blink_Pin 13
#define sync_Pin 3
//#define timer 5
static bool state =HIGH;
static bool flag =false;
int count = 0;

void setup() 
{
  //pinMode(A0,INPUT);
  pinMode(pwm_Pin,OUTPUT);
  digitalWrite(pwm_Pin,LOW);
  pinMode(blink_Pin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(sync_Pin),control,RISING);
  
}

void loop() 
{
 if(flag)
 { 
  //delayMicroseconds(i*50);
  //delayMicroseconds(analogRead(A0)*5)
  delayMicroseconds(2000);
  digitalWrite(pwm_Pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(pwm_Pin,LOW);
  flag=false;
 }
}

void control()
{
 // digitalWrite(pwm_Pin,LOW);
  flag=true;

  
  count++;
  if (count > 1000) count = 1;

}

/*
 TCCR1A=0x00;
  TCCR1B=0x13;//div 64,CTC mode;
  TIMSK1 |= (1 << OCIE1A);
  OCR1A=2000-1;// 5ms;
  TCNT1=0; //counter init 0;
  
  //TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));// clears all clock selects bits;

*/



