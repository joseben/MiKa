#include <PWMServo.h>

PWMServo m_neck;  // create PWMServo object to control a PWMServo


int pos = 80;    // variable to store the PWMServo position

void neck_up()
 {
     m_neck.attach(33);  

  for (pos; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   m_neck.write(pos);             
    delay(10);                      
  }
 }

void neck_down()
{
     m_neck.attach(33);  

  for (pos; pos >=80; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   m_neck.write(pos);              
    delay(10);                       
  }

}
