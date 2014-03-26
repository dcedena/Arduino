
int buttonState = LOW;
int pinLedRedLeft = 5;
int pinLedRedRight = 4;
int pinLedGreen = 3;
int pinButton = 2;

void setup() {
  pinMode(pinLedRedLeft, OUTPUT);
  pinMode(pinLedRedRight, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop() {
  buttonState = digitalRead(pinButton);
   
  if(buttonState == LOW) {
    // Button Not Pressed
    digitalWrite(pinLedRedLeft, LOW);
    digitalWrite(pinLedRedRight, LOW);
    digitalWrite(pinLedGreen, HIGH);
  }
  else {
    // Button Pressed
    digitalWrite(pinLedRedLeft, HIGH);
    digitalWrite(pinLedRedRight, LOW);
    digitalWrite(pinLedGreen, LOW);
    
    delay(250);
    digitalWrite(pinLedRedLeft, LOW);
    digitalWrite(pinLedRedRight, HIGH);
    delay(250);
  }
}
