
/*
  Created by David Cedena Loaisa (2014)
  POV (Persistence Of Vision) v1.0
  Reference: http://madrid.verkstad.cc/es/course-literature/pov-es/
*/

#include <BasicEducationShield.h>

int pinsLed[] = { 6, 5, 4, 3, 2 };
const int numLeds = 5;
int rowCount = 0;
const int rowLen = 22;
VUMeter vuMeter;
int time = 10;

boolean texto[numLeds][rowLen]={
  // H H H H   O O O O   L L L L   A A A A
  {0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0}
};

void setup() {
  vuMeter.config(numLeds, pinsLed);  
  vuMeter.begin();
  Serial.begin(9600);
}

void loop() {
  if(rowCount == rowLen) {
    rowCount = 0;
  }
  else {
    for(int i=0;i<numLeds;i++) {
      if(texto[i][rowCount] == 1) {
        digitalWrite(pinsLed[i], HIGH);
        Serial.print(texto[i][rowCount]);
      }
      else {
        digitalWrite(pinsLed[i], LOW);
        Serial.print(texto[i][rowCount]);
      }
    }
    Serial.println("");
    rowCount++;
  }
  delay(time);
}

