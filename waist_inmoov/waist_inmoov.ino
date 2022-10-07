/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo waist;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 105;    // 105 balance 

void left()
{
  
  for (pos ; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
   waist.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15); 
   
  }
}

void right()
{
  for (pos ; pos <= 160; pos += 1) { // goes from 180 degrees to 0 degrees
   waist.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
 }
  
}

void setup() {
  waist.attach(30);  // attaches the servo on pin 9 to the servo object

  }

void loop() {

left();
delay(2000);
right();
delay(2000);

}
