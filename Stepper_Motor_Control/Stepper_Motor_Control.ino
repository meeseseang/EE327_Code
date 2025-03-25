// Define LED pins
#define redLED    8
#define greenLED  7
#define blueLED   4
#define yellowLED 5

// Define input pins
#define button1 2
#define button2 3
#define potPin  A0

// Define global variables
float totalDelay = 25000.0; // in microseconds
volatile bool motorOn   = false;
volatile bool clockwise = false;
int drivePins[] = {6, 9, 10, 11};
int stepNum = 0;

// Define interrupt service routines
void motorOnInterrupt(){
  if(motorOn) {
    motorOn = false;
  } else {
    motorOn = true;
  }
}

void motorDirInterrupt(){
  if(clockwise){
    clockwise = false;
  } else {
    clockwise = true;
  }
}

// Sequence for the stepper motor 
int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1} 
};

int calcDelay(){
  float percentTime = analogRead(potPin) / 1023.0;
  return totalDelay * percentTime;
}

void incrementCW(){
  for(int i=0; i<4;i++){
    digitalWrite(drivePins[i], stepSequence[stepNum][i]);
  }
  stepNum += 1;
  if (stepNum > 8){
    stepNum = 0;
  }
}

void incrementCCW(){
  for(int i=0; i<4;i++){
    digitalWrite(drivePins[i], stepSequence[stepNum][i]);
  }
  stepNum -= 1;
  if (stepNum < 0){
    stepNum = 8;
  }
}

void setup() {
  // Set output pins
  pinMode(redLED,    OUTPUT);
  pinMode(greenLED,  OUTPUT);
  pinMode(blueLED,   OUTPUT);
  pinMode(yellowLED, OUTPUT);
  for(int i=0;i<4;i++){
    pinMode(drivePins[i], OUTPUT);
  }

  // Set input pins
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(potPin,  INPUT);
  
  // Setup interrupts
  attachInterrupt(digitalPinToInterrupt(button1), motorOnInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2), motorDirInterrupt, FALLING);

}

void loop() {
  int delayTime = calcDelay();
  if (motorOn){
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    if (clockwise){
      digitalWrite(yellowLED, LOW);
      digitalWrite(blueLED, HIGH);
      incrementCW();
      delayMicroseconds(delayTime);
    } else {
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, HIGH);
      incrementCCW();
      delayMicroseconds(delayTime);
    }
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

}
