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
  digitalWrite(in4_e, 1);
  digitalWrite(in1_d, 1);

  bool sen_ex_di = digitalRead(ex_direita);
  bool sen_di = digitalRead(direita);
  bool sen_me = digitalRead(meio);
  bool sen_es = digitalRead(esquerda);
  bool sen_ex_es = digitalRead(ex_esquerda);
  if (sen_di && !sen_es && !sen_me) {
    analogWrite(velocidade_esquerda, 255);
    analogWrite(velocidade_direita, 65);

  } else if (sen_es && !sen_di && !sen_me) {
    analogWrite(velocidade_direita, 255);
    analogWrite(velocidade_esquerda, 65);

  }else if (sen_ex_di && !sen_ex_es && !sen_di && !sen_me) {
    analogWrite(velocidade_esquerda, 255);
    analogWrite(velocidade_direita, 30);

  } else if (sen_me && !sen_di && !sen_es) {
    analogWrite(velocidade_esquerda, 230);
    analogWrite(velocidade_direita, 255);

  } else if (sen_ex_es && !sen_ex_di && !sen_es && !sen_me) {
    analogWrite(velocidade_direita, 255);
    analogWrite(velocidade_esquerda, 30);

  } else {
    analogWrite(velocidade_esquerda, 225);
    analogWrite(velocidade_direita, 255);
  }
}