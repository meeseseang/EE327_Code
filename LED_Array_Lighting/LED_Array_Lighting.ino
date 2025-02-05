int ledPins[]={6, 7, 8, 9, 10, 11};
void setup() {
  for(int i=0; i<6, i++){
    pinMode(ledPins[i], OUTPUT);
  }
}
void loop() {
  for(int ii=0; ii<6; ii++){
    digitalWrite(ledPins[ii], HIGH);
    delay(250);
  }
  for(int ii=0; ii<6; ii++){
    digitalWrite(ledPins[ii], LOW);
    delay(250);
  }
}
