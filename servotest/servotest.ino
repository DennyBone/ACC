#include <Servo.h>

Servo motor;

int pos = 0;
int val = 0;

void setup()
{
  motor.attach(9);
  
}

void loop()
{
  //motor.write(160);
  for(pos = 0; pos < 180; pos = pos + 10)
    {
      motor.write(pos);
      delay(1000);
    }
}

