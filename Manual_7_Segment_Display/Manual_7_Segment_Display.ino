#define A 6
#define B 7
#define C 10
#define D 9
#define E 8
#define F 5
#define G 4
#define DP 11
int segments[8] = {A, B, C, D, E, F, G, DP};
int numMap[11][8] = {
// A  B  C  D  E  F  G  DP
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9
  {0, 0, 0, 0, 0, 0, 0, 1}  // dot
};
void displayNum(int num){
  switch (num) {
    case 0:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[0][i]);
      }
      break;
    case 1:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[1][i]);
      }
      break;
    case 2:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[2][i]);
      }
      break;
    case 3:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[3][i]);
      }
      break;
    case 4:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[4][i]);
      }
      break;
    case 5:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[5][i]);
      }
      break;
    case 6:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[6][i]);
      }
      break;
    case 7:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[7][i]);
      }
      break;
    case 8:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[8][i]);
      }
      break;
    case 9:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[9][i]);
      }
      break;
    case 10:
      for(int i=0;i<9;i++){
        digitalWrite(segments[i], numMap[10][i]);
      }
      break;
  }
}
void setup() {
  for(int i=0; i<9;i++){
    pinMode(segments[i], OUTPUT);
  }
}
void loop() {
  for(int ii=0;ii<=10;ii++){
    displayNum(ii);
    delay(500);
  }
}
