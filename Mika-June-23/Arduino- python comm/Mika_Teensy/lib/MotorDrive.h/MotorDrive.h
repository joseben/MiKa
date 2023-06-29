#define pwm1 22
#define pwm2 28
#define pwm3 29
#define pwm4 23
#define dir1 16
#define dir2 21
#define dir3 20
#define dir4 17

void motorInit() {
  // put your setup code here, to run once:
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);

}

void forward(){
  motorInit();
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}

void backward(){
  motorInit();
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}
void right(){
  motorInit();
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4, LOW);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}
void left(){
  motorInit();
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}

void stopDrive(){
  motorInit();
  int i=50;
    for(i=50;i>=0;i--){
      analogWrite(pwm1,i);
      analogWrite(pwm2,i);
      analogWrite(pwm3,i);
      analogWrite(pwm4,i);
      delay(20);
      }
}
void stop(){
  motorInit();
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
}
void try_1(){
  digitalWrite(dir1, LOW);
  analogWrite(pwm1, 200);
}