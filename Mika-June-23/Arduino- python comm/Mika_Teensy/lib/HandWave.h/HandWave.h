

//pin 11 shoulder up 10- 70
//pin10 bicep rotate 10-90
//pin 8 bicep updown 10-81

#include <PWMServo.h>

PWMServo Sholud_UP;  // create PWMServo object to control a PWMServo
PWMServo L_Sholud_Rot;  // create servo object to control a servo
PWMServo BIcep_Rot;  // create PWMServo object to control a PWMServo
PWMServo BIcep_Up;  // create PWMServo object to control a PWMServo
PWMServo gripper;  // create PWMServo object to control a PWMServo

// twelve PWMServo objects can be created on most boards

int Shld_Pos = 10;    // variable to store the PWMServo position
int Bi_Rot_Pos = 10;    // variable to store the PWMServo position
int BIcep_Up_pos = 10;    // variable to store the PWMServo position
int BIcep_Rot_pos = 30;    // variable to store the PWMServo position
int Shld_Rot_Pos = 0;    // variable to store the servo position
int grip_pos;

void Shld_Up()
{    
  Sholud_UP.attach(3);  // shoulder updown
  
  
  
  for (Shld_Pos=15; Shld_Pos <=60; Shld_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sholud_UP.write(Shld_Pos);              // tell PWMServo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the PWMServo to reach the position
        }
  }
  
void Shld_Dwn()
{

  Sholud_UP.attach(3);  // shoulder updown
  
    for (Shld_Pos=60; Shld_Pos >=15; Shld_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sholud_UP.write(Shld_Pos);              // tell PWMServo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the PWMServo to reach the position
        }
  }


void Shld_Rot_Clk()
{    
  L_Sholud_Rot.attach(2);  // shoulder updown

  
  for (Shld_Rot_Pos=10; Shld_Rot_Pos <=60; Shld_Rot_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Sholud_Rot.write(Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }
  
void Shld_Rot_Anti()
{

  L_Sholud_Rot.attach(2);  // shoulder updown

    for (Shld_Rot_Pos=60; Shld_Rot_Pos >=10; Shld_Rot_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Sholud_Rot.write(Shld_Rot_Pos); 
// tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }



void Bi_Rot_Clk()
{
   BIcep_Rot.attach(5);  // shoulder updown
    
    for (BIcep_Rot_pos=90; BIcep_Rot_pos <=170; BIcep_Rot_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Rot.write(BIcep_Rot_pos);              // tell PWMServo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the PWMServo to reach the position
          }

  }
  

void Bi_Rot_Anti()
{
  BIcep_Rot.attach(5);  // shoulder updown
    
    for (BIcep_Rot_pos=170; BIcep_Rot_pos >=90; BIcep_Rot_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Rot.write(BIcep_Rot_pos);              // tell PWMServo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the PWMServo to reach the position
          }
  }


void Bi_Up()

{
    BIcep_Up.attach(4);  // 8
    
    for (BIcep_Up_pos=10; BIcep_Up_pos <=75; BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Up.write(BIcep_Up_pos);              // tell PWMServo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the PWMServo to reach the position
          }

  }
  

void Bi_Dwn()

{
  
    BIcep_Up.attach(4);  // 8
    
    for (BIcep_Up_pos=75; BIcep_Up_pos >=20; BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Up.write(BIcep_Up_pos);              // tell PWMServo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the PWMServo to reach the position
          }

  
  }

  

void open_hand(){
  grip_pos=0;
  gripper.write(grip_pos);
  }

void close_hand(){
  grip_pos=90;
  gripper.write(grip_pos);
  }

void waveReset()
  {
      Shld_Rot_Anti();
      Bi_Dwn();
      delay(1000);
      Bi_Rot_Anti();
      delay(2000);
      Shld_Dwn();
      delay(3000);
      
    }  

void handWave()
  {
      
      Bi_Rot_Clk();
      delay(500);
      Shld_Up();
      delay(1000);
      
      Bi_Up();
      delay(800);
      Bi_Dwn();    
      delay(800);
      Bi_Up();
      delay(800);
      Bi_Dwn();    
      delay(800);      
      Bi_Up();
      delay(800);
      Bi_Dwn();    
      delay(800);      
      Bi_Up();
      delay(800);
      Bi_Dwn();    
      delay(800);      
      waveReset();

    }


    //Shld_Up();
    //Shld_Dwn();
    
    //Bi_Rot_Clk();
    //Bi_Rot_Anti();
    
    //Bi_Up();
    //Bi_Dwn();
    //
    //handWave();
    //waveRest();


