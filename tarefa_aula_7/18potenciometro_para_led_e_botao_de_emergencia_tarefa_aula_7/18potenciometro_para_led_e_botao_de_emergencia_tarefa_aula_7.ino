//18potenciometro para led e botao de emergencia
const int led1 = 9;
const int led2 = 10;
const int pinoBotaoa = 2;
const int pin_sensor = A0;
int valor_sensor = 0;
int valorled = 0;
bool ligado = true;
bool pisca = false;

bool estadoled2 = 0;
int estadoBotaoa;               // Estado estável atual (será HIGH por padrão no Pull-up)
int ultimoEstadobotaoa = HIGH;  // No Pull-up, o estado de repouso é HIGH


unsigned long ultimoTempoDebouncea = 0;
unsigned long tempoDebounce = 50;

unsigned long ultimoTempoled = 0;
unsigned long intervaloled = 200;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
  pinMode(pinoBotaoa, INPUT_PULLUP);


  estadoBotaoa = HIGH; 
}

void loop() {

  int leituraa = digitalRead(pinoBotaoa);

  // 2. Verifica se o sinal mudou (ruído ou início de clique)
  if (leituraa != ultimoEstadobotaoa) {
    ultimoTempoDebouncea = millis();  // Reinicia o cronômetro
  }

  if (ligado) {
    valor_sensor = analogRead(pin_sensor);
    valorled = map(valor_sensor, 0, 1023, 0, 255);
    analogWrite(led1, valorled);
    Serial.println(valorled);
  }
  if ((millis() - ultimoTempoDebouncea) > tempoDebounce) {

    // Se o sinal estabilizou em um valor diferente do "estadoBotao" anterior
    if (leituraa != estadoBotaoa) {
      estadoBotaoa = leituraa;


      if (estadoBotaoa == LOW) {
        ligado = false;
        digitalWrite(led1, LOW);
        pisca = true;
        ultimoTempoled = millis();
      }
    }
  }
  if(millis() - ultimoTempoled >= intervaloled && pisca){
    estadoled2 = !estadoled2;
    digitalWrite(led2, estadoled2);
    ultimoTempoled = millis();
  }
  ultimoEstadobotaoa = leituraa;
}