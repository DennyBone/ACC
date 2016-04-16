void setup(){
  Serial.begin(9600);
}

void loop()
{
  unsigned int a = 0;
  unsigned int b = 0;
  a = a | 0b0010;
  b = b | 0b1001;
  Serial.println(b, BIN);
  delay(500);
  unsigned long d;
  a = a << 1;
  Serial.println(a, BIN);
  d = a | b;
  Serial.println(d, BIN);
  delay(1000);
}
