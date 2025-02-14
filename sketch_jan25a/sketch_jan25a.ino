#include <SoftwareSerial.h>
#include <RoboClaw.h>

#define address1 0x80
#define address2 0x81

SoftwareSerial serial1(10, 11);
SoftwareSerial serial2(9, 8);
RoboClaw roboclaw1(&serial1, 10000);
RoboClaw roboclaw2(&serial2, 10000);

uint8_t data[4] = { 0, 0, 0, 0 };

void setup() {
  roboclaw1.begin(38400);
  roboclaw2.begin(38400);

  // USB Serial
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    Serial.readBytes(data, 4);
  }

  // Echo the processed bytes
  Serial.write(data, 4);
  Serial.println();

  if (data[0] >= 0) {
    roboclaw1.ForwardM1(address1, data[0]);
  } else {
    roboclaw1.BackwardM1(address1, 64 - data[0]);
  }

  if (data[1] >= 0) {
    roboclaw1.ForwardM2(address1, data[1]);
  } else {
    roboclaw1.BackwardM2(address1, 64 - data[1]);
  }

  if (data[2] >= 0) {
    roboclaw2.ForwardM1(address2, data[2]);
  } else {
    roboclaw2.BackwardM1(address2, 64 - data[2]);
  }

  if (data[3] >= 0) {
    roboclaw2.ForwardM2(address2, data[3]);
  } else {
    roboclaw2.BackwardM2(address2, 64 - data[3]);
  }
}
