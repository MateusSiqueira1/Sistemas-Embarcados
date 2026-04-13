// 9média potenciometro para ligar um led
const int led = 13;
const int analogPin = A0;

unsigned long ultimo = 0;
unsigned long ultimoled = 0;
unsigned long intervaloled = 3000;
unsigned long intervalo = 300;

// Variáveis mantidas como solicitado
int valor1 = 0, valor2 = 0, valor3 = 0, valor4 = 0, valor5 = 0;
int valor6 = 0, valor7 = 0, valor8 = 0, valor9 = 0, valor10 = 0;

int passo = 1; // Variável para controlar qual leitura faremos
bool ledLigado = false; // Para saber se o LED está em contagem para apagar

void setup() {
  pinMode(led, OUTPUT);
  pinMode(analogPin, INPUT);
}

void loop() {
  unsigned long agora = millis();

  // Estrutura de leitura sequencial (um por um a cada 300ms)
  if (agora - ultimo >= intervalo) {
    ultimo = agora;

    if (passo == 1) { valor1 = analogRead(analogPin); passo = 2; }
    else if (passo == 2) { valor2 = analogRead(analogPin); passo = 3; }
    else if (passo == 3) { valor3 = analogRead(analogPin); passo = 4; }
    else if (passo == 4) { valor4 = analogRead(analogPin); passo = 5; }
    else if (passo == 5) { valor5 = analogRead(analogPin); passo = 6; }
    else if (passo == 6) { valor6 = analogRead(analogPin); passo = 7; }
    else if (passo == 7) { valor7 = analogRead(analogPin); passo = 8; }
    else if (passo == 8) { valor8 = analogRead(analogPin); passo = 9; }
    else if (passo == 9) { valor9 = analogRead(analogPin); passo = 10; }
    else if (passo == 10) { 
      valor10 = analogRead(analogPin); 
      passo = 1; // Reinicia o ciclo de médias
      
      // Cálculo da média após as 10 leituras
      if ((valor1 + valor2 + valor3 + valor4 + valor5 + valor6 + valor7 + valor8 + valor9 + valor10) / 10 > 700) {
        digitalWrite(led, HIGH);
        ultimoled = agora; // Salva o momento que ligou
        ledLigado = true;
      }
    }
  }

  // Lógica para desligar o LED após 3 segundos
  if (ledLigado && (agora - ultimoled >= intervaloled)) {
    digitalWrite(led, LOW);
    ledLigado = false;
  }
}