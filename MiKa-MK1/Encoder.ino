#define ENCODEROUTPUT 120

#define HALLSEN_B 18
#define HALLSEN_A 16 
#define HALLSEN_C 17
#define HALLSEN_D 19 

// Hall sensor A connected to pin 3 (external interrupt)


volatile long encoderValue_1 = 0;
volatile long encoderValue_2 = 0;
volatile long encoderValue_3 = 0;
volatile long encoderValue_4 = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
boolean measureRpm = false;
int motorPwm = 0;

void setup_encoder()
{
  Serial.begin(9600); // Initialize serial with 9600 baudrate

  pinMode(HALLSEN_A, INPUT_PULLUP); // Set hall sensor A as input pullup
  pinMode(HALLSEN_B, INPUT_PULLUP); // Set hall sensor A as input pullup
  pinMode(HALLSEN_C, INPUT_PULLUP); // Set hall sensor A as input pullup
  pinMode(HALLSEN_D, INPUT_PULLUP); // Set hall sensor A as input pullup
 
  // Attach interrupt at hall sensor A on each rising signal
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder_1, RISING);
  attachInterrupt(digitalPinToInterrupt(HALLSEN_B), updateEncoder_2, RISING);
  attachInterrupt(digitalPinToInterrupt(HALLSEN_C), updateEncoder_3, RISING);
  attachInterrupt(digitalPinToInterrupt(HALLSEN_D), updateEncoder_4, RISING);

}

/*void loop()
{
    Serial.print(rpmcalc(encoderValue_1));//rpmcalc(value) function will give each rpm int value
    d
    elay(1000);    
}
*/

int rpmcalc(long encoderValue){
    previousMillis = millis();

  // Update RPM value on every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

    // Revolutions per minute (RPM) =
    // (total encoder pulse in 1s / motor encoder output) x 60s
    rpm = (float)(encoderValue * 60 / ENCODEROUTPUT);

    // Only update display when there have readings
    if ( rpm > 0) {
      Serial.print(encoderValue);
      Serial.print(" pulse / ");
      Serial.print(ENCODEROUTPUT);
      Serial.print(" pulse per rotation x 60 seconds = ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
  }
  return rpm;
}
void updateEncoder_1()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue_1++;
}
void updateEncoder_2()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue_2++;
}

void updateEncoder_3()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++_3;
}
void updateEncoder_4()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++_4;
}
