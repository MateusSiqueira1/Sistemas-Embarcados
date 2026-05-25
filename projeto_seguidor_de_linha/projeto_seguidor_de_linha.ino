const int ex_direita = 2;
const int direita = 3;
const int meio = 4;
const int esquerda = 5;
const int ex_esquerda = 6;
const int motor_direita = 9;
const int motor_esquerda = 10;

void setup() {
  Serial.begin(115200);
  pinMode(ex_direita, INPUT);
  pinMode(direita, INPUT);
  pinMode(meio, INPUT);
  pinMode(esquerda, INPUT);
  pinMode(ex_esquerda, INPUT);
}

void loop() {
  if(digitalRead(ex_direita) == 0){
    analogWrite(motor_esquerda, 255)
  }
  else if(digitalRead(direita) == 0){
    analogWrite(motor_esquerda, 127)
  }
  else if(digitalRead(meio) == 0){
    analogWrite(motor_esquerda, 255)
    analogWrite(motor_direita, 255)
  }
  else if(digitalRead(esquerda) == 0){
    analogWrite(motor_direita, 127)
  }
  else if(digitalRead(ex_esquerda) == 0){
    analogWrite(motor_direita, 255)
  }
}
