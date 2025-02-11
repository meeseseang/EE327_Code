int red = 11;
int green = 10;
void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  int randNum = random(0,100);
  if (isEven(randNum)) {
    digitalWrite(red, HIGH);
    Serial.print(randNum);
    Serial.println(" is even");
  } else {
    digitalWrite(green, HIGH);
    Serial.print(randNum);
    Serial.println(" is odd");
  }
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}

bool isEven(int num){
  if (num % 2 == 0) {
    return true;
  } else {
    return false;
  }
}