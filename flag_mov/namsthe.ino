
Servo L_Sholud_UP;  // create servo object to control a servo
Servo L_Sholud_Rot;  // create servo object to control a servo
Servo L_BIcep_Rot;  // create servo object to control a servo
Servo L_BIcep_Up;  // create servo object to control a servo


void Shld_Rot_Clk()
{    
  L_Sholud_Rot.attach(5);  // shoulder updown
  R_Sholud_Rot.attach(10);  // shoulder updown

  
  for (Shld_Rot_Pos=10; Shld_Rot_Pos <=60; Shld_Rot_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Sholud_Rot.write(Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
        R_Sholud_Rot.write(Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }
  
void Shld_Rot_Anti()
{

  L_Sholud_Rot.attach(5);  // shoulder updown
    R_Sholud_Rot.attach(10);  // shoulder updown

    for (Shld_Rot_Pos=60; Shld_Rot_Pos >=20; Shld_Rot_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Sholud_Rot.write(Shld_Rot_Pos); 
        R_Sholud_Rot.write(Shld_Rot_Pos);              // tell servo to go to position in variable 'pos'
// tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }

void Shld_Up()
{    
  L_Sholud_UP.attach(4);  // shoulder updown
    R_Sholud_UP.attach(11);  // shoulder updown

  
  
  for (Shld_Pos; Shld_Pos <=70; Shld_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'
        R_Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }
  
void Shld_Dwn()
{

  L_Sholud_UP.attach(4);  // shoulder updown
    R_Sholud_UP.attach(11);  // shoulder updown

    for (Shld_Pos=70; Shld_Pos >=15; Shld_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        L_Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'
        R_Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }

  
void Bi_Rot_Clk()
{
   L_BIcep_Rot.attach(3);  // shoulder updown
       R_BIcep_Rot.attach(9);  // shoulder updown

    for (BIcep_Rot_pos=60; BIcep_Rot_pos <=90; BIcep_Rot_pos += 1) { 
          // in steps of 1 degree
          L_BIcep_Rot.write(BIcep_Rot_pos);              
          R_BIcep_Rot.write(BIcep_Rot_pos);              
     
          delay(15);                       // waits 15ms for the servo to reach the position
          }

  }
  

void Bi_Rot_Anti()
{
  L_BIcep_Rot.attach(3);  // shoulder updown
  R_BIcep_Rot.attach(9);  // shoulder updown

    for (BIcep_Rot_pos=90; BIcep_Rot_pos >=60; BIcep_Rot_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          L_BIcep_Rot.write(BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
          R_BIcep_Rot.write(BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'

          delay(15);                       // waits 15ms for the servo to reach the position
          }
  }


void Bi_Up()

{
    L_BIcep_Up.attach(2);  // shoulder updown
    R_BIcep_Up.attach(8);  // shoulder updown

    for (BIcep_Up_pos=10; BIcep_Up_pos <=60; BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          L_BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          R_BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
    
          delay(15);                       // waits 15ms for the servo to reach the position
          }

  }
  

void Bi_Dwn()

{
  
    L_BIcep_Up.attach(2);  // shoulder updown
    R_BIcep_Up.attach(8);  // shoulder updown

    for (BIcep_Up_pos=60; BIcep_Up_pos >=10; BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          L_BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          R_BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'

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
      delay(3000);
    
    }

    
