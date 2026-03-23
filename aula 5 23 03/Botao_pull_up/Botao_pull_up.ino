/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Botão com Pull-up e envio serial

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */
const int led_vermelho = 5;  //
const int led_verde = 7;     //
const int led_amarelo = 6;
const int pin_botaoa = 2;  //
const int pin_botaob = 3;
bool botaoa = false;  //
bool botaob = false;
void setup() {
  pinMode(pin_botaoa, INPUT_PULLUP);  //
  pinMode(pin_botaob, INPUT_PULLUP);
  pinMode(led_vermelho, OUTPUT);  //
  pinMode(led_verde, OUTPUT);     //
  pinMode(led_amarelo, OUTPUT);
  Serial.begin(115200);  // Definição da velocide de transmissão em 115200 bps
}

void loop() {
  botaoa = digitalRead(pin_botaoa);  //
  botaob = digitalRead(pin_botaob);
  if (botaoa == 0 && botaob == 0 ) {  // AND PRESSIONADOS
    digitalWrite(led_vermelho, HIGH);    //
  } else {
    digitalWrite(led_vermelho, LOW);
  }
  if (botaoa == 0 || botaob == 0 ) {  // OR PRESSIONADOS
    digitalWrite(led_verde, HIGH);    //
  } else {
    digitalWrite(led_verde, LOW);
  }
  if (botaoa == 0 ^ botaob == 0 ) {  // XOR PRESSIONADOS
    digitalWrite(led_amarelo, HIGH);    //
  } else {
    digitalWrite(led_amarelo, LOW);
  }
}
