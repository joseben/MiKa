#define ENCODEROUTPUT 120

#define BUTTON 2 // Maker UNO built-in button connected to pin 2
#define HALLSEN_A 3 // Hall sensor A connected to pin 3 (external interrupt)


volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
boolean measureRpm = false;
int motorPwm = 0;

void setup()
{
  Serial.begin(9600); // Initialize serial with 9600 baudrate

  pinMode(BUTTON, INPUT_PULLUP); // Set button as input pullup
  pinMode(HALLSEN_A, INPUT_PULLUP); // Set hall sensor A as input pullup
 
  // Attach interrupt at hall sensor A on each rising signal
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);

  Serial.print("\n\n");
  Serial.println("Measuring DC Motor's RPM");
  Serial.println("Press Maker UNO button to begin.");
  Serial.println("Press again to stop.");
}

void loop()
{
    Serial.print(rpmcalc());
}
int rpmcalc(){
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
void updateEncoder()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++;
}
