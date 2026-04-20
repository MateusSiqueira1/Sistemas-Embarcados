//19ntc e botao ligar led
#include <math.h>

int sensor = A0;
const int pinoBotaoa = 2;
const int pinoBotaob = 3;
const int led1 = 13;
const int led2 = 12;

int estadoBotaoa = HIGH;
int ultimoEstadobotaoa = HIGH;
unsigned long ultimoTempoDebouncea = 0;
const long tempoDebounce = 50;
bool temperaturaboa = 1;

void setup() {
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(pinoBotaoa, INPUT_PULLUP);
    pinMode(pinoBotaob, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    float temp = ntc(analogRead(sensor));
    int leituraa = digitalRead(pinoBotaoa);
    if (leituraa != ultimoEstadobotaoa) {
    ultimoTempoDebouncea = millis();  // Reinicia o cronômetro
  }

  // 3. Verifica se o sinal permaneceu o mesmo por tempo suficiente
  if ((millis() - ultimoTempoDebouncea) > tempoDebounce) {

    // Se o sinal estabilizou em um valor diferente do "estadoBotao" anterior
    if (leituraa != estadoBotaoa) {
      estadoBotaoa = leituraa;

      // 4. LÓGICA INVERTIDA: Se o estado estável agora for LOW, significa PRESSIONADO
      if (estadoBotaoa == LOW && temperaturaboa) {
        digitalWrite(led1, 1); 
      }
    }
  }
    if (temp <= 150){
      temperaturaboa = true;
    }

    if (temp >= 160){
      digitalWrite(led1, 0); 
      temperaturaboa = false;
    }
    if (temp >= 150 && temp <= 160){
      digitalWrite(led2, 1);
    } else{
      digitalWrite(led2, 0);
    }
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" C");
    delay(1000);
    ultimoEstadobotaoa = leituraa;
}

float ntc(int leitura) {
    // 1. Calcular a resistência do NTC
    // Onde 1000.0 é o seu resistor fixo de 1k
    // Se a leitura for 0, evitamos divisão por zero
    if (leitura == 0) return -273.15; 
    
    // Fórmula para divisor com resistor fixo no GND:
    // R_ntc = R_fixo * ((V_in / V_out) - 1)
    float resistencia = 1000.0 * (1023.0 / (float)leitura - 1.0);

    // 2. Parâmetros do NTC (Ajuste conforme seu componente)
    const float BETA = 3950.0;           
    const float R_NOMINAL = 10000.0;     // NTC de 10k (ajuste se o seu for diferente)
    const float T_NOMINAL = 298.15;      // 25°C em Kelvin

    // 3. Equação de Steinhart-Hart (Beta)
    float steinhart;
    steinhart = log(resistencia / R_NOMINAL); // ln(R/Ro)
    steinhart /= BETA;                        // 1/B * ln(R/Ro)
    steinhart += 1.0 / T_NOMINAL;             // + (1/To)
    steinhart = 1.0 / steinhart;              // Inverte para Kelvin

    return steinhart - 273.15;                // Converte para Celsius
}