int ledPins[] = {6, 7, 8, 10};

void setup() {
  for(int i=0;i<4;i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for(int ii=0;ii<4;ii++){
    delay(150);
    digitalWrite(ledPins[ii], HIGH);
    delay(150);
    digitalWrite(ledPins[ii], LOW);
  }
  for(int io=4;io>=0;io--){
    delay(50);
    digitalWrite(ledPins[io], HIGH);
    delay(50);
    digitalWrite(ledPins[io], LOW);
  }
  delay(100);
}
