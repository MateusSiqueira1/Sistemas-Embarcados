Sequência simples de LEDs
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;

unsigned long ultimo = 0;

unsigned long intervalo = 200;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  if (millis() - ultimo >= intervalo){
    ultimo = millis();
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
}
  if (millis() - ultimo >= intervalo){
    ultimo = millis();
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
}
  
  if (millis() - ultimo >= intervalo){
    ultimo = millis();
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
}
  
  if (millis() - ultimo >= intervalo){
    ultimo = millis();
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 1);
}
}