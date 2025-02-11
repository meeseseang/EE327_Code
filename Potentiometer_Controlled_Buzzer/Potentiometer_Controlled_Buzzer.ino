#define buzzerPin 10
#define potPin A0

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);
  if (potValue >896){
    frequencyToPWM(262, buzzerPin);
  }else if (potValue >768) {
    frequencyToPWM(294, buzzerPin);
  }else if (potValue > 640){
    frequencyToPWM(311, buzzerPin);
  }else if (potValue > 512){
    frequencyToPWM(349, buzzerPin);
  }else if (potValue > 384){
    frequencyToPWM(392, buzzerPin);
  }else if (potValue > 256){
    frequencyToPWM(415, buzzerPin);
  }else if (potValue > 128){
    frequencyToPWM(466, buzzerPin);
  }else if (potValue >= 0){
    frequencyToPWM(523, buzzerPin);
  }
}
void frequencyToPWM(int frequency, int pinNum){
  long period = 1000000L / frequency;
  long halfPeriod = period / 2;
  digitalWrite(pinNum, HIGH);
  delayMicroseconds(halfPeriod);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(halfPeriod);
}
