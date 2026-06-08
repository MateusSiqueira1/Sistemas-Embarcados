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

  bool s_ex_d = digitalRead(ex_direita);
  bool s_d = digitalRead(direita);
  bool s_m = digitalRead(meio);
  bool s_e = digitalRead(esquerda);
  bool s_ex_e = digitalRead(ex_esquerda);
  if (!s_ex_d && !s_ex_e && !s_d && !s_e && !s_m) {
    analogWrite(velocidade_esquerda, 110);
    analogWrite(velocidade_direita, 70);
  } else if (s_d && !s_e && !s_m) {
    analogWrite(velocidade_esquerda, 200);
    analogWrite(velocidade_direita, 80);

  } else if (s_e && !s_d && !s_m) {
    analogWrite(velocidade_direita, 200);
    analogWrite(velocidade_esquerda, 80);

  }else if (s_ex_d && !s_ex_e && !s_d && !s_m) {
    analogWrite(velocidade_esquerda, 240);
    analogWrite(velocidade_direita, 95);

  } else if (s_m && !s_d && !s_e) {
    analogWrite(velocidade_esquerda, 245);
    analogWrite(velocidade_direita, 255);

  } else if (s_ex_e && !s_ex_d && !s_e && !s_m) {
    analogWrite(velocidade_direita, 255);
    analogWrite(velocidade_esquerda, 95);

  } else {
    analogWrite(velocidade_esquerda, 245);
    analogWrite(velocidade_direita, 255);
  }
}