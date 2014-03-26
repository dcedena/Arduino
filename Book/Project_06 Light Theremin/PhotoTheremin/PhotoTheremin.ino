
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int piezoPin = 8;
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(piezoPin, OUTPUT);
  digitalWrite(piezoPin, HIGH);
  
  while(millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    Serial.print("SETUP: SensorValue = ");
    Serial.println(sensorValue);
 
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(piezoPin, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("LOOP : SensorValue = ");
  Serial.println(sensorValue);
    
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  tone(8, pitch, 10);
  delay(10);
}

