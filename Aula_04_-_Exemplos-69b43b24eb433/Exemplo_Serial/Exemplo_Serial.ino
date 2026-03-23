/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exemplo de comunicação serial

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

void setup() {
  Serial.begin(9600); 			// Definição da velocide de transmissão em 9600 bps
}

void loop() {
  Serial.print("Ola, seu nome, seja bem vindo ao maravilhoso mundo do Arduino");	// Imprime na serial
}
