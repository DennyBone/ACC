void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
}

void Measure(){  // Gets and prints boolean value coming from Hall Sensor
                 // Value is 0 when magnetic field is detected. 1 otherwise
  int raw = digitalRead(8);
  Serial.print("Raw reading: ");
  Serial.println(raw);
}

int count = 0;

void RPM()
{
  int raw1 = digitalRead(8); 
   if (raw1 == 0){
     count = count + 1;
   }
  Serial.print("Count: ");
  Serial.print(count); 
}

void loop() {
  Measure();
  RPM();
  //delay(200);
}

