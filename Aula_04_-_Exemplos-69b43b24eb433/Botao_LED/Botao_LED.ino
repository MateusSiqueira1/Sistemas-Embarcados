/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Acionamento de LED por botão com Pull-Up interno 

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

const int led = 7;				//
const int pin_botao = 10;			//

void setup() {
  pinMode(led, OUTPUT);				//
  pinMode(pin_botao, INPUT_PULLUP);		//
}

void loop() {
  int valor = digitalRead(pin_botao);		//
  if (valor == HIGH) {				//
    digitalWrite(led, HIGH); 			// Acende o led
  }
  else {					//
    digitalWrite(led, LOW); 			// Apaga o led
  }
}
