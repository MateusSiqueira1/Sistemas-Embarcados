//11 botao para ligar 2 leds pelo tempo pressionado
const int pinoBotao = 2;
const int pinoLED1 = 13;
const int pinoLED2 = 12;

int estadoBotao;                
int ultimoEstadoLeitura = HIGH;  

unsigned long ultimoTempoDebounce = 0;
unsigned long tempoDebounce = 50;

unsigned long tempoApertou = 0;
unsigned long tempoSoltou = 0;
unsigned long duracaoClique = 0;

const long tempoCurto = 1000; // Até 1 segundo
const long tempoLongo = 2000; // Mais de 2 segundos

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoLED1, OUTPUT);
  pinMode(pinoLED2, OUTPUT);
  estadoBotao = HIGH;
}

void loop() {
  int leitura = digitalRead(pinoBotao);

  // 1. Debounce
  if (leitura != ultimoEstadoLeitura) {
    ultimoTempoDebounce = millis();
  }

  if ((millis() - ultimoTempoDebounce) > tempoDebounce) {
    
    // Se o estado do botão realmente mudou
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      if (estadoBotao == LOW) {
        // MOMENTO EM QUE APERTOU
        tempoApertou = millis();
      } 
      else {
        // MOMENTO EM QUE SOLTOU
        tempoSoltou = millis();
        duracaoClique = tempoSoltou - tempoApertou;

        // 2. Lógica de decisão baseada na duração
        if (duracaoClique < tempoCurto) {
          // Clique rápido: liga LED 1, desliga LED 2
          digitalWrite(pinoLED1, HIGH);
          digitalWrite(pinoLED2, LOW);
        } 
        else if (duracaoClique >= tempoLongo) {
          // Clique longo: liga LED 2, desliga LED 1
          digitalWrite(pinoLED1, LOW);
          digitalWrite(pinoLED2, HIGH);
        }
      }
    }
  }

  ultimoEstadoLeitura = leitura;
}