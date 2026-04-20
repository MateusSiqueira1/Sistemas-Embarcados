//Binario com 2 botoes
const int pin_botaoA = 2;
const int pin_botaoB = 3;
const int pin_LED1 = 9;
const int pin_LED2 = 10;
const int pin_LED3 = 11;
const int pin_LED4 = 12;

int lastButtonStateA = HIGH;
int buttonStateA;
int buttonStateB;
unsigned long lastDebounceTimeA = 0;
int lastButtonStateB = HIGH;
unsigned long lastDebounceTimeB = 0;
unsigned long debounceDelay = 50;
unsigned long ultimotempoled = 0;
unsigned long intervaloled = 2000;

int conta = 0;
int numero = 0;
bool estadoled = 0;
bool pisca = false;
unsigned long ultimotempopisca = 0;
unsigned long intervalopisca = 200;
bool acertou = false;
void setup() {
  pinMode(pin_botaoA, INPUT_PULLUP);
  pinMode(pin_botaoB, INPUT_PULLUP);
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  pinMode(pin_LED3, OUTPUT);
  pinMode(pin_LED4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int readingA = digitalRead(pin_botaoA);
  if (readingA != lastButtonStateA) {
    lastDebounceTimeA = millis();
  }
  if ((millis() - lastDebounceTimeA) > debounceDelay) {

    if (readingA != buttonStateA) {
      buttonStateA = readingA;

      if (buttonStateA == LOW) {
        conta++;
        ultimotempoled = millis();
      }
    }
  }
  lastButtonStateA = readingA;
  int readingB = digitalRead(pin_botaoB);
  if (readingB != lastButtonStateB) {
    lastDebounceTimeB = millis();
  }
  if ((millis() - lastDebounceTimeB) > debounceDelay) {

    if (readingB != buttonStateB) {
      buttonStateB = readingB;

      if (buttonStateB == LOW) {
        if (conta == 0) {
          numero += 1000;
                  conta++;

        }
        else if (conta == 1) {
          numero += 100;
                  conta++;

        }
        else if (conta == 2) {
          numero += 10;
                  conta++;

        }
        else if (conta == 3) {
          numero += 1;
                  conta++;
          ultimotempoled = millis();

        }
         
        }
      }
    }
  
  lastButtonStateB = readingB;

if (numero == 1010 && conta == 4) {

          digitalWrite(pin_LED1, 1);
          digitalWrite(pin_LED2, 1);
          digitalWrite(pin_LED3, 1);
          digitalWrite(pin_LED4, 1);
          
          
        }
  if (millis() - ultimotempoled >= intervaloled) {
    digitalWrite(pin_LED1, 0);
    digitalWrite(pin_LED2, 0);
    digitalWrite(pin_LED3, 0);
    digitalWrite(pin_LED4, 0);
  }
if (conta == 4 && numero != 1010){
  if (millis() - ultimotempopisca >= intervalopisca) {
    estadoled = !estadoled;
    digitalWrite(pin_LED1, estadoled);
    digitalWrite(pin_LED2, estadoled);
    digitalWrite(pin_LED3, estadoled);
    digitalWrite(pin_LED4, estadoled);
    ultimotempopisca = millis();
  }
}
  Serial.print("Contagem = ");
  Serial.println(numero);
}