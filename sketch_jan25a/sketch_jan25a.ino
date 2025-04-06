//Roboclaw simple serial example.  Set mode to 6.  Option to 4(38400 bps)
#include <SoftwareSerial.h>

//See limitations of Arduino SoftwareSerial

SoftwareSerial serial1(10, 11);
SoftwareSerial serial2(9, 8);
SoftwareSerial serial3(7, 13);
SoftwareSerial serial4(6,2);

uint8_t data[10] = {0,0,0,0,0,0, 0, 0,0,0}; 

void setup() {
  serial1.begin(38400);
  serial2.begin(38400);
  serial3.begin(38400);
  serial4.begin(38400);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() >= 10) {
    Serial.readBytes(data, 10);
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

      if (data[8] > 0) {
        serial4.write(150);
        } else if(data[9] > 0){
          serial4.write(220);
        } else {
          serial4.write(192);
        }
      
}
