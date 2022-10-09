#include <Servo.h>

Servo gripper;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  gripper.attach(30);  // attaches the servo on pin 9 to the servo object
}

int grip_pos;
void loop() {
  open_hand();
  //close_hand();
}

void open_hand(){
  grip_pos=0;
  gripper.write(grip_pos);
  }

void close_hand(){
  grip_pos=90;
  gripper.write(grip_pos);
  }
