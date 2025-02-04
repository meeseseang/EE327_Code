void setup() {
  pinMode(3, OUTPUT);
}
void loop() {
  for(double i=0.0;i<1.0; i+=0.01){
    double brightness = (105 * (pow(exp(1),sin((-1.54)+6.3*i))-pow(exp(1),-1)));
    analogWrite(3, brightness);
    delay(50);
  }
}
