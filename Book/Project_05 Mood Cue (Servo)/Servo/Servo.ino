
#include <Servo.h>

Servo myServo;
const int pinServo = 9;
const int pinPot = A0;
int potValue;
int angle;

void setup() {
   myServo.attach(pinServo);
   Serial.begin(9600);
 //  pinMode(pinServo, INPUT);
}

void loop() {
   potValue = analogRead(pinPot);
   Serial.print("potValue: ");
   Serial.print(potValue);
   
   angle = map(potValue, 0, 1023, 0, 179);
   Serial.print(", angle: ");
   Serial.println(angle);
   
   myServo.write(angle);
   delay(15);
}

