
const int valorMaximo = 32; // 2 ^ countLeds
int countLeds = 5;
int leds[] = { 9, 10, 11, 12, 13 };
int valueLeds[] = { 0, 0, 0, 0, 0 };
int valor = 0;

int valueDelay = 500;

void setup() {
  for(int i=0;i<countLeds;i++) {
    pinMode( leds[i], OUTPUT );
    valueLeds[i] = 0;
  }
}

void loop() {
  
  CalcularValoresArrayLEDS();
  
  for(int i=0;i<countLeds;i++) {
    digitalWrite( leds[i], valueLeds[i] );   
  }

  // Incrementar valor
  valor++;
  if(valor == valorMaximo) {
    valor = 0;
  }
  delay(valueDelay);
}

void CalcularValoresArrayLEDS() {
  int _temp = valor;
  for(int i=0;i<countLeds;i++) { 
    valueLeds[i] = _temp % 2;
    _temp = _temp / 2;
  }
}
