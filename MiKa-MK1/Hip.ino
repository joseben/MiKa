

Servo hip;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int hip_pos = 105;    // 105 balance 
int hip_rest_pos = 105;    // 105 balance 

void hip_turn_left()
{
  
  for (hip_pos ; hip_pos >= 40; hip_pos -= 1) { // goes from 180 degrees to 0 degrees
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
   delay(15); 
   
  }
}

void hip_turn_right()
{
  for (hip_pos ; hip_pos <= 160; hip_pos += 1) { // goes from 180 degrees to 0 degrees
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
   delay(15);                       // waits 15ms for the servo to reach the hip_position
 }
  
}

void hip_rest()
{
    if (hip_pos>hip_rest_pos)
    {
       for (hip_pos; hip_pos >=hip_rest_pos; hip_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
    delay(10);                       // waits 15ms for the servo to reach the hip_position
  } 
    }
    else
    {
        for (hip_pos; hip_pos <= hip_rest_pos; hip_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   hip.write(hip_pos);              // tell servo to go to hip_position in variable 'hip_pos'
    delay(10);                       // waits 15ms for the servo to reach the hip_position
  }
    }
  }


void setup_hip() {
  hip.attach(29);  // attaches the servo on pin 9 to the servo object

  }
