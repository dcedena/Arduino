/*
  Created by David Cedena Loaisa (2014)
  SIMON SAYS v2.0
  - [v1.0] 4 Capacitive Sensors
  - [v1.0] 4 Leds in each sensor: Green, Red, Yellow, Blue
  - [v2.0] 4 Notes (distinct) for each sensor
  - [v2.0] In each turn, adding a new sound/color/sensor,
           keeping the previous sounds/colors/sensors.
*/

#include <CapacitiveSensor.h>
#include <BasicEducationShield.h>
#include "pitches.h"

#define NO_SENSOR     -1
#define SENSOR_GREEN   0
#define SENSOR_RED     1
#define SENSOR_YELLOW  2
#define SENSOR_BLUE    3

#define NOTE_GREEN 
#define NOTE_RED 
#define NOTE_YELLOW 
#define NOTE_BLUE

CapacitiveSensor csGreen = CapacitiveSensor(2,7);
CapacitiveSensor csRed = CapacitiveSensor(2,6);
CapacitiveSensor csYellow = CapacitiveSensor(2,5);
CapacitiveSensor csBlue = CapacitiveSensor(2,4);
int pinsLed[] = { 11, 10, 9, 8 }; // GREEN, RED, YELLOW, BLUE
const int numberOfLeds = 4;

const long valueLimitPushedSensor = 150;

VUMeter vuMeter;

const int initialTurn = 2; // Number of initial turns
const int maxTurns = 10; // Max of turns
int turns = initialTurn; // Current turn
int game[maxTurns]; // Storage the random turns
int blinkTime = 500;
int noteTime = 1000;

CedenaMelody piezo = CedenaMelody(13);

// MAIN SETUP
void setup() {
   Serial.begin(9600);
   csGreen.set_CS_AutocaL_Millis(0xFFFFFFFF);
   csRed.set_CS_AutocaL_Millis(0xFFFFFFFF);
   csYellow.set_CS_AutocaL_Millis(0xFFFFFFFF);
   csBlue.set_CS_AutocaL_Millis(0xFFFFFFFF);

   vuMeter.config(numberOfLeds, pinsLed);
   vuMeter.begin();
   randomSeed(millis());

   setupInitialGame();
}

void setupInitialGame() {
  for(int i=0;i<initialTurn;i++) {
    game[i] = random(numberOfLeds);
  }
}

// MAIN ITERATOR
void loop() {
 
    NewGame();
    SimonSays();
    delay(500);
    GetInputs();

}

// Create a new game, blinkAll several times.
void NewGame() {
  vuMeter.blinkAll(200, 5);
  vuMeter.clear();
  delay(500);
  // Print for Serial Port the game
  for(int i=0;i<turns;i++) {
    PrintLed(i, game[i]);
  }
}

void PrintLed(int turn, int value) {
    Serial.print(turn);
    Serial.print("\t=>\t");
   
    String msg = "";
    switch(value) {
      case SENSOR_GREEN:
        msg = "[0] GREEN";
        break;
      case SENSOR_RED:
        msg = "[1] RED";
        break;
      case SENSOR_YELLOW:
        msg = "[2] YELLOW";
        break;  
      case SENSOR_BLUE:
        msg = "[3] BLUE";
        break;
    }
    Serial.println(msg);
}

// Display the led's sequence.
void SimonSays() {
  for(int i=0;i<turns;i++) {
    vuMeter.on(game[i]);
    piezo.effect_simon_says( game[i] );
    delay(blinkTime);
    vuMeter.off(game[i]);
    delay(blinkTime);
  }
}

void GetInputs() {
  for(int i=0;i<turns;i++) {
    
    int whatSensorPushed = NO_SENSOR;
    while(whatSensorPushed == NO_SENSOR) {
      whatSensorPushed = GetSensorPushed();
    } 
    
    if(whatSensorPushed == game[i]) {
        // Blink LED of Sensor pushed.
        vuMeter.blink(whatSensorPushed, 200, 1);
        // Play the note of Sensor pushed.
        piezo.effect_simon_says( whatSensorPushed );
      // piezo.effect_score();
    }
    else {
      GameOver();
      return;
    }
  }
  
  delay(500);
  AddLevelTurnAndWin();
}

// Check that 'sensor' is pushed.
// #defines => SENSOR_GREEN, SENSOR_RED.
int GetSensorPushed() {
  int result = NO_SENSOR;
  long valueGreen = csGreen.capacitiveSensor(30);
  long valueRed = csRed.capacitiveSensor(30);
  long valueYellow = csYellow.capacitiveSensor(30);
  long valueBlue = csBlue.capacitiveSensor(30);

  if(valueGreen > valueLimitPushedSensor) {
    result = SENSOR_GREEN;
    Serial.println("GREEN\tPUSHED");
  }
  else if(valueRed > valueLimitPushedSensor) {
    result = SENSOR_RED;
    Serial.println("RED\tPUSHED");
  }
  else if(valueYellow > valueLimitPushedSensor) {
    result = SENSOR_YELLOW;
    Serial.println("YELLOW\tPUSHED");
  }
  else if(valueBlue > valueLimitPushedSensor) {
    result = SENSOR_BLUE;
    Serial.println("BLUE\tPUSHED");
  }

  return result; 
}

void AddLevelTurnAndWin() {
  if(turns < maxTurns) {
    AddNext();
  }
  piezo.effect_win();
}

void AddNext() {
  turns++;
  game[turns] = random(numberOfLeds);
}

void GameOver() {
  turns = initialTurn;
  piezo.effect_gameover();
}
