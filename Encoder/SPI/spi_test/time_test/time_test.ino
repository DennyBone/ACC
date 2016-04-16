
unsigned long buffer[6];
int n = 0;

void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  unsigned long time;
  for (n=0; n<6; n++)
  {
    time = micros();
    buffer[n] = time;
    Serial.println(time);
    Serial.println(n);
    delay(1000);
  }
  Serial.println("HEY");
  
  int a = B1000;
  int b = B0100;
  int c = a - b;
  Serial.println(c);
  Serial.println(c, BIN);
   
  Serial.print("buffer 4 = ");
  Serial.println(buffer[4]);
  delay(1000);
  
}
