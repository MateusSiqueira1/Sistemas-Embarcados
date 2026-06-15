const int st1 = 10;
const int sp1 = 11;
const int st2 = 12;
const int start = 2;
const int stop = 3;
const int m1 = 6;
const int mcr = 7;
const int ft = 4;
const int fc = 5;
const int sr = 8;



bool problema = false;

bool aguardandocoroamento = false;
unsigned long coroando = 0;
const int intervalo = 2000;


int processo = 0;
int contador = 0;
void setup() {
  Serial.begin(9600);

  // Configuração das entradas e saídas
  pinMode(start, INPUT_PULLUP);
  pinMode(stop, INPUT_PULLUP);
  pinMode(st1, INPUT);
  pinMode(st2, INPUT);
  pinMode(sp1, INPUT);
  pinMode(sr, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(mcr, OUTPUT);
  pinMode(ft, OUTPUT);
  pinMode(fc, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(start), liga, CHANGE);
  attachInterrupt(digitalPinToInterrupt(stop), desliga, CHANGE);
  digitalWrite(m1, LOW);  // Garante motor desligado ao iniciar
}

void loop() {

  if (digitalRead(st1) == 1) {
    digitalWrite(ft, 1);
    problema = 1;
  } else {
    digitalWrite(ft, 0);
  }
  if (problema == 1) {
    digitalWrite(mcr, 0);
    digitalWrite(m1, 0);
  }
  if (digitalRead(sp1) == 1 && processo == 1 && digitalRead(sr) == 1) {
    digitalWrite(m1, 0);
    processo == 2;
  }
  if (processo == 2 && !aguardandocoroamento) {
    digitalWrite(mcr, 1);
    coroando = millis();
    aguardandocoroamento = 1;
  }
  if (millis() - coroando >= intervalo) {
    contador++;
    if (contador > 1 && digitalRead(st2) == 0) {
      problema = 1;
      digitalWrite(fc, 1);
    }
    processo = 1;
    aguardandocoroamento = 0;
    digitalWrite(mcr, 0);
    digitalWrite(m1, 1);
  }
  if (contador >= 24) {
    processo = 0;
    digitalWrite(mcr, 0);
    digitalWrite(m1, 0);
  }
}
void liga() {
  problema = 0;
  digitalWrite(fc, 0);
  if (processo == 0 && digitalRead(st1) == 1) {
    processo = 1;
    digitalWrite(m1, 1);
    contador = 0;
  }
}
void desliga() {
  processo = 0;
  digitalWrite(mcr, 0);
  digitalWrite(m1, 0);
}

