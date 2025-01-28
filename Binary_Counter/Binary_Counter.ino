// 4 LED Binary Counter
int ledPin[] = {10, 9, 8, 7};
void setup(){
  for (int i=0;i<4; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}
void loop(){
  for (int counter=0;counter<16;counter++){
    displayBinary(counter);
    delay(250);
  }
  delay(500);
  for (int countDown=16;countDown>0;countDown--)
  {
    displayBinary(countDown);
    delay(100);
  }
  delay(500);
}
void displayBinary(byte numToShow){
  for (int i=0; i<4; i++){
    if (bitRead(numToShow, i)==1){
      digitalWrite(ledPin[i], HIGH);
    } else{
      digitalWrite(ledPin[i], LOW);
    }
  }
}