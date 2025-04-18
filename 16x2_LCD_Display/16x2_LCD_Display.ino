#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define DHTPIN 8

void setup() {
 // LCD pin setup
 pinMode(E, OUTPUT);
 pinMode(RS, OUTPUT);
 pinMode(D4, OUTPUT);
 pinMode(D5, OUTPUT);
 pinMode(D6, OUTPUT);
 pinMode(D7, OUTPUT);
 
 // DHT11 pin
 pinMode(DHTPIN, OUTPUT);
 
 // Initialize LCD
 delay(50);
 write4bits(0x03); delay(5);
 write4bits(0x03); delay(5);
 write4bits(0x03); delay(1);
 write4bits(0x02); // Set 4-bit mode

 sendCommand(0x28); // Function set: 2-line, 5x7 font
 sendCommand(0x08); // Display off
 sendCommand(0x01); delay(2); // Clear display
 sendCommand(0x06); // Entry mode
 sendCommand(0x0C); // Display on, cursor off
}

void loop() {
 byte data[5] = {0, 0, 0, 0, 0};

 // Send start signal
 pinMode(DHTPIN, OUTPUT);
 digitalWrite(DHTPIN, LOW);
 delay(18);
 digitalWrite(DHTPIN, HIGH);
 delayMicroseconds(40);
 pinMode(DHTPIN, INPUT);

 // Wait for response
 while (digitalRead(DHTPIN) == HIGH);
 while (digitalRead(DHTPIN) == LOW);
 while (digitalRead(DHTPIN) == HIGH);

 // Read 5 bytes
 for (int i = 0; i < 5; i++) {
  for (int j = 0; j < 8; j++) {
   while (digitalRead(DHTPIN) == LOW);
   unsigned long t = micros();
   while (digitalRead(DHTPIN) == HIGH);
   if ((micros() - t) > 40)
    data[i] |= (1 << (7 - j));
  }
 }

 // Check checksum
 if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
  int temp = data[2]; // Integer part of temperature
  char buffer[16];
  sprintf(buffer, "Temp: %d C", temp);

  sendCommand(0x01); // Clear screen
  delay(2);
  setCursor(0, 0);
  printToLCD("DHT11 Reading:");
  setCursor(1, 0);
  printToLCD(buffer);
 } else {
  sendCommand(0x01); // Clear screen
  delay(2);
  setCursor(0, 0);
  printToLCD("Checksum error");
 }

 delay(2000); // Wait before next read
}

// ========== LCD  Functions ==========

void write4bits(byte nibble) {
 digitalWrite(D4, (nibble >> 0) & 0x01);
 digitalWrite(D5, (nibble >> 1) & 0x01);
 digitalWrite(D6, (nibble >> 2) & 0x01);
 digitalWrite(D7, (nibble >> 3) & 0x01);
 pulseEnable();
}

void pulseEnable() {
 digitalWrite(E, LOW);
 delayMicroseconds(1);
 digitalWrite(E, HIGH);
 delayMicroseconds(1);
 digitalWrite(E, LOW);
 delayMicroseconds(100);
}

void sendCommand(byte cmd) {
 digitalWrite(RS, LOW);
 write4bits(cmd >> 4);
 write4bits(cmd & 0x0F);
 delay(2);
}

void sendData(byte data) {
 digitalWrite(RS, HIGH);
 write4bits(data >> 4);
 write4bits(data & 0x0F);
 delayMicroseconds(100);
}

void printToLCD(const char* str) {
 while (*str) {
  sendData(*str++);
 }
}

void setCursor(int row, int col) {
 byte addr = col + (row == 0 ? 0x00 : 0x40);
 sendCommand(0x80 | addr);
}