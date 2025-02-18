// Pin definitions
#define rightSide 5
#define leftSide 2
int ledPins[] = {8, 9, 10, 11};

// Boolean to track state
bool moveRight = true;

void setup() {
  pinMode(rightSide, INPUT_PULLUP);
  pinMode(leftSide, INPUT_PULLUP);
  for(int i=0;i<4;i++){
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(rightSide) == LOW){
    moveRight = true;
  } else if(digitalRead(leftSide) == LOW) {
    moveRight = false;
  }
  moveLED();
}

void moveLED(){
  if(moveRight){
    for(int i=0;i<4;i++){
      digitalWrite(ledPins[i], HIGH);
      delay(100);
      digitalWrite(ledPins[i], LOW);
    }
  } else {
    for(int ii=3;ii>=0;ii--){
      digitalWrite(ledPins[ii], HIGH);
      delay(100);
      digitalWrite(ledPins[ii], LOW);
    }
  }
}