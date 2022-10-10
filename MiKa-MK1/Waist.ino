
Servo waist;  // create servo object to control a servo

int waist_pos = 105;    // 105 balance 
int waist_rest_pos = 105;    // 105 balance 

void waist_left_up()
{
  
  for (waist_pos ; waist_pos >= 40; waist_pos -= 1) { // goes from 180 degrees to 0 degrees
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
   delay(15); 
   
  }
}

void waist_right_up()
{
  for (waist_pos ; waist_pos <= 160; waist_pos += 1) { // goes from 180 degrees to 0 degrees
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
   delay(15);                       // waits 15ms for the servo to reach the waist_position
 }
  
}


void waist_rest()
{
    if (waist_pos>waist_rest_pos)
    {
       for (waist_pos; waist_pos >=waist_rest_pos; waist_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
    delay(10);                       // waits 15ms for the servo to reach the waist_position
  } 
    }
    else
    {
        for (waist_pos; waist_pos <= waist_rest_pos; waist_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   waist.write(waist_pos);              // tell servo to go to waist_position in variable 'waist_pos'
    delay(10);                       // waits 15ms for the servo to reach the waist_posyition
  }
    }
  }
  

void setup_waist() {
  waist.attach(30);  // attaches the servo on pin 9 to the servo object

  }
