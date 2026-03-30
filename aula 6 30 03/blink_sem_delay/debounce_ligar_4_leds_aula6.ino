// debounce para ligar 4 leds
int ledazul = 8;
int ledverde = 9;
int ledama = 10;
int ledverm = 11;
unsigned long tempo_anterior = 0;

int intervalo = 1000;

bool estado = 0;

void setup() {
  pinMode(ledazul, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledama, OUTPUT);
  pinMode(ledverm, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long tempo_atual = millis();
  if (tempo_atual - tempo_anterior >= intervalo) {
    estado = !estado;
    digitalWrite(ledazul, estado);
    digitalWrite(ledverde, estado);
    digitalWrite(ledama, estado);
    digitalWrite(ledverm, estado);
    tempo_anterior = tempo_atual;
    Serial.println("1 segundo");
  }
}
