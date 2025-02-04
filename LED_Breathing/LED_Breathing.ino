void setup() {
  pinMode(3, OUTPUT);
}
void loop() {
  for(int i=0;i<255; i+=5){
    analogWrite(3, i);
    delay(5);
  }
  int a = 255;
  while (a>0) {
    analogWrite(3, a);
    delay(5);
    a -= 5;
  }
}
