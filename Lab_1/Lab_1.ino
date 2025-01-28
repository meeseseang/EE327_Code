const int RedLED = 10;
const int GreenLED = 8;

void setup() {
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);

}

void loop() {
  // Blink together
  for(int i=0; i<5;i++){
    digitalWrite(RedLED, HIGH);
    digitalWrite(GreenLED, HIGH);
    delay(750);
    digitalWrite(RedLED, LOW);
    digitalWrite(GreenLED, LOW);
    delay(750);
  }

  delay(1000);
  // Blink alternate
  for(int ii=0; ii<5;ii++){
    digitalWrite(RedLED, HIGH);
    delay(750);
    digitalWrite(RedLED, LOW);
    digitalWrite(GreenLED, HIGH);
    delay(750);
    digitalWrite(GreenLED, LOW);

  }
  delay(1000);
  for(int io=0;io<5;io++){
    digitalWrite(RedLED, HIGH);
    digitalWrite(GreenLED, HIGH);
    delay(250);
    digitalWrite(GreenLED, LOW);
    delay(250);
    digitalWrite(GreenLED, HIGH);
    delay(250);
    digitalWrite(RedLED, LOW);
    digitalWrite(GreenLED, LOW);
    delay(250);
  }
}
