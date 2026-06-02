                                                                                                                      const int pin_botao_start = 2;
const int pin_botao_stop = 3;
const int sensor3 = 4;
const int sensor4 = 5;
const int sensor1 = 6;
const int sensor2 = 7;
const int horario = 8;
const int antihorario = 9;

int estado = 0;

unsigned long tempo_ant = 0, tempo_atual = 0;

void setup() {
  pinMode(pin_botao_start, INPUT_PULLUP);
  pinMode(pin_botao_stop, INPUT_PULLUP);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(horario, OUTPUT);
  pinMode(antihorario, OUTPUT);
}

void loop() {
  bool stop = digitalRead(pin_botao_stop);
  bool sen1 = digitalRead(sensor1);
  bool sen2 = digitalRead(sensor2);
  bool sen3 = digitalRead(sensor3);
  bool sen4 = digitalRead(sensor4);
  if (stop == 0) {
    estado = 0;
    digitalWrite(horario, 0);
    digitalWrite(antihorario, 0);
  }


  switch (estado) {
    case 0:
      bool start = digitalRead(pin_botao_start);

      if (start == 0) {
        estado = 1;
      }
      break;
    case 1:
      tempo_atual = millis();
      if (tempo_atual - tempo_ant > 2000) {
        estado = 2;
      }
      break;
    case 2:
      if (sen3 == 1 && sen4 == 0) {
        digitalWrite(horario, 1);
        digitalWrite(antihorario, 0);
      }
      if (sen3 == 1 && sen4 == 1) {
        digitalWrite(horario, 0);
        digitalWrite(antihorario, 1);
        estado = 3;
      }
      break;
    case 3:
      if (sen1 == 1 || sen2 == 1) {
        digitalWrite(horario, 0);
        digitalWrite(antihorario, 0);
        estado = 1;
      }
      break;
    default:
      digitalWrite(horario, 0);
      digitalWrite(antihorario, 0);
      estado = 0;
  }
  break;
}
