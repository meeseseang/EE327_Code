int ledPins[] = {2, 3, 4, 5, 6, 7};
void setup() {
  for (int pins = 0; pins < 6; pins++) {
    pinMode(ledPins[pins], OUTPUT);
  }
}
void loop() {
  for(int i=0; i<5; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i+1], HIGH);
    delay(50);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[i+1], LOW);
  }
  for(int ii=5; ii>0; ii--){
    digitalWrite(ledPins[ii], HIGH);
    digitalWrite(ledPins[ii-1], HIGH);
    delay(50);
    digitalWrite(ledPins[ii], LOW);
    digitalWrite(ledPins[ii-1], LOW);
  }
}
