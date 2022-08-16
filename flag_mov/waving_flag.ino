
void flag_Shld_Up()
{    
  R_Sholud_UP.attach(11);  // shoulder updown
  
  
  
  for (Shld_Pos=15; Shld_Pos <=70; Shld_Pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        R_Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }
  
void flag_Shld_Dwn()
{

  R_Sholud_UP.attach(11);  // shoulder updown
  
    for (Shld_Pos=70; Shld_Pos >=15; Shld_Pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        R_Sholud_UP.write(Shld_Pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
  }

  
void flag_Bi_Rot_Clk()
{
   R_BIcep_Rot.attach(9);  // shoulder updown
    
    for (BIcep_Rot_pos=90; BIcep_Rot_pos <=170; BIcep_Rot_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          R_BIcep_Rot.write(BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }

  }
  

void flag_Bi_Rot_Anti()
{
  R_BIcep_Rot.attach(9);  // shoulder updown
    
    for (BIcep_Rot_pos=170; BIcep_Rot_pos >=90; BIcep_Rot_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          R_BIcep_Rot.write(BIcep_Rot_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }
  }


void flag_Bi_Up()

{
    R_BIcep_Up.attach(8);  // shoulder updown
    
    for (BIcep_Up_pos=10; BIcep_Up_pos <=50; BIcep_Up_pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          R_BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }


  }
  

void flag_Bi_Dwn()

{
  
    R_BIcep_Up.attach(8);  // shoulder updown
    
    for (BIcep_Up_pos=50; BIcep_Up_pos >=10; BIcep_Up_pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          R_BIcep_Up.write(BIcep_Up_pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          }


  
  }

  

void open_hand(){
  grip_pos=0;
  gripper.write(grip_pos);
  }

void close_hand(){
  grip_pos=90;
  gripper.write(grip_pos);
  }

  

void wavekaro()
  {
    gripper.attach(30);  // attaches the servo on pin 9 to the servo object
      open_hand();
      delay(5000);
      close_hand();  
      delay(1000);

      
      flag_Bi_Rot_Clk();
      delay(800);
      flag_Shld_Up();
      delay(1000);
      
      flag_Bi_Up();
      delay(800);
      flag_Bi_Dwn();    
      delay(800);
      
      flag_Bi_Up();
      delay(800);
      flag_Bi_Dwn();    
      delay(800);  
          
      flag_Bi_Up();
      delay(800);
      flag_Bi_Dwn();    
      delay(800);  
          
      flag_Bi_Up();
      delay(800);
      flag_Bi_Dwn();    
      delay(800);  
          
             
      flag_Bi_Up();
      delay(800);
      flag_Bi_Dwn();    
      delay(800);
      

    }


void resetkaro()
  {
      flag_Bi_Dwn();
      delay(1000);
      flag_Bi_Rot_Anti();
      delay(2000);
      flag_Shld_Dwn();
      delay(3000);
      
    }
