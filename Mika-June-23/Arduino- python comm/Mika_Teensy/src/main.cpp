#include <Arduino.h>

#include <action.h>
#include <MotorDrive.h>
#include <HandWave.h>
#include <danceSeq.h>
#include <flower.h>
#include <detach.h>


void setup()
{
  //An LED is Connected Pin12 
  pinMode(13,OUTPUT);  //Make Pin12 Output
  digitalWrite(13,LOW);//Make Pin12 OFF

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 8N1

}

void loop()
{
  char RxedByte = 0;

 if (Serial.available()) 
    {
      RxedByte = Serial.read();    
      switch(RxedByte)
      {
        case 'A':  
                  action();
                  delay(1000);
                  detach_servo();
                  break;

        case 'B':  
                  forward();
                  break;

        case 'C':  
                  backward();
                  break;

        case 'D':  
                  right();
                  break;

        case 'E':  
                  left();
                  break;

        case 'F':  
                  stopDrive();
                  break;

        case 'G':  
                  namasthe(); //it will reset itself after 7seconds
                  delay(1000);
                  detach_servo();
                  break;

        case 'H':  
                  namastheReset(); 
                  delay(1000);
                  detach_servo();
                  break;

        case 'I':  
                  handWave(); // it will reset itself
                  delay(1000);
                  detach_servo();
                  break;

        case 'J':  
                  waveReset();
                  delay(1000);
                  detach_servo();
                  break;
        case 'K':  
                  seq1();
                  delay(1000);
                  detach_servo();
                  break;

        case 'L':  
                  seq2();
                  delay(1000);
                  detach_servo();
                  break;

        case 'M':  
                  flower();
                  delay(1000);
                  detach_servo();
                  break;

        default:
                  action();
                  delay(1000);
                  detach_servo();
                  break;
      }//end of switch()
    

    Serial.print(RxedByte); 

    }//endof if 
}
      

  
