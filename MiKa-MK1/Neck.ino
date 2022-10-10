
Servo m_neck;  // create servo object to control a servo

int neck_pos = 0;    // variable to store the servo neck_position
int neck_rest_pos = 90;    // variable to store the servo neck_position

void neck_up()
 {
  for (neck_pos; neck_pos <= 120; neck_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   m_neck.write(neck_pos);              // tell servo to go to neck_position in variable 'neck_pos'
    delay(10);                       // waits 15ms for the servo to reach the neck_position
  }
 }

void neck_down()
{
  for (neck_pos; neck_pos >=0; neck_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   m_neck.write(neck_pos);              // tell servo to go to neck_position in variable 'neck_pos'
    delay(10);                       // waits 15ms for the servo to reach the neck_position
  }
  }
  
void neck_rest()
{
    if (neck_pos>neck_rest_pos)
    {
       for (neck_pos; neck_pos >=neck_rest_pos; neck_pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   m_neck.write(neck_pos);              // tell servo to go to neck_position in variable 'neck_pos'
    delay(10);                       // waits 15ms for the servo to reach the neck_position
  } 
    }
    else
    {
        for (neck_pos; neck_pos <= neck_rest_pos; neck_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   m_neck.write(neck_pos);              // tell servo to go to neck_position in variable 'neck_pos'
    delay(10);                       // waits 15ms for the servo to reach the neck_position
  }
    }
  }

void setup_neck() {
     m_neck.attach(26);  // attaches the servo on pin 9 to the servo object
    }
   
