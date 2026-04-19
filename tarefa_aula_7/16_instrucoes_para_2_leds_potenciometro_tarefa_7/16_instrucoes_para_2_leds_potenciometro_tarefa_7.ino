//16 instruçõe para 2 leds com potenciometro
int led1 = 9;
int led2 = 10;
int pin_sensor = A0;
int valor_sensor = 0;


int temperatura = 0;
int potencia = 0;
bool estadoled = LOW;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  temperatura = map(valor_sensor, 0, 1023, 0, 90);

  unsigned long tempoAtual = millis();

  if (temperatura < 30) {
    analogWrite(led2, 51);
    digitalWrite(led1, 0); 
  }
  else if (30 <= temperatura && temperatura <= 60) {
  potencia = map(temperatura, 30, 60, 51, 255);
  analogWrite(led2, potencia);  
  digitalWrite(led1, 0);  
    }
  else if (temperatura > 60) {
    digitalWrite(led1, 1);
    analogWrite(led2, 255);
  }
}