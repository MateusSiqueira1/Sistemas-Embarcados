//7frequencia do led com potenciometro tarefa aula 7
int led1 = 9;
int pin_sensor = A0;
int valor_sensor = 0;



unsigned long tempoAnterior = 0;
int intervaloPisca = 0; 
bool estadoLed = LOW;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  intervaloPisca = map(valor_sensor, 0, 1023, 2000, 100);
 
  unsigned long tempoAtual = millis();
    
    // Lógica para piscar sem usar delay()
    if (tempoAtual - tempoAnterior >= intervaloPisca) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed; // Inverte o estado (HIGH <-> LOW)
      digitalWrite(led1, estadoLed);
    }
}