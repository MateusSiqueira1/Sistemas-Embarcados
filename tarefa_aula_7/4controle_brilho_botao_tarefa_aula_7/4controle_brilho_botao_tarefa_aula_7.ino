// controle de brilho com botão
const int pinoBotao = 2;
const int pinoLED   = 9;

int estadoBotao;           
int ultimoEstadoLeitura = HIGH; 

unsigned long ultimoTempoDebounce = 0; 
unsigned long tempoDebounce = 50; 
unsigned int apertos = 0;

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP); 
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
  estadoBotao = HIGH;
}

void loop() {
  int leitura = digitalRead(pinoBotao);

  // Verifica se o sinal mudou (ruído ou clique)
  if (leitura != ultimoEstadoLeitura) {
    ultimoTempoDebounce = millis();
  }

  if ((millis() - ultimoTempoDebounce) > tempoDebounce) {
    // Se o estado estabilizou e é diferente do estado anterior
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      // SÓ incrementa e muda o LED se o estado for LOW (Botão Pressionado)
      if (estadoBotao == LOW) {
        apertos++;

        if (apertos > 4) {
          apertos = 0;
        }

        // Calcula o brilho (0, 1, 2, 3, 4 cliques)
        int valorled = map(apertos, 0, 4, 0, 255);
        analogWrite(pinoLED, valorled);
        
        Serial.print("Apertos: ");
        Serial.println(apertos);
      }
    }
  }

  // SALVAR a leitura para a próxima comparação - ESSENCIAL
  ultimoEstadoLeitura = leitura;
}