// Set pin numbers
const int enablePin = 9;
const int dir1      = 10;
const int dir2      = 11;
const int button1   = 4;
const int button2   = 2;

// Toggle booleans
bool motorOn   = false;
bool clockwise = false;

void setup() {
  // Set pin modes for input and output
  pinMode(enablePin, OUTPUT);
  pinMode(dir1,      OUTPUT);
  pinMode(dir2,      OUTPUT);
  pinMode(button1,   INPUT_PULLUP);
  pinMode(button2,   INPUT_PULLUP);

  // Enable the motor driver
  digitalWrite(enablePin, HIGH);
}

void loop() {
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
    if(clockwise){
      digitalWrite(dir2, LOW);
      digitalWrite(dir1, HIGH);
    } else {
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
    }
  } else {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
  delay(500);
}
