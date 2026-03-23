/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Leitura de dados pela serial

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

int valor = 0;					// 

void setup() {
  Serial.begin(115200); 			// Definição da velocide de transmissão em 115200 bps
}

void loop() {
  Serial.println("Digite um numero ");		// 
  valor = Serial.read(); 			// leitura de dados do monitor serial
  Serial.print("O numero digitado foi ");	// 
  Serial.write(valor);				// 
  Serial.println();				// 
  delay(2000); 					// Aguarda por 2 segundos
}
