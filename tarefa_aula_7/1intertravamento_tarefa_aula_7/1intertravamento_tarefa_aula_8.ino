1intertravamento tarefa aula 8
const int pinoBotaoa = 2;
const int pinoBotaob = 3;
const int pinoLED = 13;

int estadoBotaoa = HIGH;
int ultimoEstadobotaoa = HIGH;
unsigned long ultimoTempoDebouncea = 0;

int estadoBotaob = HIGH;
int ultimoEstadobotaob = HIGH;
unsigned long ultimoTempoDebounceb = 0;

unsigned long tempoDebounce = 50;

void setup() {
  pinMode(pinoBotaoa, INPUT_PULLUP);
  pinMode(pinoBotaob, INPUT_PULLUP);
  pinMode(pinoLED, OUTPUT);
  digitalWrite(pinoLED, LOW);
}

void loop() {
  int leituraa = digitalRead(pinoBotaoa);
  int leiturab = digitalRead(pinoBotaob);

  // --- DEBOUNCE BOTÃO A ---
  if (leituraa != ultimoEstadobotaoa) {
    ultimoTempoDebouncea = millis();
  }
  if ((millis() - ultimoTempoDebouncea) > tempoDebounce) {
    estadoBotaoa = leituraa;
  }

  // --- DEBOUNCE BOTÃO B ---
  if (leiturab != ultimoEstadobotaob) {
    ultimoTempoDebounceb = millis();
  }
  if ((millis() - ultimoTempoDebounceb) > tempoDebounce) {
    estadoBotaob = leiturab;
  }

  // --- LÓGICA DE INTERTRAVAMENTO ---
  // O LED só liga se AMBOS estiverem estáveis em LOW
  if (estadoBotaob == LOW && estadoBotaoa == LOW) {
    digitalWrite(pinoLED, HIGH);
  } else {
    // Se B (permissão) for solto, apaga imediatamente (respeitando o debounce)
    digitalWrite(pinoLED, LOW);
  }

  // Salva os estados para a próxima iteração
  ultimoEstadobotaoa = leituraa;
  ultimoEstadobotaob = leiturab;
}