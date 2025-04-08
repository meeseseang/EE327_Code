#define latchPin 4
#define serialDat 2
#define shiftClk 3

const uint8_t segmentMap[11] = {
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100000, // 7
  0b11111110, // 8
  0b11110110, // 9
  0b00000001  // DP (decimal point)
};

void displayNum(uint8_t data) {
  digitalWrite(latchPin, LOW); // Prepare to send data
  shiftOut(serialDat, shiftClk, LSBFIRST, data);
  digitalWrite(latchPin, HIGH); // Latch the data
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(serialDat, OUTPUT);
  pinMode(shiftClk, OUTPUT);
}

void loop() {
  for (int i = 0; i < 11; i++) { // Loop through 0-9 and DP
    displayNum(segmentMap[i]);
    delay(500); // Wait 1 second between numbers
  }
}
