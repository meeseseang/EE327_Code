// Set pin numbers
#define enPIN    11
#define dir1     10
#define dir2     9
#define redLED   3
#define greenLED 2
#define yellLED  4
#define blueLED  5
#define potPIN   A0
#define button1  6
#define button2  7

float delayMicro = 4000.0;

// Toggle booleans
bool motorOn   = false;
bool clockwise = false;

void setup() {
  // Set pin modes for input and output
  pinMode(enPIN,     OUTPUT);
  pinMode(dir1,      OUTPUT);
  pinMode(dir2,      OUTPUT);
  pinMode(button1,   INPUT_PULLUP);
  pinMode(button2,   INPUT_PULLUP);
  pinMode(redLED,    OUTPUT);
  pinMode(greenLED,  OUTPUT);
  pinMode(yellLED,   OUTPUT);
  pinMode(blueLED,   OUTPUT);
}

void loop() {
  float percent = (float)analogRead(potPIN) / 1023.0;
  float onTime = percent * delayMicro;
  float offTime = delayMicro - onTime;
  // Toggle motor on and direction based on button input
  if(digitalRead(button1) == LOW){
    if(motorOn){
      motorOn = false;
    } else {
      motorOn = true;
    }
  }
  if(digitalRead(button2) == LOW){
    if(clockwise){
      clockwise = false;
    } else {
      clockwise = true;
    }
  }
  // Based on booleans enable/disable motor and set direction
  if(motorOn){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    if(clockwise){
      digitalWrite(blueLED, HIGH);
      digitalWrite(yellLED, LOW);
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
      digitalWrite(enPIN, HIGH);
      delayMicroseconds(onTime);
      digitalWrite(enPIN, LOW);
      delayMicroseconds(offTime);
    } else {
      digitalWrite(blueLED, LOW);
      digitalWrite(yellLED, HIGH);
      digitalWrite(dir2, LOW);
      digitalWrite(dir1, HIGH);
      digitalWrite(enPIN, HIGH);
      delayMicroseconds(onTime);
      digitalWrite(enPIN, LOW);
      delayMicroseconds(offTime);
    }
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
}
