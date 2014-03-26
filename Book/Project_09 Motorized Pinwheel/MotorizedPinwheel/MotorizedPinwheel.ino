
const int buttonPin = 2;
const int motorPin = 9;
int stateButton = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  stateButton = digitalRead(buttonPin);
  Serial.print("State Value: ");
  Serial.println(stateButton);

  if(stateButton == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
  }
}
