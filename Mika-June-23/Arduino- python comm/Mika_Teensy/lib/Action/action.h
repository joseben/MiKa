#include <PWMServo.h>

PWMServo Act_R_Act_Sholud_UP;  
PWMServo Act_R_Sholud_Rot;  
PWMServo Act_R_BIcep_Rot;  
PWMServo Act_R_BIcep_Up;  

PWMServo Act_L_Act_Sholud_UP;  
PWMServo Act_L_Sholud_Rot;  
PWMServo Act_L_BIcep_Rot;  
PWMServo Act_L_BIcep_Up;  
PWMServo Act_Sholud_UP;  
PWMServo L_Gripper; 
PWMServo R_Gripper;  
 
PWMServo Act_waist;  
PWMServo Act_hip;  
PWMServo Act_m_neck;  // create PWMServo object to control a PWMServo


int Act_Gripper_pos = 0;    // variable to store the servo position



int Act_Act_hip_pos = 105;    // 105 balance 
int Act_Act_hip_rest_pos = 105;    // 105 balance 
int Act_waist_pos = 80;    // 80 balance 
int Act_waist_rest_pos = 80;    // 80 balance 
int Act_pos = 80;    // variable to store the PWMServo position


int Act_Shld_Pos = 10;    
int Act_Bi_Rot_Pos = 10;    
int Act_BIcep_Up_pos = 10;    
int Act_BIcep_Rot_pos = 30;    
int Act_Shld_Rot_Pos = 0;    


void Act_Shld_Rot_Clk()
{    
    Act_L_Sholud_Rot.attach(2);  // shoulder updown
    Act_R_Sholud_Rot.attach(8);  // shoulder updown

    for (Act_Shld_Rot_Pos=10; Act_Shld_Rot_Pos <=30; Act_Shld_Rot_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Act_L_Sholud_Rot.write(Act_Shld_Rot_Pos);      
        Act_R_Sholud_Rot.write(Act_Shld_Rot_Pos);        // tell servo to go to position in variable 'pos'
    delay(15);
    }
}
  
void Act_Shld_Rot_Anti()
{

    Act_L_Sholud_Rot.attach(2);  // shoulder updown
    Act_R_Sholud_Rot.attach(8);  // shoulder updown

    for (Act_Shld_Rot_Pos=30; Act_Shld_Rot_Pos >=10; Act_Shld_Rot_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Act_L_Sholud_Rot.write(Act_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        Act_R_Sholud_Rot.write(Act_Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }

}
  


void Act_Bi_Up()

{
    Act_L_BIcep_Up.attach(4);  // shoulder updown
    Act_R_BIcep_Up.attach(10);  // shoulder updown

    for (Act_BIcep_Up_pos=5; Act_BIcep_Up_pos <=40; Act_BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Act_L_BIcep_Up.write(Act_BIcep_Up_pos);   
        Act_R_BIcep_Up.write(Act_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
    delay(15);

  }
} 

void Act_Bi_Dwn()

{
  
    Act_L_BIcep_Up.attach(4);  // shoulder updown
    Act_R_BIcep_Up.attach(10);  // shoulder updown

    for (Act_BIcep_Up_pos=40; Act_BIcep_Up_pos >=5; Act_BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            Act_L_BIcep_Up.write(Act_BIcep_Up_pos);     
            Act_R_BIcep_Up.write(Act_BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
    delay(15);
}
}
void Act_Gripper_Close()

{

    L_Gripper.attach(6);  // shoulder updown
    R_Gripper.attach(12);  // shoulder updown

    for (Act_Gripper_pos=60; Act_Gripper_pos <=120; Act_Gripper_pos += 1) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            L_Gripper.write(Act_Gripper_pos);     
            R_Gripper.write(Act_Gripper_pos);              // tell servo to go to position in variable 'pos'
    delay(15);
}
}
void Act_Gripper_Open()

{
  
    L_Gripper.attach(6);  // shoulder updown
    R_Gripper.attach(12);  // shoulder updown

    for (Act_Gripper_pos=120; Act_Gripper_pos >=60; Act_Gripper_pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Gripper.write(Act_Gripper_pos);      
        R_Gripper.write(Act_Gripper_pos);              // tell servo to go to position in variable 'pos'
    delay(15);
}
}


////////////////////////////////
////////////////////////////////



void Act_Act_hip_turn_left()
{
  
  for (Act_Act_hip_pos ; Act_Act_hip_pos >= 85; Act_Act_hip_pos -= 1) { // goes from 180 degrees to 0 degrees
   Act_hip.write(Act_Act_hip_pos);              // tell servo to go to Act_Act_hip_position in variable 'Act_Act_hip_pos'
   delay(15);
   
  }
}

void Act_Act_hip_turn_right()
{
  for (Act_Act_hip_pos ; Act_Act_hip_pos <= 125; Act_Act_hip_pos += 1) { // goes from 180 degrees to 0 degrees
   Act_hip.write(Act_Act_hip_pos);              // tell servo to go to Act_Act_hip_position in variable 'Act_Act_hip_pos'
   delay(15);                      // waits 15ms for the servo to reach the Act_Act_hip_position
 }
  
}

void Act_Act_hip_rest()
{
    if (Act_Act_hip_pos>Act_Act_hip_rest_pos)
    {
       for (Act_Act_hip_pos; Act_Act_hip_pos >=Act_Act_hip_rest_pos; Act_Act_hip_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   Act_hip.write(Act_Act_hip_pos);              // tell servo to go to Act_Act_hip_position in variable 'Act_Act_hip_pos'
    delay(10);                      // waits 15ms for the servo to reach the Act_Act_hip_position
  } 
    }
    else
    {
        for (Act_Act_hip_pos; Act_Act_hip_pos <= Act_Act_hip_rest_pos; Act_Act_hip_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   Act_hip.write(Act_Act_hip_pos);              // tell servo to go to Act_Act_hip_position in variable 'Act_Act_hip_pos'
    delay(10);                      // waits 15ms for the servo to reach the Act_Act_hip_position
  }
    }
  }


void Act_setup_Act_hip() {
  
  }



void Act_Act_waist_left_up()
{
  
  for (Act_waist_pos ; Act_waist_pos >= 70; Act_waist_pos -= 1) { // goes from 180 degrees to 0 degrees
   Act_waist.write(Act_waist_pos);              // tell servo to go to Act_waist_position in variable 'Act_waist_pos'
   delay(15);
   
  }
}

void Act_Act_waist_right_up()
{
  for (Act_waist_pos ; Act_waist_pos <= 90; Act_waist_pos += 1) { // goes from 180 degrees to 0 degrees
   Act_waist.write(Act_waist_pos);              // tell servo to go to Act_waist_position in variable 'Act_waist_pos'
   delay(15);                      // waits 15ms for the servo to reach the Act_waist_position
 }
  
}


void Act_Act_hipWaisitReset()
{
    if (Act_waist_pos>Act_waist_rest_pos)
    {
       for (Act_waist_pos; Act_waist_pos >=Act_waist_rest_pos; Act_waist_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   Act_waist.write(Act_waist_pos);              // tell servo to go to Act_waist_position in variable 'Act_waist_pos'
    delay(10);                      // waits 15ms for the servo to reach the Act_waist_position
  } 
    }
    else
    {
        for (Act_waist_pos; Act_waist_pos <= Act_waist_rest_pos; Act_waist_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   Act_waist.write(Act_waist_pos);              // tell servo to go to Act_waist_position in variable 'Act_waist_pos'
    delay(10);                      // waits 15ms for the servo to reach the Act_waist_posyition
  }
    }
  }
  

///////////////////////////////
////////////////////////////////


void Act_neck_up()
 {
     Act_m_neck.attach(33);  

  for (Act_pos; Act_pos <= 110; Act_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   Act_m_neck.write(Act_pos);             
    delay(10);                      
  }
 }

void Act_neck_down()
{
     Act_m_neck.attach(33);  

  for (Act_pos; Act_pos >=90; Act_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   Act_m_neck.write(Act_pos);              
    delay(10);                       
  }

}

void action()
{
    Act_waist.attach(24);  
    Act_hip.attach(25);
    int r=random(1,7);
    switch(r)
    {
        case 1: 
            Act_Gripper_Open();
            delay(800);
            Act_Gripper_Close();
            delay(500);
            Act_Gripper_Open();
            delay(800);
            Act_Gripper_Close();
            break;
        case 2:
            Act_Shld_Rot_Clk();
            delay(800);
            Act_Shld_Rot_Anti();
            delay(500);
            Act_Shld_Rot_Clk();
            delay(800);
            Act_Shld_Rot_Anti();
            break;
        case 3:
            Act_Bi_Up();
            delay(800);
            Act_Bi_Dwn();
            delay(500);
            Act_Bi_Up();
            delay(800);
            Act_Bi_Dwn();
            break;

        case 4:
            Act_Act_hip_turn_left();
            delay(800);
            Act_Act_hip_turn_right();
            delay(500);
            Act_Act_hip_turn_left();
            delay(800);
            Act_Act_hip_turn_right();
            delay(800);
            Act_Act_hip_rest();
            break;
        case 5:
            Act_Act_waist_left_up();
            delay(800);
            Act_Act_waist_right_up();         
            delay(500);
            Act_Act_waist_left_up();   
            delay(800);
            Act_Act_waist_right_up();
            delay(800);
            Act_Act_hipWaisitReset();
            break;

        case 6:
            Act_neck_up();
            delay(800);
            Act_neck_down();
            delay(800);
            Act_neck_up();
            break;
    }
    
    delay(1000);
    analogWrite(2,0);
    analogWrite(8,0);
    analogWrite(4,0);
    analogWrite(10,0);
    analogWrite(6 ,0);
    analogWrite(12,0);
    analogWrite(33,0);
    analogWrite(24,0);
    analogWrite(25,0);

}

  
