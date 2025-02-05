int LED = 10;
void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  for (int i=0; i<4; i++) {
    shortBlink(LED);
    delay(500);
  }
  for (int i=0; i<4; i++) {
    longBlink(LED);
    delay(500);
  }
  for (int i=0; i<4; i++) {
    shortBlink(LED);
    delay(500);
  }
  delay(2000);
}
void shortBlink(int ledPin){
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}
void longBlink(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(1500);
  digitalWrite(ledPin, LOW);
}