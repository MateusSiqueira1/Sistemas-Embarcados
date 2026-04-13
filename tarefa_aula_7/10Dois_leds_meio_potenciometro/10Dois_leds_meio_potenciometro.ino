//10 ligar dois leds meio potenciometro
const int led = 13;
const int analogPin = A0;

unsigned long ultimo = 0;
int led1 = 9;
int led2 = 10;
int pin_sensor = A0;
int valor_sensor = 0;
int valorled1 = 0;
int valorled2 = 0;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  if (valor_sensor <= 512) {
    valorled1 = map(valor_sensor, 0, 512, 255, 0);
    analogWrite(led1, valorled1);
    Serial.print("valorled1:");
    Serial.println(valorled1);
    delay(10);
  }
  if (valor_sensor > 512) {
    valorled2 = map(valor_sensor, 513, 1023, 0, 255);
    analogWrite(led2, valorled2);
    Serial.print("valorled2:");
    Serial.println(valorled2);
    delay(10);
  }
}