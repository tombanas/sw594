/*
SW 594 project
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
