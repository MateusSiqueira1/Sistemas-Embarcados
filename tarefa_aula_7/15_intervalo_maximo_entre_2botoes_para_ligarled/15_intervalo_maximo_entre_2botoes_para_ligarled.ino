// 15 intervalo maximo entre 2 botoes para ligar 1 led
const int pinoBotao1 = 2;
const int pinoBotao2 = 3;
const int LED1 = 8;
const int LED2 = 9;

int estadoBotao1, estadoBotao2;
int ultimoEstadoLeitura1 = HIGH;
int ultimoEstadoLeitura2 = HIGH;

unsigned long ultimoTempoDebounce1 = 0;
unsigned long ultimoTempoDebounce2 = 0;
unsigned long tempoDebounce = 50;

unsigned long intervaloa = 0;
unsigned long intervalob = 0;
unsigned long intervaloMaximo = 500; // Tempo máximo entre cliques para validar

bool modoTravado = false; 

void setup() {
  pinMode(pinoBotao1, INPUT_PULLUP);
  pinMode(pinoBotao2, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  // Estado inicial dos LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
}

void loop() {
  int leitura1 = digitalRead(pinoBotao1);
  int leitura2 = digitalRead(pinoBotao2);

  // --- LOGICA BOTÃO 1 ---
  if (leitura1 != ultimoEstadoLeitura1) ultimoTempoDebounce1 = millis();
  if ((millis() - ultimoTempoDebounce1) > tempoDebounce) {
    if (leitura1 != estadoBotao1) {
      estadoBotao1 = leitura1;
      if (estadoBotao1 == LOW) {
        intervaloa = millis(); 
      }
    }
  }

  // --- LOGICA BOTÃO 2 ---
  if (leitura2 != ultimoEstadoLeitura2) ultimoTempoDebounce2 = millis();
  if ((millis() - ultimoTempoDebounce2) > tempoDebounce) {
    if (leitura2 != estadoBotao2) {
      estadoBotao2 = leitura2;
      if (estadoBotao2 == LOW) {
        intervalob = millis();
      }
    }
  }

  // --- LÓGICA DE TRAVAMENTO ---
  // Calculamos a diferença absoluta entre os últimos cliques registrados
  unsigned long diferenca = (intervaloa > intervalob) ? (intervaloa - intervalob) : (intervalob - intervaloa);

  // Se a diferença entre o clique do botão A e do botão B for pequena, TRAVA
  if (diferenca < intervaloMaximo && intervaloa > 0 && intervalob > 0) {
    modoTravado = true;
  }

  // Aplica o estado nos LEDs
  if (modoTravado) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }

  ultimoEstadoLeitura1 = leitura1;
  ultimoEstadoLeitura2 = leitura2;
}
