
const int tiltPin = 8;

unsigned long previousTime = 0;
unsigned long currentTime = 0;
int tiltState = 0;
int prevTiltState = 0;
int led = 2; // First Led
long interval = 5000;

void setup() {
  Serial.begin(9600);
  for(int i=2;i<8;i++) { // Pin 2 to 7 (incl.)
    pinMode(i, OUTPUT);
  }
  pinMode(tiltPin, INPUT);
}

void loop() {
  
  currentTime = millis();
  
  Serial.print("\tPreviousTime \t ");
  Serial.print(previousTime);
  Serial.print("\tCurrentTime \t ");
  Serial.println(currentTime);
  
  if(currentTime - previousTime > interval) {
    previousTime = currentTime;
    
    if(led == 8) {
      Reset();
      Serial.println("## RESET LEDS ###");
    }

    digitalWrite(led, HIGH);
    Serial.print("Led => ");
    Serial.print(led);
    Serial.println(" - HIGH");

    led++;    
  }
  tiltState = digitalRead(tiltPin);
  
  if(tiltState != prevTiltState) {
      Reset();
      Serial.println("## RESET TILT ###");
  }
  prevTiltState = tiltState;
}

void Reset() {
  led = 2;
  ClearLeds();
  previousTime = currentTime;
}

void ClearLeds() {
  for(int i=2;i<8;i++) { // Pin 2 to 7 (incl.)
      digitalWrite(i, LOW);
  }
}

