
int pinPiezo = 8;
int pinKeys = A0;

int notes[] = { 262, 294, 330, 349 };

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(pinKeys);
  Serial.println(keyVal);

  if(keyVal == 1023) {
    tone(pinPiezo, notes[0]);
  }
  else if(keyVal >= 990 && keyVal <= 1010) {
    tone(pinPiezo, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515) {
    tone(pinPiezo, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10) {
    tone(pinPiezo, notes[3]);
  }
  else
    noTone(pinPiezo);
}
