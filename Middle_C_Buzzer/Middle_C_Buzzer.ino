#define ledPin 10
float cycleTimeMs = 3.75;
float dutyCyclePercent = 0.95;
float onTime = cycleTimeMs * dutyCyclePercent;
float offTime = cycleTimeMs - onTime;
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(onTime*1000);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(offTime*1000);
}
