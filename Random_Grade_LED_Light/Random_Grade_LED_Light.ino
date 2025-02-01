// Define LED pins, one for each grade letter
int LEDpins[] = {6, 7, 8, 9, 10};
void setup() {
  // Loop through each pin and set it as a digital output
  for (int pin=0; pin<=5; pin++) {
    pinMode(LEDpins[pin], OUTPUT);
  }
  // Setup serial communication
  Serial.begin(115200);
  Serial.println("Beginning grading...");
}
void loop() {
  // Clear the pin status
  for (int i=0; i<5; i++) {
    digitalWrite(LEDpins[i], LOW);
  }
  // Generate a random number to represent a grade
  int randGrade = random(0,100);
  // Buffer to hold the formatted string
  char buf[50];
  // Determine the grade letter based on the random grade
  if (randGrade >= 90 && randGrade < 100) {
    digitalWrite(LEDpins[0], HIGH);
    sprintf(buf, "Grade Percentage: %d, Grade Letter: A", randGrade);
  } else if (randGrade >= 80 && randGrade < 90) {
    digitalWrite(LEDpins[1], HIGH);
    sprintf(buf, "Grade Percentage: %d, Grade Letter: B", randGrade);
  } else if (randGrade >= 70 && randGrade < 80) {
    digitalWrite(LEDpins[2], HIGH);
    sprintf(buf, "Grade Percentage: %d, Grade Letter: C", randGrade);
  } else if (randGrade >= 60 && randGrade < 70) {
    digitalWrite(LEDpins[3], HIGH);
    sprintf(buf, "Grade Percentage: %d, Grade Letter: D", randGrade);
  } else if (randGrade < 60) {
    digitalWrite(LEDpins[4], HIGH);
    sprintf(buf, "Grade Percentage: %d, Grade Letter: F", randGrade);
  }
  // Print the formatted string to the Serial Monitor
  Serial.println(buf);
  delay(2500);
}
