/*const int pinA = 6;
const int pinF = 7;
const int pinE = 8;

const int pinB = 13;
const int pinG = 12;
const int pinC = 11;
const int pinD = 10;*/

/* Display Number in Digit 7-Segments */

//                   A   B   C   D  E  F   G
const int pins[] = { 6, 13, 11, 10, 8, 7, 12 };

int NUM_SEGMENTS = 7;

//                abcdefg
#define NUMBER_0 "1111110"
#define NUMBER_1 "0110000"
#define NUMBER_2 "1101101"
#define NUMBER_3 "1111001"
#define NUMBER_4 "0110011"
#define NUMBER_5 "1011011"
#define NUMBER_6 "1011111"
#define NUMBER_7 "1110000"
#define NUMBER_8 "1111111"
#define NUMBER_9 "1111011"

int millDelay = 1000;

int SegOn = LOW;
int SegOff = HIGH;

void setup() {
  Serial.begin(9600);
  ConfigPins();
  ClearSegments();
}

// Configure each pin of segment connection.
void ConfigPins() {
  for(int i=0;i<NUM_SEGMENTS;i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for(int i=9;i>=0;i--) {
    Display(i);
    delay(millDelay);
  }
}

// Display the number.
void Display(int number) {
  switch(number) {
    case 0:
      SetStateSegments(NUMBER_0);
      break;
    case 1:
      SetStateSegments(NUMBER_1);
      break;
    case 2:
      SetStateSegments(NUMBER_2);
      break;
    case 3:
      SetStateSegments(NUMBER_3);
      break;
    case 4:
      SetStateSegments(NUMBER_4);
      break;
    case 5:
      SetStateSegments(NUMBER_5);
      break;
    case 6:
      SetStateSegments(NUMBER_6);
      break;
    case 7:
      SetStateSegments(NUMBER_7);
      break;
    case 8:
      SetStateSegments(NUMBER_8);
      break;
    case 9:
      SetStateSegments(NUMBER_9);
      break;
    default:
      SetStateSegments("1001111"); // ERROR
  }
}

void SetStateSegments(String stateSegments) {
  // Check stateSegments => 7 digits and 0's and 1's only
  for(int d=0;d<NUM_SEGMENTS;d++) {
    int state;
    if(stateSegments[d] == '0') {
      state = SegOff;
    }
    else {
      state = SegOn;
    }
    digitalWrite( pins[d], state );
  }
}

void ClearSegments() {
  for(int i=0;i<NUM_SEGMENTS;i++) {
    digitalWrite(pins[i], SegOff);
  }
}


