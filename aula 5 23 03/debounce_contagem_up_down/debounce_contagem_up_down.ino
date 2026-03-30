// debounce contage up e down aula 5
// Definições de pinos
const int pinoUp   = 2; // Botão para aumentar
const int pinoDown = 3; // Botão para diminuir

// Variáveis de controle do Contador
int contador = 0;

// Variáveis de estado para o Botão UP
int estadoEstavelUp = HIGH;
int ultimoBrutoUp   = HIGH;
unsigned long tempoDebounceUp = 0;

// Variáveis de estado para o Botão DOWN
int estadoEstavelDown = HIGH;
int ultimoBrutoDown   = HIGH;
unsigned long tempoDebounceDown = 0;

const unsigned long intervaloDebounce = 50; // 50ms para estabilizar

void setup() {
  pinMode(pinoUp, INPUT_PULLUP);
  pinMode(pinoDown, INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("Sistema Iniciado. Use os botoes para contar!");
  Serial.print("Contagem atual: ");
  Serial.println(contador);
}

void loop() {
  unsigned long tempoAtual = millis();

  // --- LÓGICA DEBOUNCE: BOTÃO UP ---
  int leituraUp = digitalRead(pinoUp);
  if (leituraUp != ultimoBrutoUp) {
    tempoDebounceUp = tempoAtual;
  }
  if ((tempoAtual - tempoDebounceUp) > intervaloDebounce) {
    if (leituraUp != estadoEstavelUp) {
      estadoEstavelUp = leituraUp;
      // Se estabilizou em LOW, o botão foi pressionado
      if (estadoEstavelUp == LOW) {
        contador++;
        exibirContador();
      }
    }
  }
  ultimoBrutoUp = leituraUp;

  // --- LÓGICA DEBOUNCE: BOTÃO DOWN ---
  int leituraDown = digitalRead(pinoDown);
  if (leituraDown != ultimoBrutoDown) {
    tempoDebounceDown = tempoAtual;
  }
  if ((tempoAtual - tempoDebounceDown) > intervaloDebounce) {
    if (leituraDown != estadoEstavelDown) {
      estadoEstavelDown = leituraDown;
      // Se estabilizou em LOW, o botão foi pressionado
      if (estadoEstavelDown == LOW) {
        contador--;
        exibirContador();
      }
    }
  }
  ultimoBrutoDown = leituraDown;
}

// Função auxiliar para evitar repetição de código do Serial
void exibirContador() {
  Serial.print("Contagem: ");
  Serial.println(contador);
}