// Pin definitions
#define brighter 5
#define dimmer 2
const int led = 11;

// Define duty cycle info
float dutyTime = 10.0;
float brightnessLevel = 0.75;
float onTime = brightnessLevel * dutyTime;
float offTime = dutyTime - onTime;

void setup() {
  pinMode(brighter, INPUT);
  pinMode(dimmer, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  // Check for button press and alter duty cycle percentage accordingly
  if(digitalRead(brighter) == LOW){
    if(brightnessLevel >= 1.0){
      brightnessLevel = 1.0;
    } else {
      brightnessLevel = brightnessLevel + 0.01;
    }
  }
  
  // Same as above, just make it dimmer
  if(digitalRead(dimmer) == LOW){
    if(brightnessLevel <=0.0){
      brightnessLevel = 0.1;
    } else {
      brightnessLevel = brightnessLevel - 0.01;
    }
  }

  // Set delays for duty cycle and cycle the LED
  onTime = dutyTime*brightnessLevel;
  offTime = dutyTime - onTime;
  digitalWrite(led, HIGH);
  delay(onTime);
  digitalWrite(led, LOW);
  delay(offTime);
}
