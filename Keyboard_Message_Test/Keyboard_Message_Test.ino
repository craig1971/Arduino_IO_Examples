/* 
 Keyboard Message Test
 
 For the Arduino Leonardo and Micro.
 
 Sends a text string when a button is pressed.

 The circuit:
 * pushbutton attached from pin 4 to +5V
 * 10-kilohm resistor attached from pin 4 to ground
 
 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */

const int buttonPin1 = 4;          // input pin for pushbutton
int previousButton1State = HIGH;   // for checking the state of a pushButton
const int buttonPin2 = 7;          // input pin for pushbutton
int previousButton2State = HIGH;   // for checking the state of a pushButton

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}


void loop() {
  // read the pushbutton:
  int button1State = digitalRead(buttonPin1);
  int button2State = digitalRead(buttonPin2);
  
  // if the button 1 state has changed,
  if ((button1State != previousButton1State) && (button1State == HIGH)) {    
    Keyboard.press('1');delay(100);Keyboard.release('1');delay(100);
    Keyboard.press('e');delay(100);Keyboard.release('e');delay(100);
    Keyboard.press('e');delay(100);Keyboard.release('e');delay(100);
    Keyboard.press(' ');delay(100);Keyboard.release(' ');delay(100);
    Keyboard.press('s');delay(100);Keyboard.release('s');delay(100);
    Keyboard.press(' ');delay(100);Keyboard.release(' ');delay(100);
    Keyboard.press('q');delay(100);Keyboard.release('q');delay(100);
    Keyboard.press('q');delay(100);Keyboard.release('q');delay(100);
    Keyboard.press('1');delay(100);Keyboard.release('1');
  }
  // save the current button state for comparison next time:
  previousButton1State = button1State;
  
  // if the button 2 state has changed,
  if ((button2State != previousButton2State) && (button2State == HIGH)) {    
    Keyboard.press(KEY_RETURN);
  }
  // save the current button state for comparison next time:
  previousButton2State = button2State;
  
  delay(100);
  
  Keyboard.releaseAll();
}
