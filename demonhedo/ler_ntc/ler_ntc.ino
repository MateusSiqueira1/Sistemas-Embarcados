//ler ntc
#include <math.h>

int sensor = A0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    float temp = ntc(analogRead(sensor));
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" C");
    delay(1000);
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