#include <PWMServo.h>

PWMServo Flow_R_Sholud_Rot;  // create servo object to control a servo
PWMServo Flow_R_BIcep_Rot;  // create servo object to control a servo
PWMServo Flow_R_BIcep_Up;  // create servo object to control a servo
PWMServo Flow_Sholud_UP;  // create servo object to control a servo
PWMServo Flow_Gripper;  // create servo object to control a servo


int Flow_Shld_Pos = 10;    // variable to store the servo position
int Flow_Bi_Rot_Pos = 10;    // variable to store the servo position
int Flow_BIcep_Up_pos = 10;    // variable to store the servo position
int Flow_BIcep_Rot_pos = 30;    // variable to store the servo position
int Flow_Shld_Rot_Pos = 0;    // variable to store the servo position
int Gripper_pos = 0;    // variable to store the servo position

void Flow_Shld_Rot_Clk()
{    
  Flow_R_Sholud_Rot.attach(2);  // shoulder updown

  
  for (Flow_Shld_Rot_Pos=10; Flow_Shld_Rot_Pos <=60; Flow_Shld_Rot_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Flow_R_Sholud_Rot.write(Flow_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
        }
  }
  
void Flow_Shld_Rot_Anti()
{

    Flow_R_Sholud_Rot.attach(2);  // shoulder updown

    for (Flow_Shld_Rot_Pos=60; Flow_Shld_Rot_Pos >=10; Flow_Shld_Rot_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Flow_R_Sholud_Rot.write(Flow_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
// tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
        }
  }


  
void Flow_Bi_Rot_Clk()
{
       Flow_R_BIcep_Rot.attach(5);  // shoulder updown

    for (Flow_BIcep_Rot_pos=60; Flow_BIcep_Rot_pos <=90; Flow_BIcep_Rot_pos += 1) { 
          // in steps of 1 degree
          Flow_R_BIcep_Rot.write(Flow_BIcep_Rot_pos);              
        delay(15);

                     // waits 15ms for the servo to reach the position
          }

  }
  

void Flow_Bi_Rot_Anti()
{
  Flow_R_BIcep_Rot.attach(5);  // shoulder updown

    for (Flow_BIcep_Rot_pos=90; Flow_BIcep_Rot_pos >=60; Flow_BIcep_Rot_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Flow_R_BIcep_Rot.write(Flow_BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
          }
  }


void Flow_Bi_Up()

{
    Flow_R_BIcep_Up.attach(4);  // shoulder updown

    for (Flow_BIcep_Up_pos=5; Flow_BIcep_Up_pos <=60; Flow_BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Flow_R_BIcep_Up.write(Flow_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                     // waits 15ms for the servo to reach the position
          }

  }
  

void Flow_Bi_Dwn()

{
  
    Flow_R_BIcep_Up.attach(4);  // shoulder updown

    for (Flow_BIcep_Up_pos=60; Flow_BIcep_Up_pos >=5; Flow_BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Flow_R_BIcep_Up.write(Flow_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
          }
}

void R_Gripper_Close()

{
  
    Flow_Gripper.attach(6);  // shoulder updown

    for (Gripper_pos=80; Gripper_pos <=120; Gripper_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Flow_Gripper.write(Gripper_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
          }
}

void R_Gripper_Open()

{
  
    Flow_Gripper.attach(6);  // shoulder updown

    for (Gripper_pos=120; Gripper_pos >=80; Gripper_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Flow_Gripper.write(Gripper_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
          }
}


void give()
  {
    //Flow_Bi_Up();
    R_Gripper_Open();
    delay(2000);
    R_Gripper_Close();
    delay(1000);
    Flow_Shld_Rot_Clk();
    delay(8000);
    R_Gripper_Open();

  }

void givereset()
  {
    //Flow_Bi_Dwn();
    Flow_Shld_Rot_Anti();
    R_Gripper_Close();

    }


void flower()
{

    give();
    delay(5000);
    givereset();

}
