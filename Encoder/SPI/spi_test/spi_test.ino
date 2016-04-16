#include <SPI.h>

unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
unsigned int e;
unsigned int f;
unsigned long pos1;
unsigned long pos2;
unsigned long pos3;
float time1;
float time2;
float time3;
float rad_vel;
float final_vel;
float buffer[10]; //Arbitrarily big so I don't address outside of array
const float delta = .002746;
const float pi = 3.14;
int n;


void setup()
{
  Serial.begin(9600);
  SPI.begin(); // start the spi library
  SPI.setDataMode(SPI_MODE2); // Clock starts high, data sampled on falling edge
  SPI.setBitOrder(MSBFIRST); // MSB sent first (according to data sheet)
  SPI.setClockDivider(32); // 16MHz/32 = 500kHz
  pinMode(12, INPUT); // pin 12 = Master In Slave Out
  pinMode(13, OUTPUT); // pin 13 = SCK
  pinMode(11, OUTPUT); // MOSI
  pinMode(10, OUTPUT); // SS/NSL
  
}

void loop()
{
  
  for (n=0; n<4; n++)
  {  
    digitalWrite(10, LOW); // set SS pin to low to initiate start of sequence
    //delayMicroseconds(5); //Not sure if this is correct/necessary
  
    a = SPI.transfer(0); // get the first 8 bits, including MSB(sent first)
    b = SPI.transfer(0); // get next 8 bits
    c = SPI.transfer(0); // get last bit
    time1 = micros();
    digitalWrite(10, HIGH);
    
    digitalWrite(10, LOW);
    d = SPI.transfer(0); // get the first 8 bits, including MSB(sent first)
    e = SPI.transfer(0); // get next 8 bits
    f = SPI.transfer(0); // get last bit
    time2 = micros();
    digitalWrite(10, HIGH); // set SS high to end sequence
    
    // Bitshift and combine values to get 17 bit position
    a = a << 8;
    pos1 = a | b; 
    pos1 = pos1 << 1;
    pos1 = pos1 | c; // Final variable that holds 17 bit position
    //Serial.print("pos1 BIN: ");
    //Serial.println(pos1, BIN); // print 17 bit binary value
    
    // Bitshift and combine values to get 17 bit position
    d = d << 8;
    pos2 = d | e; 
    pos2 = pos2 << 1;
    pos2 = pos2 | f; // Final variable that holds 17 bit position
    //Serial.print("pos2 BIN: ");
    //Serial.println(pos2, BIN); // print 17 bit binary value
      
    //Convert Bits to Angles
    pos1 = pos1*delta; // in degrees
    pos2 = pos2*delta;
    
    // Compute the radial velocity
    if (pos2 < pos1){
      pos2 = pos2 + 360; // Add 360 degrees to make the difference positive
      pos3 = pos2 - pos1; // Change of Angle in degrees
    }
    else {
      pos3 = pos2 - pos1;
    }
    //Serial.print("pos3: ");
    //Serial.println(pos3, BIN);
    time3 = time2 - time1; // time difference in microseconds
    //Serial.print("time3: ");
    //Serial.println(time3);
    rad_vel = ((pos3)*(pi/180)*(1000000))/(time3); // radial velocity in rads/sec
    //Serial.print("Radial velocity: ");
    //Serial.println(rad_vel);
  
    // Buffer rad_vel in order to apply average filter
    buffer[n] = rad_vel;  
    
  }
  
  // Average Filter
  final_vel = (buffer[0] + buffer[1] + buffer[2] + buffer[3])/4;
  Serial.println(final_vel);
  
}
  

