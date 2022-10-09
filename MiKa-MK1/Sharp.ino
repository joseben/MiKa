int sharp_f = 0;                 // analog pin used to connect the sharp sensor
int sharp_b = 1;                 // analog pin used to connect the sharp sensor

int val_f = 0;                 // variable to store the values from sensor(initially zero)
int val_cm_f=0;

int val_b = 0;                 // variable to store the values from sensor(initially zero)
int val_cm_b=0;

void setup()
{
  Serial.begin(115200);               // starts the serial monitor
}
 
void loop()
{
  sharpval();
  delay(100);                    // wait for this much time before printing next value
}

void sharpval(){
  val_f = analogRead(sharp_f);       // reads the value of the sharp sensor
  val_cm_f=pow(3027.4 / val_f, 1.2134);
  val_b = analogRead(sharp_b);       // reads the value of the sharp sensor
  val_cm_b=pow(3027.4 / val_b, 1.2134);

  if (val_cm_f>=10)
  {
    Serial.print("Front Dump");
    }

    else if(val_cm_b>=10)
    {
    Serial.print("Back Dump");
    }
}
