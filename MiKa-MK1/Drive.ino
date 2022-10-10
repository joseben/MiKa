#define pwm1 2
#define pwm2 4
#define pwm3 6
#define pwm4 8
#define dir1 3
#define dir2 5
#define dir3 7
#define dir4 9

void setup_drive() {
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

void Drive_forward(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}

void Drive_backward(){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}
void Drive_right(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4, LOW);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}
void Drive_left(){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}
void Drive_stop(){
  int i=50;
    for(i-50;i>=0;i--){
      analogWrite(pwm1,i);
      analogWrite(pwm2,i);
      analogWrite(pwm3,i);
      analogWrite(pwm4,i);
      delay(20);
      }
}
