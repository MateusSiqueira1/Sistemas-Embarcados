/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Botão com Pull-down e envio serial

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

const int pin_botao = 10;			//
boolean botao = false;				//

void setup() {
  pinMode(pin_botao, INPUT);			//
  Serial.begin(115200); 			// Definição da velocide de transmissão em 115200 bps
}

void loop() {
  botao = digitalRead(pin_botao);		//
  if (botao == true) {				//
    Serial.println("Botao pressionado!!!");	//
  }
}
