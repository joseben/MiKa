
#include <NewPing.h>

#define SONAR_NUM     4 // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.


NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(22, 24, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(26, 28, MAX_DISTANCE),
  NewPing(30, 32, MAX_DISTANCE),
  NewPing(38, 40, MAX_DISTANCE),
  //NewPing(38, 40, MAX_DISTANCE),
  //NewPing(42, 44, MAX_DISTANCE)  
};

void setup() {
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}

void loop() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == SONAR_NUM - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }
  // Other code that *DOESN'T* analyze ping results can go here.

}

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;

    // Send package for the reading
//    byte reading_high = highByte(cm[currentSensor]);
//    byte reading_low = lowByte(cm[currentSensor]);
//    byte packet[]={0x59,0x59,currentSensor,reading_high,reading_low};
//    Serial.write(packet, sizeof(packet));
    
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  
  for (uint8_t i = 0; i < SONAR_NUM; i++) {

     // Sending bytes
        //byte reading_high = highByte(cm[i]);
        //byte reading_low = lowByte(cm[i]);
        //byte packet[]={0x59,0x59,i,reading_high,reading_low};
       // Serial.write(packet, sizeof(packet));
    
    //Printing lines
    //if (i!=0) Serial.print(";");
    //Serial.print(i);
    //Serial.print(":");
    //Serial.print(cm[i]);
    if (cm[i]>=20)
    {
     Serial.print("Obstacle at Sensor ");
     Serial.print(i);
     Serial.print("  -- Distance is = ");
     Serial.print(cm[i]);
      
      }
    
  }
  
  //Serial.println();
  // delay(500);

}
