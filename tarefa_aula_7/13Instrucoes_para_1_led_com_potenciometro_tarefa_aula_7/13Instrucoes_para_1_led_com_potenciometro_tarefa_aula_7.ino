//instruções para 1 led com potenciometro
int led1 = 9;
int pin_sensor = A0;
int valor_sensor = 0;


const long intervaloPisca = 500;
unsigned long tempoAnterior = 0;
int tensao = 0;
bool estadoled = LOW;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  tensao = map(valor_sensor, 0, 1023, 0, 6);

  unsigned long tempoAtual = millis();

  if (tensao <= 2) {
    estadoled = LOW;
    digitalWrite(led1, estadoled);
  }
  else if (2 < tensao && tensao < 4) {
     
    if (tempoAtual - tempoAnterior >= intervaloPisca) {
      tempoAnterior = tempoAtual;
      estadoled = !estadoled;  // Inverte o estado (HIGH <-> LOW)
      digitalWrite(led1, estadoled);
    }
  }
  else if (tensao >= 4) {
    estadoled = HIGH;
    digitalWrite(led1, estadoled);
  }
}
