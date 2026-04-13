// 6 Alarme de Temperatura Simples
// Definição dos pinos
const int pinoNTC = A0;   // Sensor NTC conectado à porta analógica A0
const int led4 = 13;      // LED 4 (exemplo no pino 13)

// Variáveis de controle
int valorReferencia = 600; // Valor analógico equivalente a ~40°C (ajuste conforme seu NTC)
unsigned long tempoAnterior = 0;
const int intervaloPisca = 100; // 100ms conforme solicitado
bool estadoLed = LOW;

void setup() {
  pinMode(led4, OUTPUT);
  Serial.begin(9600); // Para monitoramento no Serial Monitor
}

void loop() {
  // Leitura do sensor
  int leitura = analogRead(pinoNTC);
  
  // Verifica se ultrapassou o limite
  if (leitura > valorReferencia) {
    unsigned long tempoAtual = millis();
    
    // Lógica para piscar sem usar delay()
    if (tempoAtual - tempoAnterior >= intervaloPisca) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed; // Inverte o estado (HIGH <-> LOW)
      digitalWrite(led4, estadoLed);
    }
  } else {
    // Se a temperatura estiver normal, mantém o LED desligado
    estadoLed = LOW;
    digitalWrite(led4, LOW);
  }
}