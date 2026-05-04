// ligar led com dois botoes usando interrupt
const int led = 13;
const int interruptpin1 = 2;
const int interruptpin2 = 3;
bool state = LOW;
void setup() {
pinMode(led, OUTPUT);
pinMode(interruptpin1, INPUT_PULLUP);
pinMode(interruptpin2, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptpin1), liga, CHANGE);
attachInterrupt(digitalPinToInterrupt(interruptpin2), desliga, CHANGE);
}

void loop() {
digitalWrite(led, state);
}
void liga(){
  state = HIGH;
}
void desliga(){
  state = LOW;
}
