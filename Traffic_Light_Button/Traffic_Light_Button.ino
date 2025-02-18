#define red    4
#define green  5
#define yellow 6
#define randButton  7
#define crossButton 8

void setup() {
  // Set pin modes
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(randButton, INPUT_PULLUP);
  pinMode(crossButton, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(randButton) == 1) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    int randNum = random(0,3);
    switch(randNum) {
      case 0:
        digitalWrite(red, HIGH);
        delay(2500);
        digitalWrite(red, LOW);
        break;
      case 1:
        digitalWrite(green, HIGH);
        delay(2500);
        digitalWrite(green, LOW);
        break;
      case 2:
        digitalWrite(yellow, HIGH);
        delay(2500);
        digitalWrite(yellow, LOW);
        break;
    } 
  }
  digitalWrite(green, HIGH);
  for(int i=0;i<30;i++){
    if(digitalRead(crossButton)==0){
      break;
    }
    delay(100);
  }
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1500);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(3000);
  digitalWrite(red, LOW);
}