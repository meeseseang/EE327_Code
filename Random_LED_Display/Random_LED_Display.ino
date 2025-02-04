int LEDpins[] = {3, 4, 5, 6, 7, 8};
void setup() {
  for (int i=0;i<6;i++){
    pinMode(LEDpins[i], OUTPUT);
  }
}
void loop() {
  int pinSelect = random(0,5);
  digitalWrite(LEDpins[pinSelect], HIGH);
  delay(250);
  digitalWrite(LEDpins[pinSelect], LOW);
}
