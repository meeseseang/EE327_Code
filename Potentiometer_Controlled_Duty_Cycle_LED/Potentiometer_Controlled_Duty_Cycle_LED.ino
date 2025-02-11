#define ledPin 10
#define potPin A0
int cycleTimeMs = 10;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}
void loop() {
  float dutyCyclePerc = analogRead(potPin) / 1023.0;
  float onTime = dutyCyclePerc * cycleTimeMs;
  float offTime = cycleTimeMs - onTime;
  digitalWrite(ledPin, HIGH);
  delay(onTime);
  digitalWrite(ledPin, LOW);
  delay(offTime);
}
