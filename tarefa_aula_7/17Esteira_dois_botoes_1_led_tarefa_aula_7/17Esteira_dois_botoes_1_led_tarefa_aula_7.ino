const int pinoBotaoa = 2;
const int pinoBotaob = 3;
const int pinoLED = 13;

// Variáveis de controle de estado
int estadoLED = LOW;

int estadoBotaob = HIGH;
int ultimoEstadobotaob = HIGH;
unsigned long tempoDebounceUp = 0;

int estadoBotaoa = HIGH;
int ultimoEstadobotaoa = HIGH;
unsigned long ultimoTempoDebouncea = 0;
const long tempoDebounce = 50;

unsigned long ultimoTempoespera = 0;
const long tempodesligado = 3000;

bool ligado = false;
bool esperab = false;
int contador = 0;
int contadorb = 0;

void setup() {
  // Ativa o resistor interno de Pull-up (dispensa resistor externo no botão)
  pinMode(pinoBotaoa, INPUT_PULLUP);
  pinMode(pinoBotaob, INPUT_PULLUP);

  pinMode(pinoLED, OUTPUT);
  digitalWrite(pinoLED, estadoLED);
  Serial.begin(9600);
  // Inicializa o estado estável como HIGH (solto)
  estadoBotaoa = HIGH;
  estadoBotaob = HIGH;
}

void loop() {
  // 1. Lê o estado bruto do botão
  int leituraa = digitalRead(pinoBotaoa);
  int leituraUp = digitalRead(pinoBotaob);

  // 2. Verifica se o sinal mudou (ruído ou início de clique)
  if (leituraa != ultimoEstadobotaoa) {
    ultimoTempoDebouncea = millis();  // Reinicia o cronômetro
  }

  // 3. Verifica se o sinal permaneceu o mesmo por tempo suficiente
  if ((millis() - ultimoTempoDebouncea) > tempoDebounce) {

    // Se o sinal estabilizou em um valor diferente do "estadoBotao" anterior
    if (leituraa != estadoBotaoa) {
      estadoBotaoa = leituraa;

      // 4. LÓGICA INVERTIDA: Se o estado estável agora for LOW, significa PRESSIONADO
      if (estadoBotaoa == LOW) {
        estadoLED = HIGH;  // Inverte o LED
        ligado = true;
        contador = 0;
      }
    }
  }

  if (leituraUp != ultimoEstadobotaob) {
    tempoDebounceUp = millis();
  }
  if ((millis() - tempoDebounceUp) > tempoDebounce) {
    if (leituraUp != estadoBotaob) {
      estadoBotaob = leituraUp;
      // Se estabilizou em LOW, o botão foi pressionado
      if (estadoBotaob == LOW) {
        contador++;
        contadorb++;
        exibirContador();
      }
    }
  }
  if (contadorb >= 5 && ligado) {
    estadoLED = LOW;
    esperab = true;
    ligado = false;
    ultimoTempoespera = millis();
    contadorb = 0;
  }
  if (millis() - ultimoTempoespera >= tempodesligado && esperab) {
    esperab = false;
    ligado = true;
    estadoLED = HIGH;
  }
  if (contador >= 20) {
    estadoLED = LOW;
    ligado = false;
    esperab = false;
  }

  // Atualiza o hardware e a memória para o próximo loop
  digitalWrite(pinoLED, estadoLED);
  ultimoEstadobotaoa = leituraa;
  ultimoEstadobotaob = leituraUp;
}
void exibirContador() {
  Serial.println(contador);
  Serial.println(contadorb);
}
