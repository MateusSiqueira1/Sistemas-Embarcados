/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Seleção multipla

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

const int led_vermelho = 5;			//
const int led_verde = 6;			//
const int led_amarelo = 7;			//
char led;					//

void setup() {
  pinMode(led_vermelho, OUTPUT);		//
  pinMode(led_verde, OUTPUT);			//
  pinMode(led_amarelo, OUTPUT);			//
  Serial.begin(115200); 			// Definição da velocide de transmissão em 115200 bps
}

void loop() {
  if (Serial.available()) {			//
    led = Serial.read();			//
    switch (led) {				//
      case 'R': digitalWrite(led_vermelho, HIGH);	// Acende led
        break;						//
      case 'r': digitalWrite(led_vermelho, LOW);	// Apaga led
        break;
      case 'G': digitalWrite(led_verde, HIGH);		// Acende led
        break;
      case 'g': digitalWrite(led_verde, LOW);		// Apaga led
        break;
      case 'Y': digitalWrite(led_amarelo, HIGH);	// Acende led
        break;
      case 'y': digitalWrite(led_amarelo, LOW);		// Apaga led
        break;
      default: Serial.println("Nenhum led selecionado!!!"); //
       break;
    }
  }
}
