
const int sensonPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600); // Open a serial port
  
  for(int pin=2;pin<=4;pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {

  int sensorValue = analogRead(sensonPin);

  Serial.print("Serial value: ");
  Serial.print(sensorPin);
  
  // Convert tha ADC reading to voltage
  float voltage = (sensorValue / 1024.0) * 5.0;
  
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  // Convert the voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);
  
  if(temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
  
}
