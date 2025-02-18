#define buttonPin 5
int led = 11;
bool ledToggle = false;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
}
void loop() {
  if(digitalRead(buttonPin) == LOW){
    if(ledToggle){
      ledToggle = false;
    } else {
      ledToggle = true;
    }
  }
  if(ledToggle){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(175);
}
