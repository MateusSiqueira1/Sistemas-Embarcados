const int sensoralto = 10;
const int sensorbaixo = 11;
const int interruptor = 4;
const int botaol = 2;
const int botaod = 3;
const int motor = 5; // Pino de saída para a bomba (adicionado)

// Variáveis de tempo e controle
unsigned long tempoligar = 0;
unsigned long tempodesligar = 0;
const long intervalo = 10000; // 10 segundos

bool manual = false;
bool automatico = false;
bool aguardandoLigar = false;
bool aguardandoDesligar = false;

// Variáveis para evitar leituras repetidas (borda de subida/descida)
bool flagBaixo = false;
bool flagAlto = false;

void setup() {
  Serial.begin(9600);
  
  // Configuração das entradas e saídas
  pinMode(sensoralto, INPUT_PULLUP);
  pinMode(sensorbaixo, INPUT_PULLUP);
  pinMode(botaol, INPUT_PULLUP);
  pinMode(botaod, INPUT_PULLUP);
  pinMode(interruptor, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  
  digitalWrite(motor, LOW); // Garante motor desligado ao iniciar
}

void loop() {
  // 1. Seleção do Modo de Funcionamento
  // Se o interruptor estiver conectado ao GND (LOW), ativa o modo Manual
  if (digitalRead(interruptor) == LOW) {
    manual = true;
    automatico = false;
  } else {
    manual = false;
    automatico = true;
  }

  // ================= MODO MANUAL =================
  if (manual) {
    // Reseta as variáveis do modo automático para não causar acionamentos indevidos depois
    aguardandoLigar = false;
    aguardandoDesligar = false;
    flagBaixo = false;
    flagAlto = false;

    // Botão LIGA (pressionado vai para LOW devido ao PULLUP)
    if (digitalRead(botaol) == LOW) {
      digitalWrite(motor, HIGH);
    }
    // Botão DESLIGA
    if (digitalRead(botaod) == LOW) {
      digitalWrite(motor, LOW);
    }
  }

  // =============== MODO AUTOMÁTICO ===============
  if (automatico) {
    // Detecta o momento exato em que o nível fica BAIXO
    if (digitalRead(sensorbaixo) == HIGH && !flagBaixo) { 
      tempoligar = millis();
      aguardandoLigar = true;
      flagBaixo = true;
    }
    if (digitalRead(sensorbaixo) == LOW) {
      flagBaixo = false; // Reseta a flag quando o nível subir
    }

    // Detecta o momento exato em que o nível fica ALTO
    if (digitalRead(sensoralto) == HIGH && !flagAlto) { 
      tempodesligar = millis();
      aguardandoDesligar = true;
      flagAlto = true;
    }
    if (digitalRead(sensoralto) == LOW) {
      flagAlto = false; // Reseta a flag quando o nível descer
    }

    // Ações baseadas no tempo decorrido
    if (aguardandoLigar && (millis() - tempoligar >= intervalo)) {
      digitalWrite(motor, HIGH);
      aguardandoLigar = false; // Finaliza a contagem
    }

    if (aguardandoDesligar && (millis() - tempodesligar >= intervalo)) {
      digitalWrite(motor, LOW);
      aguardandoDesligar = false; // Finaliza a contagem
    }
  }
}
