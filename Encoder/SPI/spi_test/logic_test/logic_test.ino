#include <SPI.h>
#include "pins_arduino.h"

void setup (void)
{
  SPI.begin();
  
}


void loop (void)
{

  
  //digitalWrite(10, HIGH);  // ensure SS stays high

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on

 
  // enable Slave Select
  digitalWrite(10, LOW);    // SS is pin 10
  const char a = 'F';
  //const char b = 'b';
  //const char c = 'c';
  
  SPI.transfer(a);
  //SPI.transfer(b);
  //SPI.transfer(c);  

 // disable Slave Select
 digitalWrite(10, HIGH);

 // turn SPI hardware off
 //SPI.end ();
 
 //while (1);  //loop
}
