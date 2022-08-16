

//pin 4 shoulder up 10- 70
//pin3 bicep rotate 10-90
//pin2  bicep updown 10-81
//pin5 should rotate

#include <Servo.h>

Servo Sholud_UP;  // create servo object to control a servo
Servo Sholud_Rot;  // create servo object to control a servo
Servo BIcep_Rot;  // create servo object to control a servo
Servo BIcep_Up;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int Shld_Pos = 10;    // variable to store the servo position
int Bi_Rot_Pos = 10;    // variable to store the servo position
int BIcep_Up_pos = 10;    // variable to store the servo position
int BIcep_Rot_pos = 30;    // variable to store the servo position
int Shld_Rot_Pos = 0;    // variable to store the servo position
int pos6 = 70;    // variable to store the servo position

void Shld_Rot_Clk()
{    
  Sholud_Rot.attach(5);  // shoulder updown
  //  Sholud_Rot.attach(10);  // shoulder updown

  
  for (Shld_Rot_Pos=10; Shld_Rot_Pos <=50; Shld_Rot_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sholud_Rot.write(Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }
  
void Shld_Rot_Anti()
{

  Sholud_Rot.attach(5);  // shoulder updown
  //  Sholud_Rot.attach(10);  // shoulder updown

    for (Shld_Rot_Pos=50; Shld_Rot_Pos >=10; Shld_Rot_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sholud_Rot.write(Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }

void Shld_Up()
{    
  Sholud_UP.attach(4);  // shoulder updown
   // Sholud_UP.attach(11);  // shoulder updown

  
  
  for (Shld_Pos; Shld_Pos <=70; Shld_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }
  
void Shld_Dwn()
{

  Sholud_UP.attach(4);  // shoulder updown
   // Sholud_UP.attach(11);  // shoulder updown

    for (Shld_Pos=70; Shld_Pos >=15; Shld_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }

  
void Bi_Rot_Clk()
{
   BIcep_Rot.attach(3);  // shoulder updown
   //    BIcep_Rot.attach(9);  // shoulder updown

    for (BIcep_Rot_pos=60; BIcep_Rot_pos <=90; BIcep_Rot_pos += 1) { 
          // in steps of 1 degree
          BIcep_Rot.write(BIcep_Rot_pos);              
          delay(15);                       // waits 15ms for the servo to reach the position
          }

  }
  

void Bi_Rot_Anti()
{
  BIcep_Rot.attach(3);  // shoulder updown
  //BIcep_Rot.attach(9);  // shoulder updown

    for (BIcep_Rot_pos=90; BIcep_Rot_pos >=60; BIcep_Rot_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Rot.write(BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }
  }


void Bi_Up()

{
    BIcep_Up.attach(2);  // shoulder updown
   // BIcep_Up.attach(8);  // shoulder updown

    for (BIcep_Up_pos=5; BIcep_Up_pos <=80; BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }

  }
  

void Bi_Dwn()

{
  
    BIcep_Up.attach(2);  // shoulder updown
     //   BIcep_Up.attach(8);  // shoulder updown

    for (BIcep_Up_pos=80; BIcep_Up_pos >=5; BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }

  
  }

void namste_leftarm()
  {
      Bi_Up();
      delay(500);
      Shld_Rot_Clk();
      delay(500);
      Bi_Rot_Anti();
    
    }

void namste_leftarm_reset()
  {
      Bi_Dwn();
      delay(500);
      Shld_Rot_Anti();
      delay(500);
      Bi_Rot_Clk();
    
    }

    
void setup() {
    Serial.begin(9600);
 

  //Shld_Up();
  //Shld_Dwn();
  
  //Bi_Rot_Clk();
  //Bi_Rot_Anti();
  
  //Bi_Up();
  //Bi_Dwn();
  
  //Shld_Rot_Clk();
  //Shld_Rot_Anti();

     // delay(500);

//namste_leftarm();

//namste_leftarm_reset();
 
}

void loop() {

  

  }
