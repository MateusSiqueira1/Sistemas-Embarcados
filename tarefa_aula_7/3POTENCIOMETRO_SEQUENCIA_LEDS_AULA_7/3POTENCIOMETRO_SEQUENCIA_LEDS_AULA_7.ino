//Escalonamento (Barra de LEDs):
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int pin_sensor = A0;
int valor_sensor = 0;



void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  Serial.print("Valor analogico =");
  Serial.println(valor_sensor);
delay(200);

  if(valor_sensor < 255){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  if(valor_sensor >= 255  && valor_sensor < 511){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(valor_sensor >= 511 && valor_sensor < 767){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(valor_sensor >= 767 && valor_sensor <921){
   digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  if(valor_sensor >= 921){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}