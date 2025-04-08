// Define shift register pins
#define latchPin  4
#define serialDat 2
#define shiftClk  3

// Define button matrix pins
#define C1 10
#define C2 9
#define C3 8
#define R1 13
#define R2 12
#define R3 11

// Define array of matrix pins
const int matrixPins[] = {R1, R2, R3};

// Define number data in binary format for shift register to output to 7 segment display
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

// Function to display number on 7 segment display
void displayNum(int num) {
  digitalWrite(latchPin, LOW); // Prepare to send data
  shiftOut(serialDat, shiftClk, LSBFIRST, segmentMap[num]);
  digitalWrite(latchPin, HIGH); // Latch the data
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(serialDat, OUTPUT);
  pinMode(shiftClk, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(C2, INPUT_PULLUP);
  pinMode(C3, INPUT_PULLUP);
  pinMode(C1, INPUT_PULLUP);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
}

void loop() {
  for(int i=0;i<3;i++){
    digitalWrite(matrixPins[i], LOW);
    if(i==0){
      if(digitalRead(C1)== 0){
        displayNum(1);
      }else if(digitalRead(C2)==0){
        displayNum(2);
      }else if(digitalRead(C3)==0){
        displayNum(3);
      }
    }
    if(i==1){
      if(digitalRead(C1)== 0){
        displayNum(4);
      }else if(digitalRead(C2)==0){
        displayNum(5);
      }else if(digitalRead(C3)==0){
        displayNum(6);
      }
    }
    if(i==2){
      if(digitalRead(C1)== 0){
        displayNum(7);
      }else if(digitalRead(C2)==0){
        displayNum(8);
      }else if(digitalRead(C3)==0){
        displayNum(9);
      }
    }
    digitalWrite(matrixPins[i], HIGH);
  }

}
