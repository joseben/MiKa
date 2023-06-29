#include <PWMServo.h>

PWMServo Nam_L_Sholud_Rot;  // create servo object to control a servo
PWMServo Nam_L_BIcep_Rot;  // create servo object to control a servo
PWMServo Nam_L_BIcep_Up;  // create servo object to control a servo

PWMServo Nam_R_Sholud_Rot;  // create servo object to control a servo
PWMServo Nam_R_BIcep_Rot;  // create servo object to control a servo
PWMServo Nam_R_BIcep_Up;  // create servo object to control a servo
PWMServo Nam_Sholud_UP;  // create servo object to control a servo

int Nam_Shld_Pos = 10;    // variable to store the servo position
int Nam_Bi_Rot_Pos = 10;    // variable to store the servo position
int Nam_BIcep_Up_pos = 10;    // variable to store the servo position
int Nam_BIcep_Rot_pos = 30;    // variable to store the servo position
int Nam_Shld_Rot_Pos = 0;    // variable to store the servo position

void Nam_Shld_Rot_Clk()
{    
  Nam_L_Sholud_Rot.attach(2);  // shoulder updown
  Nam_R_Sholud_Rot.attach(8);  // shoulder updown

  
  for (Nam_Shld_Rot_Pos=10; Nam_Shld_Rot_Pos <=60; Nam_Shld_Rot_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Nam_L_Sholud_Rot.write(Nam_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        Nam_R_Sholud_Rot.write(Nam_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);
                       // waits 15ms for the servo to reach the position
        }
  }
  
void Nam_Shld_Rot_Anti()
{

  Nam_L_Sholud_Rot.attach(2);  // shoulder updown
    Nam_R_Sholud_Rot.attach(8);  // shoulder updown

    for (Nam_Shld_Rot_Pos=60; Nam_Shld_Rot_Pos >=10; Nam_Shld_Rot_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Nam_L_Sholud_Rot.write(Nam_Shld_Rot_Pos); 
        Nam_R_Sholud_Rot.write(Nam_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
// tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
        }
  }


  
void Nam_Bi_Rot_Clk()
{
   Nam_L_BIcep_Rot.attach(5);  // shoulder updown
       Nam_R_BIcep_Rot.attach(11);  // shoulder updown

    for (Nam_BIcep_Rot_pos=60; Nam_BIcep_Rot_pos <=90; Nam_BIcep_Rot_pos += 1) { 
          // in steps of 1 degree
          Nam_L_BIcep_Rot.write(Nam_BIcep_Rot_pos);              
          Nam_R_BIcep_Rot.write(Nam_BIcep_Rot_pos);              
        delay(15);

                     // waits 15ms for the servo to reach the position
          }

  }
  

void Nam_Bi_Rot_Anti()
{
  Nam_L_BIcep_Rot.attach(5);  // shoulder updown
  Nam_R_BIcep_Rot.attach(11);  // shoulder updown

    for (Nam_BIcep_Rot_pos=90; Nam_BIcep_Rot_pos >=60; Nam_BIcep_Rot_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Nam_L_BIcep_Rot.write(Nam_BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
          Nam_R_BIcep_Rot.write(Nam_BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
          }
  }


void Nam_Bi_Up()

{
    Nam_L_BIcep_Up.attach(4);  // shoulder updown
    Nam_R_BIcep_Up.attach(10);  // shoulder updown

    for (Nam_BIcep_Up_pos=5; Nam_BIcep_Up_pos <=60; Nam_BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Nam_L_BIcep_Up.write(Nam_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          Nam_R_BIcep_Up.write(Nam_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                     // waits 15ms for the servo to reach the position
          }

  }
  

void Nam_Bi_Dwn()

{
  
    Nam_L_BIcep_Up.attach(4);  // shoulder updown
    Nam_R_BIcep_Up.attach(10);  // shoulder updown

    for (Nam_BIcep_Up_pos=60; Nam_BIcep_Up_pos >=5; Nam_BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          Nam_L_BIcep_Up.write(Nam_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          Nam_R_BIcep_Up.write(Nam_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
        delay(15);

                       // waits 15ms for the servo to reach the position
          }
}

void namastheReset()
  {
      Nam_Bi_Dwn();
      Nam_Shld_Rot_Anti();
      Nam_Bi_Rot_Clk();
    
    }

void namasthe()
  {
      Nam_Bi_Up();
      Nam_Shld_Rot_Clk();
      Nam_Bi_Rot_Anti();
      delay(7000);
      namastheReset();
    }

