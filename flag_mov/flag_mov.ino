/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
/////////////////////////////////////////////////////////////////////////////////////////////////
//pin 4 shoulder up 10- 70
//pin3 bicep rotate 10-90
//pin2  bicep updown 10-81
//pin5 should rotate

#include <Servo.h>

Servo R_Sholud_UP;  // create servo object to control a servo
Servo R_Sholud_Rot;  // create servo object to control a servo
Servo R_BIcep_Rot;  // create servo object to control a servo
Servo R_BIcep_Up;  // create servo object to control a servo

Servo gripper;  // create servo object to control a servo

// twelve servo objects can be created on most boards

/////////////////////////////////////////////////////////////////////////////////////////////////
#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
#include <avr/power.h>
#endif


#define PIN        27
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <ros.h>
#include <std_msgs/Int32.h>


ros::NodeHandle  nh;

int flagwave=3;

int lock=0;
int reset_status=1;

int Shld_Pos = 10;    // variable to store the servo position
int Bi_Rot_Pos = 10;    // variable to store the servo position
int BIcep_Up_pos = 10;    // variable to store the servo position
int BIcep_Rot_pos = 30;    // variable to store the servo position
int Shld_Rot_Pos = 0;    // variable to store the servo position
int grip_pos;

void messageCb(const std_msgs::Int32 & arm_msg){

  

  if(arm_msg.data==10 && reset_status==1)
  {
      if(lock==1) return;
      lock=1;
      digitalWrite(LED_BUILTIN,HIGH);
      flagwave=1;
      //resetkaro();
      wavekaro();
      lock=0;
      reset_status=0;
    
  }
  else if (arm_msg.data==11&& reset_status==1)
  {
      if(lock==1) return;
      lock=1;
      digitalWrite(LED_BUILTIN,LOW);
            //namste_leftarm_reset();

      namste_leftarm();
      flagwave=2;
      lock=0;
      reset_status=0;
  }

  else if (arm_msg.data==12)
  {
    if(lock==1) return;
    lock=1;
    if (flagwave==1)
    {
       resetkaro();
       reset_status=1;

      }
    else if (flagwave==2)
    {
      namste_leftarm_reset();
      reset_status=1;

      }
    }
    lock=0;
}

ros::Subscriber<std_msgs::Int32> sub("arm", &messageCb );

void blue(){
  for(int i=0; i<16; i++) { 

    pixels.setPixelColor(i, pixels.Color(0, 0, 200));
    

    pixels.show(); 

    delay(DELAYVAL);
  }
  }
void flag_display(){
  for(int i=0; i<5; i++) { 

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    

    pixels.show(); 

    delay(DELAYVAL);
  }
  for(int i=5; i<11; i++) {
    pixels.setPixelColor(i, pixels.Color(250, 250, 250));
    

    pixels.show();  

    delay(DELAYVAL); 
  }
  for(int i=11; i<16; i++) { 
    pixels.setPixelColor(i, pixels.Color(230, 80, 0));
    

    pixels.show(); 

    delay(DELAYVAL);
  }
  //pixels.clear();
  }


void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  #if defined(_AVR_ATtiny85_) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
    flag_display();
    //blue();
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
