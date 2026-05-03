int leds[3] = {9,10,11};

int tempo[3] = {2000,500,2000};

void setup() {
 for(int i=0; i<3; i++){
 pinMode(leds[i], OUTPUT);
 }
}
void loop() {
 for(int i=0; i<3; i++){
 digitalWrite(leds[i], HIGH);
 delay(tempo[i]);
 digitalWrite(leds[i], LOW);
 }
}
