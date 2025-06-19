/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define BUTTON_PIN 2
//#define LED_STATUS 0
int LED_STATUS = 0;
int LED_STATUS_2 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A15, INPUT_PULLUP);
  //int LED_STATUS = 0;
}

// the loop function runs over and over again forever
void loop() {

  if (digitalRead(A15) == LOW) {
    switch (LED_STATUS_2) {
      case 0:
        digitalWrite(6,HIGH);
        LED_STATUS_2 = 1;
        break;
      
      case 1:
        digitalWrite(6, LOW);
        LED_STATUS_2 = 0;
        break;
      
      default:
        LED_STATUS_2 =0;
    }
  }
  if (digitalRead(BUTTON_PIN) == LOW) {
    //delay(50);
    
    switch (LED_STATUS) {
      case 0:
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(7,HIGH);
        LED_STATUS = 1;
        break;
      case 1:
        digitalWrite(LED_BUILTIN, LOW);
        LED_STATUS = 0;
        digitalWrite(7, LOW);
        break;
      default:
        LED_STATUS = 0;
    }
      //if (digitalRead(LED_BUILTIN) == HIGH) {
      ///  digitalWrite(LED_BUILTIN, LOW);
     // }
      
      ////if (digitalRead(LED_BUILTIN) == LOW) {
     ///   digitalWrite(LED_BUILTIN, HIGH);
     // }  

  }
  //digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  //delay(1000);                      // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  //delay(1000);                      // wait for a second
}
