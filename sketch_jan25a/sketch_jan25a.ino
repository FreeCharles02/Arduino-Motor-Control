//Roboclaw simple serial example.  Set mode to 6.  Option to 4(38400 bps)
#include <SoftwareSerial.h>

//See limitations of Arduino SoftwareSerial

SoftwareSerial serial1(10, 11);
SoftwareSerial serial2(9, 8);

 int32_t data[4] = {0,0,0,0}; 

void setup() {
  serial1.begin(38400);
  serial2.begin(38400);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() >= 16) {
    Serial.readBytes((uint8_t*)data, 16);
    }
    
      serial1.write((uint8_t*)&data[0], 4);
      serial1.write((uint8_t*)&data[1], 4);
      serial2.write((uint8_t*)&data[2], 4);
      serial2.write((uint8_t*)&data[3], 4);
}
