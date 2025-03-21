// Use preprocessor definitions to define the pins
#define enPIN    11
#define dir1     10
#define dir2     9
#define redLED   3
#define greenLED 2
#define yellLED  4
#define blueLED  5
#define potPIN   A0

// Define variables
float delayMicro = 1500.0; // Value is in microseconds (500 for a 2kHz PWM frequency)
bool clockwise = false;
bool motorOn = false;

void setup() {
  // Initialize pins for input/output
  pinMode(enPIN, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(potPIN, INPUT);
}

void setMotorSpeed() {
  // Intial variables
  int potValue = analogRead(A0);
  float percent = 0.0;

  // Check if potentiometer is above or below the half point
  if (potValue >= 511) {
    // Set direction through the L293D chip
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    clockwise = true; // Set direction bool
    
    // Calculate duty cycle
    percent = ((float)potValue - 511.0) / 512.0;
    float onTime = percent * delayMicro;
    float offTime = delayMicro - onTime;

    // Send PWM signal
    digitalWrite(enPIN, HIGH);
    delayMicroseconds(onTime);
    digitalWrite(enPIN, LOW);
    delayMicroseconds(offTime);
  } else {
    // Same as above, just different direction
    digitalWrite(dir2, LOW);
    digitalWrite(dir1, HIGH);
    clockwise = false;
    percent = (512.0 - (float)potValue) / 512.0; // Invert the percent so the closer to center the lower the duty cycle
    float onTime = percent * delayMicro;
    float offTime = delayMicro - onTime;
    digitalWrite(enPIN, HIGH);
    delayMicroseconds(onTime);
    digitalWrite(enPIN, LOW);
    delayMicroseconds(offTime);
  }

  // Set motorOn status LED
  if ((percent*100) < 30.0) {
    motorOn = false;
  } else {
    motorOn = true;
  }
}

void loop() {
  setMotorSpeed();
  if(motorOn) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  } else {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  if (clockwise) {
    digitalWrite(blueLED, HIGH);
    digitalWrite(yellLED, LOW);
  } else {
    digitalWrite(blueLED, LOW);
    digitalWrite(yellLED, HIGH);
  }
}
