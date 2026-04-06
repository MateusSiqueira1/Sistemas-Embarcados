/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: fade com potenciometro

Autor: Mateus Siqueira
Data: 22/05/2023
Versão: 1.0

************************************************************************ */
int led1 = 9;
int pin_sensor = A0;
int valor_sensor = 0;
int valorled = 0;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  valorled = map(valor_sensor, 0, 1023, 0, 255);
  analogWrite(led1, valorled);
  Serial.println(valorled);
  delay(10);

}