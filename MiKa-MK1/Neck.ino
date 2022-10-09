/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo m_neck;  // create servo object to control a servo


// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void neck_up()
 {
  for (pos; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  
   m_neck.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
 }

void neck_down()
{
  for (pos; pos >=0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   m_neck.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  }


void setup() {
 m_neck.attach(26);  // attaches the servo on pin 9 to the servo object


  //neck_rest();
  //delay(1000);
  //m_neck.write();              // tell servo to go to position in variable 'pos'


}
   
void loop() {
  neck_up();
  delay(500);
  neck_down();
  delay(500);

}
