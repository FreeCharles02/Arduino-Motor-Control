#include <SoftwareSerial.h>
#include <RoboClaw.h>


SoftwareSerial serial(10, 11);  
SoftwareSerial serial2(9, 8);   


RoboClaw roboclaw(&serial, 10000);  
RoboClaw roboclaw2(&serial2, 10000);


#define address 0x80  
#define address2 0x81  
int m1Speed;
int m2Speed;
int m3Speed;
int m4Speed;
uint8_t data[4] = {0,0,0,0};


void setup() {
  
  roboclaw.begin(38400);
  roboclaw2.begin(38400);
  Serial.begin(9600);

}

void loop() {
if (Serial.available()) {
   Serial.readBytes(data, 4);
}

if ( data[0] >= 0) {
  m1Speed = data[0];
 roboclaw.ForwardM1(address, data[0]);
 Serial.write(data[0]);
} else {
  data[0] = -data[0];
  roboclaw.BackwardM1(address, data[0]);
}

if ( data[1] >= 0) {
 roboclaw.ForwardM2(address, data[1]);
 Serial.write(data[1]);
} else {
  data[1] = -data[1];
  roboclaw.BackwardM2(address, data[1]);
}

if ( data[2] >= 0) {
 roboclaw2.ForwardM1(address2, data[2]);
 Serial.write(data[2]);
} else {
  data[2] = -data[2];
  roboclaw2.BackwardM1(address2, data[2]);
}

if ( data[3] >= 0) {
 roboclaw2.ForwardM2(address2, data[3]);
  Serial.write(data[3]);
} else {
  data[3] = -data[3];
  roboclaw2.BackwardM2(address2, data[3]);
  
}

Serial.println();

}