#include <Rtc_Pcf8563.h>
#include <Wire.h>       // for I2C communication
#include <Servo.h> 

//initialize RTC Timer
Rtc_Pcf8563 rtc; //initialize

// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 

void setup() { 
   // We need to attach the servo to the used pin number 
   Serial.begin(9600);
   Wire.begin();
   Servo1.attach(servoPin); 

   rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  rtc.setDate(16, 3, 11, 20, 20);
  //hr, min, sec
  rtc.setTime(11, 0, 0);
}
void loop(){ 
  int currentHour = rtc.getHour();
  int currentMinute = rtc.getMinute();
  int currentSecond = rtc.getSecond();

  Serial.print("Time:");
  //Serial.print(rtc.formatTime(RTCC_TIME_HM));
  Serial.print(rtc.formatTime());
 
  Serial.print("\t Date:");
  //Serial.println(rtc.formatDate(RTCC_DATE_ASIA));
  Serial.println(rtc.formatDate());

  delay(1000);

   if (currentHour == 11 && currentMinute == 0 && currentSecond == 25) {
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(5000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000);
  }

  if (currentHour == 11 && currentMinute == 0 && currentSecond == 40) {
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(5000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000);
   
  }
}
