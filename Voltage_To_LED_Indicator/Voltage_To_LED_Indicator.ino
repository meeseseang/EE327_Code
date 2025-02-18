#define potPin A0
int ledPins[] = {6, 7, 8, 9, 10, 11};
void setup() {
  for (int i=0;i<6;i++){
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);
}

void loop() {
  int potRead = analogRead(potPin);
  if(potRead > 878) {
    ledWrite(6);
  } else if(potRead > 732){
    ledWrite(5);
  } else if(potRead > 586){
    ledWrite(4);
  } else if(potRead >= 440){
    ledWrite(3);
  } else if(potRead > 294){
    ledWrite(2);
  } else if(potRead > 147){
    ledWrite(1);
  } 
  for(int i=0; i<6;i++){
    digitalWrite(ledPins[i], LOW);
  }
}

void ledWrite(int numLights){
  for(int i=0;i<numLights;i++){
    digitalWrite(ledPins[i], HIGH);
  }
}