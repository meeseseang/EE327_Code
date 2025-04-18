// Define LCD pins
#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

// Initialize DPS310 library
#include <Adafruit_DPS310.h>
Adafruit_DPS310 dps;
Adafruit_Sensor *dps_temp = dps.getTemperatureSensor();
Adafruit_Sensor *dps_pressure = dps.getPressureSensor();
float startAlt;
float calibratedAlt;

void setup(){
  Serial.begin(115200); // Start the serial console
  pinMode(E, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

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

  if(! dps.begin_I2C()) {
    Serial.println("Failed to find DPS");
    while(1) yield();
  }
  Serial.println("DPS OK");

  // Setup highest precision
  dps.configurePressure(DPS310_64HZ, DPS310_64SAMPLES);
  dps.configureTemperature(DPS310_64HZ, DPS310_64SAMPLES);

  dps_temp->printSensorDetails();
  dps_pressure->printSensorDetails();
  delay(1500);

  // Relative altitude calibration
  for(int i=0;i<5;i++){
    sensors_event_t temp_event, pressure_event;
    startAlt += (44330*(1-pow((pressure_event.pressure/1013.25),(1/5.255))));
    Serial.print("Start alt value: ");
    Serial.println(startAlt);
    delay(50);
  }
  calibratedAlt = startAlt / 5.0;
  Serial.print("Calibrated altitude: ");
  Serial.println(calibratedAlt);
  delay(1250);
}

void loop(){
  sensors_event_t temp_event, pressure_event;
  dps_temp->getEvent(&temp_event);
  Serial.print("Temp(C): ");
  Serial.print(temp_event.temperature);
  dps_pressure->getEvent(&pressure_event);
  Serial.print(", Pressure(hPa): ");
  Serial.print(pressure_event.pressure); //hPa
  Serial.print(", Altitude(m): ");
  double alt = ((44330*(1-pow((pressure_event.pressure/1013.25),(1/5.255)))) - calibratedAlt)*100;
  Serial.print(alt);
  Serial.println("");

  sendCommand(0x01);
  delay(2);
  setCursor(0, 0);
  printToLCD("Temp(C):");
  char buffer[8];
  printToLCD(dtostrf(temp_event.temperature, 1, 2, buffer));
  setCursor(1,0);
  printToLCD("Alt(cm):");
  char buffer2[8];
  printToLCD(dtostrf(alt, 1, 0, buffer2));
  delay(100);
}

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