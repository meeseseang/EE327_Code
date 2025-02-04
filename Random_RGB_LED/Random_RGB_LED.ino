void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop() {
  int rand1 = random(0,255);
  int rand2 = random(0,255);
  int rand3 = random(0,255);
  analogWrite(3, rand1);
  analogWrite(4, rand2);
  analogWrite(5, rand3);
  delay(750);
}
