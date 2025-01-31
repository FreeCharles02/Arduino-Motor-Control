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
const size_t dataLength = 4;
byte data[dataLength];


void setup() {
  
  roboclaw.begin(38400);
  roboclaw2.begin(38400);
  serial.begin(9600);

}

void loop() {
if (Serial.available()) {
  Serial.readBytes(data, 4);
}

 roboclaw.ForwardBackwardM1(address, data[0]);
 roboclaw.ForwardBackwardM2(address, data[1]);
 roboclaw2.ForwardBackwardM1(address2, data[2]);
 roboclaw2.ForwardBackwardM2(address2, data[3]);

}

/*void setSpeed(int m1Speed, int m2Speed, int m3Speed, int m4Speed) {
  for(int i = 0; i < sizeof(data); i++) {
  data[0] = m1Speed;
  data[1] = m2Speed;
  data[2] = m3Speed;
  data[3] = m4Speed;
  }
} */

