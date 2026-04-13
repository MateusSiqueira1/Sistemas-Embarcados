// atividade 2 mateus siqueira correção
const int pinoBotao1 = 2;
const int pinoBotao2 = 3;

const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;

int estadoBotao1;
int estadoBotao2;
int ultimoEstadoLeitura1 = HIGH;
int ultimoEstadoLeitura2 = HIGH;

unsigned long ultimoTempoDebounce1 = 0;
unsigned long ultimoTempoDebounce2 = 0;
unsigned long tempoDebounce = 50;

unsigned long ultimoMillisPisca = 0; // Apenas um timer para o pisca
unsigned long intervalo = 300;

bool sequenciaAtiva = false;
bool fasePisca = false; // Controla qual par de LEDs acende

void setup() {
  pinMode(pinoBotao1, INPUT_PULLUP);
  pinMode(pinoBotao2, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  estadoBotao1 = HIGH;
  estadoBotao2 = HIGH;
}

void loop() {
  int leitura1 = digitalRead(pinoBotao1);
  int leitura2 = digitalRead(pinoBotao2);

  // --- DEBOUNCE BOTÃO 1 ---
  if (leitura1 != ultimoEstadoLeitura1) {
    ultimoTempoDebounce1 = millis();
  }
  if ((millis() - ultimoTempoDebounce1) > tempoDebounce) {
    if (leitura1 != estadoBotao1) {
      estadoBotao1 = leitura1;
      if (estadoBotao1 == LOW) {
        sequenciaAtiva = true;
        ultimoMillisPisca = millis(); // Inicia o tempo do pisca
      }
    }
  }

  // --- DEBOUNCE BOTÃO 2 ---
  if (leitura2 != ultimoEstadoLeitura2) {
    ultimoTempoDebounce2 = millis();
  }
  if ((millis() - ultimoTempoDebounce2) > tempoDebounce) {
    if (leitura2 != estadoBotao2) {
      estadoBotao2 = leitura2;
      if (estadoBotao2 == LOW) {
        sequenciaAtiva = false;
        // Apaga tudo ao desligar
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
      }
    }
  }

  // --- LÓGICA DO PISCA-PISCA (MÁQUINA DE ESTADOS) ---
  if (sequenciaAtiva) {
    if (millis() - ultimoMillisPisca >= intervalo) {
      ultimoMillisPisca = millis(); // Reseta o timer do pisca
      fasePisca = !fasePisca;       // Inverte a fase (Toggle)

      if (fasePisca) {
        digitalWrite(LED1, LOW); digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH); digitalWrite(LED4, HIGH);
      } else {
        digitalWrite(LED1, HIGH); digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW); digitalWrite(LED4, LOW);
      }
    }
  }

  ultimoEstadoLeitura1 = leitura1;
  ultimoEstadoLeitura2 = leitura2;
}

      