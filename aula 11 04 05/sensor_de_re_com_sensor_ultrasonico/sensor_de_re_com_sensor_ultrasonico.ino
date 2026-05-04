//sensor de ré com sensor ultrasonico
#include <Ultrasonic.h>
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;
int pinoBotao = 2;

Ultrasonic ultrasonic(12, 13);
int distance;
int estadoBotao;
int ultimoEstadoLeitura = HIGH;
unsigned long ultimoTempoDebounce = 0;
unsigned long tempoDebounce = 50;
bool apertado = false;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();

  Serial.print("Distance in CM: ");
  Serial.println(distance);

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
        apertado = true;
      }


      if (estadoBotao == HIGH) {
        apertado = false;
      }
    }
  }
  if (apertado) {
    if (distance > 0 && distance < 10) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
    } else if (distance >= 10 && distance < 20) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
    } else if (distance >= 20 && distance < 30) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    } else if (distance >= 30 && distance < 40) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    } else if (distance >= 40) {
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
  } else{
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }

  ultimoEstadoLeitura = leitura;
}