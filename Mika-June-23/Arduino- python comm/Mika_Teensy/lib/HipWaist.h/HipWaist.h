#include <PWMServo.h>


PWMServo waist;  // create servo object to control a servo
PWMServo hip;  // create servo object to control a servo


// twelve servo objects can be created on most boards

int hip_pos = 105;    // 105 balance 
int hip_rest_pos = 105;    // 105 balance 

void hip_turn_left()
{
  
  for (hip_pos ; hip_pos >= 60; hip_pos -= 1) { // goes from 180 degrees to 0 degrees
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
   delay(15);
   
  }
}

void hip_turn_right()
{
  for (hip_pos ; hip_pos <= 150; hip_pos += 1) { // goes from 180 degrees to 0 degrees
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
   delay(15);                      // waits 15ms for the servo to reach the hip_position
 }
  
}

void hip_rest()
{
    if (hip_pos>hip_rest_pos)
    {
       for (hip_pos; hip_pos >=hip_rest_pos; hip_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
    delay(10);                      // waits 15ms for the servo to reach the hip_position
  } 
    }
    else
    {
        for (hip_pos; hip_pos <= hip_rest_pos; hip_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
    delay(10);                      // waits 15ms for the servo to reach the hip_position
  }
    }
  }


void setup_hip() {
  
  }

int waist_pos = 80;    // 80 balance 
int waist_rest_pos = 80;    // 80 balance 

void waist_left_up()
{
  
  for (waist_pos ; waist_pos >= 60; waist_pos -= 1) { // goes from 180 degrees to 0 degrees
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
   delay(15);
   
  }
}

void waist_right_up()
{
  for (waist_pos ; waist_pos <= 100; waist_pos += 1) { // goes from 180 degrees to 0 degrees
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
   delay(15);                      // waits 15ms for the servo to reach the waist_position
 }
  
}


void hipWaisitReset()
{
    if (waist_pos>waist_rest_pos)
    {
       for (waist_pos; waist_pos >=waist_rest_pos; waist_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
    delay(10);                      // waits 15ms for the servo to reach the waist_position
  } 
    }
    else
    {
        for (waist_pos; waist_pos <= waist_rest_pos; waist_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
    delay(10);                      // waits 15ms for the servo to reach the waist_posyition
  }
    }
  }
  

void hipWaistInit() {
  waist.attach(24);  
   hip.attach(25);  
hip_turn_right();
      delay(2000);

hip_turn_left();
      delay(2000);
hip_rest();

            delay(2000);

waist_left_up();
      delay(2000);

waist_right_up();
           delay(2000);

hipWaisitReset();
  }

  