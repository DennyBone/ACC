#include <Servo.h>

Servo motor;

int rpm = 0;
int pos = 0;
unsigned long lastmillis = 0;
int rpmcount = 0;
unsigned long timeold = 0;
int calc = 2;

void setup()
{
   Serial.begin(9600);
   motor.attach(9);
   attachInterrupt(0, rpm_fan, FALLING);
}


void loop()
{
  if (rpmcount == calc)
  {
    motor.write(150);
  }
  else
  {
    motor.write(30);
  }
  
  /*for(pos = 0; pos < 180; pos = pos + 10)
  {
    motor.write(pos);
    delay(1000);
  }*/
  
  //if (millis() - lastmillis == 1000)
  /*if (rpmcount >= 2)
  {
    detachInterrupt(0);
    
    rpm = rpmcount;
    timeold = millis();
    rpmcount = 0;
    
    Serial.print("RPM = \t");
    Serial.print(rpm);
    //Serial.print(" \t Hz = \t");
    //Serial.println(rpmcount);
    
    //rpmcount = 0;
    //lastmillis = millis();
    attachInterrupt(0, rpm_fan, FALLING);
  }*/
}

void rpm_fan()
{
  rpmcount++;
}


  
