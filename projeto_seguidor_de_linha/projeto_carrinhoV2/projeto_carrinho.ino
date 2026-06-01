const int ex_direita = 2;
const int direita = 3;
const int meio = 4;
const int esquerda = 5;
const int ex_esquerda = 6;
const int velocidade_direita = 9;
const int velocidade_esquerda = 10;
const int in1_d = 7;
const int in2_d = 8;
const int in3_e = 11;
const int in4_e = 12;


void setup() {
  Serial.begin(115200);
  pinMode(ex_direita, INPUT);
  pinMode(direita, INPUT);
  pinMode(meio, INPUT);
  pinMode(esquerda, INPUT);
  pinMode(ex_esquerda, INPUT);
  pinMode(velocidade_direita, OUTPUT);
  pinMode(velocidade_esquerda, OUTPUT);
  pinMode(in1_d, OUTPUT);
  pinMode(in2_d, OUTPUT);
  pinMode(in3_e, OUTPUT);
  pinMode(in4_e, OUTPUT);
}

void loop() {
  if(digitalRead(ex_direita) == 0){
    analogWrite(velocidade_esquerda, 255);
    digitalWrite(in4_e, 1);
    digitalWrite(in2_d, 0);
  }
  else if(digitalRead(direita) == 0){
    analogWrite(velocidade_esquerda, 127);
    digitalWrite(in4_e, 1);
    digitalWrite(in2_d, 0);
  }
  else if(digitalRead(meio) == 0){
    analogWrite(velocidade_esquerda, 255);
    analogWrite(velocidade_direita, 255);
    digitalWrite(in4_e, 1);
    digitalWrite(in2_d, 1);
  }
  else if(digitalRead(esquerda) == 0){
    analogWrite(velocidade_direita, 127);
    digitalWrite(in4_e, 0);
    digitalWrite(in2_d, 1);
  }
  else if(digitalRead(ex_esquerda) == 0){
    analogWrite(velocidade_direita, 255);
    digitalWrite(in4_e, 0);
    digitalWrite(in2_d, 1);
  }
}
