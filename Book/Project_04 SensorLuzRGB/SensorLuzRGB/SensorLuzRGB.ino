
const int pinRGB_Red = 11;
const int pinRGB_Blue = 10;
const int pinRGB_Green = 9;

const int sensorRed = A0;
const int sensorGreen = A1;
const int sensorBlue = A2;

void setup() {
	Serial.begin(9600);
	pinMode(pinRGB_Red, OUTPUT);
	pinMode(pinRGB_Green, OUTPUT);
	pinMode(pinRGB_Blue, OUTPUT);
}

void loop() {
	int redSensorValue = analogRead(sensorRed);
	delay(5);
	int greenSensorValue = analogRead(sensorGreen);
	delay(5);
	int blueSensorValue = analogRead(sensorBlue);

	Serial.print("Raw Sensor Values \t Red: ");
	Serial.print(redSensorValue);
	Serial.print("\t Green: ");
	Serial.print(greenSensorValue);
	Serial.print("\t Blue: ");
	Serial.println(blueSensorValue);

	// Get Values RGB
	int redValue = redSensorValue / 4;
	int greenValue = greenSensorValue / 4;
	int blueValue = blueSensorValue / 4;

	Serial.print("Mapped Sensor Values \t Red: ");
	Serial.print(redValue);
	Serial.print("\t Green: ");
	Serial.print(greenValue);
	Serial.print("\t Blue: ");
	Serial.println(blueValue);

	analogWrite(pinRGB_Red, redValue);
	analogWrite(pinRGB_Green, greenValue);
	analogWrite(pinRGB_Blue, blueValue);

delay(1000);
}
