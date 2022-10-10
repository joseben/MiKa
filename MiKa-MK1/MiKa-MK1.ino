/* 
1 - Drive front
2 - Drive Back
3 - Drive right
4 - Drive left
5 - Drive Stop
6 - Neck up
7 - Neck Down
8 - Neck rest


.
8 - Gripper open
9 - Gripper close
10 - Hip left turn
11 - Hip right turn
   - Hip rest
12 - Waist left up
13 - Waist right up
14 - Read Ultrasonic
15 - Read Sharp
16 - Namasthe
17 - Hands down (Rest)
18 - Read Encoder
19 - Neo Pixel
20 - Flower
21 - 




 */
//////////////////////////Libraries//////////////////////////////////////////
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Int32.h>



//////////////////////////Libraries//////////////////////////////////////////
//////////////////////////References//////////////////////////////////////////
void Drive_forward();
void Drive_backward();
void Drive_right();
void Drive_left();
void Drive_stop();
void neck_up();
void neck_down();
void setup_drive();
void setup_neck();
void setup_hip();
void setup_gripper();
void setup_waist();

//////////////////////////References//////////////////////////////////////////


ros::NodeHandle  nh;
void messageCb(const std_msgs::Int32 & arm_msg){

  if(arm_msg.data==1)//Drive front
  {
    digitalWrite(LED_BUILTIN,HIGH);
    Drive_forward();
  }
  
  else if (arm_msg.data==2)//Drive Back
  {
    digitalWrite(LED_BUILTIN,LOW);
    Drive_backward();
  }
  
    else if (arm_msg.data==3)//Drive right
  {
    digitalWrite(LED_BUILTIN,LOW);
    Drive_right();
  }
  
    else if (arm_msg.data==4)//Drive left
  {
    digitalWrite(LED_BUILTIN,LOW);
    Drive_left();
  }  
  
  else if (arm_msg.data==5)//Drive Stop
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    Drive_stop();
  }
    else if (arm_msg.data==6)//Neck Up
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    neck_up();
  }
    else if (arm_msg.data==7)//Neck Down
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    neck_down();
  }
    else if (arm_msg.data==8)//Neck rest
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    neck_rest();
  }
     else if (arm_msg.data==8)//left gripper open
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    left_open_hand();
  }   else if (arm_msg.data==8)//left gripper close
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    left_close_hand();
  }   else if (arm_msg.data==8)//right gripper open
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    right_open_hand();
  }   else if (arm_msg.data==8)//right gripper close
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    right_close_hand();
  }
     else if (arm_msg.data==8)//left turn hip
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    hip_turn_left();
  }   else if (arm_msg.data==8)//right turn hip
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    hip_turn_right();
  }  
  else if (arm_msg.data==8)// hip rest
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    hip_rest();
  } 
  else if (arm_msg.data==8)//left waist up
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    waist_left_up();
  }   else if (arm_msg.data==8)//right waist up
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    waist_right_up();
  }
   else if (arm_msg.data==8)//waist rest
  {
  
    digitalWrite(LED_BUILTIN,LOW);
    waist_rest();
  }
}

ros::Subscriber<std_msgs::Int32> sub("arm", &messageCb );

void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  setup_drive();
  setup_neck();
  setup_hip();
  setup_gripper();
  setup_waist();
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
