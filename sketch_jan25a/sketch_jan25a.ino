//Roboclaw simple serial example.  Set mode to 6.  Option to 4(38400 bps)
#include <SoftwareSerial.h>

//See limitations of Arduino SoftwareSerial

SoftwareSerial serial1(10, 11);
SoftwareSerial serial2(9, 8);

uint8_t data[4] = {0,0,0,0}  

void setup() {
  serial1.begin(38400);
  serial2.begin(38400);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()) {
    Serial.readBytes(data, 4);
    }
    
   serial1.write(data[0]);
   serial1.write(data[1]);
   serial2.write(data[2]);
   serial2.write(data[3]);
}
