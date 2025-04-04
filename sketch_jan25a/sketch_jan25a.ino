//Roboclaw simple serial example.  Set mode to 6.  Option to 4(38400 bps)
#include <SoftwareSerial.h>

//See limitations of Arduino SoftwareSerial

SoftwareSerial serial1(10, 11);
SoftwareSerial serial2(9, 8);
SoftwareSerial serial3(7, 13);

uint8_t data[8] = {0,0,0,0,0,0, 0, 0}; 

void setup() {
  serial1.begin(38400);
  serial2.begin(38400);
  serial3.begin(38400);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() >= 8) {
    Serial.readBytes(data, 8);
    }
    
      serial1.write(data[0]);
      serial1.write(data[1]);
      serial2.write(data[2]);
      serial2.write(data[3]);

      if(data[4] > 0){
        serial3.write(120);
      }else if(data[5] > 0){
        serial3.write(10);
      }else{
        serial3.write(64);
      }

      if(data[6] > 0){
        serial3.write(150);
      }else if(data[7] > 0){
        serial3.write(240);
      }else{
        serial3.write(192);
      }
}
