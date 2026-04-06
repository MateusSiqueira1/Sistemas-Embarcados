// ligando led com potenciometro
int led1 = 9;
int led2 = 10;
int led3 = 11;
int pin_sensor = A0;
int valor_sensor = 0;



void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  Serial.print("Valor analogico =");
  Serial.println(valor_sensor);
delay(200);

  if(valor_sensor < 204){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
  if(valor_sensor >= 204  && valor_sensor < 409){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  if(valor_sensor >= 409 && valor_sensor < 613){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  if(valor_sensor >= 613 && valor_sensor <818){
   digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  if(valor_sensor >= 818){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}