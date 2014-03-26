
#include <CapacitiveSensor.h>
#include <BasicEducationShield.h>
#include "pitches.h"

int pinLeds[] = { 9, 10, 11 };
int pinCount = 3;
VUMeter LEDs;
CapacitiveSwitch pad[3];

int reactTime = 500;

Melody piezo = Melody(8);

void setup() {
  LEDs.config(pinCount, ledPins);
  LEDs.begin();
   
  //Configure the pads
  pad[0] = CapacitiveSwitch(2,3);
  pad[1] = CapacitiveSwitch(2,4);
  pad[2] = CapacitiveSwitch(2,5);
  pad[0].config(100);
  pad[1].config(100);
  pad[2].config(100);
}

void loop() {


}
