

Servo left_gripper;  // create servo object to control a servo
Servo right_gripper;  // create servo object to control a servo


void setup_gripper() {
  left_gripper.attach(30);  // attaches the servo on pin 9 to the servo object
  right_gripper.attach(30);  // attaches the servo on pin 9 to the servo object
}

int grip_pos;

void left_open_hand(){
  grip_pos=0;
  left_gripper.write(grip_pos);
  }

void left_close_hand(){
  grip_pos=90;
  left_gripper.write(grip_pos);
  }

void right_open_hand(){
  grip_pos=0;
  right_gripper.write(grip_pos);
  }

void right_close_hand(){
  grip_pos=90;
  right_gripper.write(grip_pos);
  }
