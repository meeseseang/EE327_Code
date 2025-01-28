int ledPin[] = {3, 5, 6};
void setup() {
  for(int pin=0; pin<3; pin++){
    pinMode(ledPin[pin], OUTPUT);
  }
}
void loop() {
  for(int ii=0;ii<3;ii++){
    for(int i=0; i<255; i+=5){
      analogWrite(ledPin[ii], i);
      delay(50);
    }
    delay(250);
  }
  for(int ii=0;ii<3;ii++){
    for(int i=255; i>0; i-=5){
      analogWrite(ledPin[ii], i);
      delay(50);
    }
    delay(250);
  }
  delay(500);
}
