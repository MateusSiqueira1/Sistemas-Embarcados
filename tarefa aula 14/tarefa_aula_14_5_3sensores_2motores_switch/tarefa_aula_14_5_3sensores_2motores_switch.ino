const int mch = 4;
const int mca = 5;
const int start = 2;
const int stop = 3;
const int s1 = 6;
const int s2 = 7;
const int s3 = 8;
const int cilindro = 9;
const int lampada = 10;

int processo = 0;
int contador = 0;

void setup() {
  pinMode(start, INPUT_PULLUP);
  pinMode(stop, INPUT_PULLUP);
  pinMode(st1, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(mch, OUTPUT);
  pinMode(mca, OUTPUT);
  pinMode(cilindro, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(start), liga, CHANGE);
  attachInterrupt(digitalPinToInterrupt(stop), desliga, CHANGE);

}

void loop() {
  switch(processo){
    case 1:
    if(digitalRead(s2) == 0){
      digitalWrite(mch, 1);
    } else(){
      digitalWrite(mch, 0);
    }
    if(digitalRead(s3) == 0){
      digitalWrite(mca, 1);
    } else(){
      digitalWrite(mca, 0);
    }
    if(digitalRead(s2) == 1 && digitalRead(s3) == 1){
      processo = 2;
    }
    break;
    case 2:
    digitalWrite(cilindro, 1);
    processo = 3;
  
  break;
  case 3:
  if(digitalRead(s3) = 1){
digitalWrite(cilindro, 0);
contador++
processo = 4;
  }
  break;
  case 4:
  if(contador >= 5){
    if(digitalRead(s3) == 1){
      digitalWrite(mca, 1);

    }else{
      contador = 0;
      processo = 1;
    }
  } else{
    processo = 1;
  }
}
}
void liga(){
  processo = 1;
  digitalWrite(lampada, 1);
}
void desliga(){
  processo = 0;
  digitalWrite(mch, 0);
  digitalWrite(mca, 0);
  digitalWrite(lampada, 0);
}
