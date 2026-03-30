// debounce led aula 5
const int pinoBotao = 2;
const int pinoLED   = 13;

// Variáveis de controle de estado
int estadoLED = LOW;         
int estadoBotao;             // Estado estável atual (será HIGH por padrão no Pull-up)
int ultimoEstadoLeitura = HIGH; // No Pull-up, o estado de repouso é HIGH

// Variáveis para o tempo (millis)
unsigned long ultimoTempoDebounce = 0; 
unsigned long tempoDebounce = 50; 

void setup() {
  // Ativa o resistor interno de Pull-up (dispensa resistor externo no botão)
  pinMode(pinoBotao, INPUT_PULLUP); 
  
  pinMode(pinoLED, OUTPUT);
  digitalWrite(pinoLED, estadoLED);
  
  // Inicializa o estado estável como HIGH (solto)
  estadoBotao = HIGH;
}

void loop() {
  // 1. Lê o estado bruto do botão
  int leitura = digitalRead(pinoBotao);

  // 2. Verifica se o sinal mudou (ruído ou início de clique)
  if (leitura != ultimoEstadoLeitura) {
    ultimoTempoDebounce = millis(); // Reinicia o cronômetro
  }

  // 3. Verifica se o sinal permaneceu o mesmo por tempo suficiente
  if ((millis() - ultimoTempoDebounce) > tempoDebounce) {
    
    // Se o sinal estabilizou em um valor diferente do "estadoBotao" anterior
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      // 4. LÓGICA INVERTIDA: Se o estado estável agora for LOW, significa PRESSIONADO
      if (estadoBotao == LOW) {
        estadoLED = !estadoLED; // Inverte o LED
      }
    }
  }

  // Atualiza o hardware e a memória para o próximo loop
  digitalWrite(pinoLED, estadoLED);
  ultimoEstadoLeitura = leitura;
}