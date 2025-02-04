void setup() {
  pinMode(3, OUTPUT);
}
void loop() {
  for(int i=0;i<255; i+=5){
    analogWrite(3, i);
    delay(5);
  }
  for(int i=255;i>0; i-=5){
    analogWrite(3, i);
    delay(5);
  }
}
