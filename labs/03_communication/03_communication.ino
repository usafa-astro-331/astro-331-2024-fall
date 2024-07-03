#include "xbee_pins.h"

#include "LED_pins.h"
#include "input.h"

  
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // normal USB serial port to PC
  Serial1.begin(9600); // 2nd serial port to XBee radio


	pinMode(LED_pin, OUTPUT); 
	digitalWrite(LED_pin, LOW); 


// clear terminal screen 
  Serial1.write(27);       // ESC command
  Serial1.print("[2J");    // clear screen command
  Serial1.write(27);
  Serial1.print("[H");     // cursor to home command


  
Serial1.println("FlatSAT online \npress 1 for options");
Serial.print("hello \n");
}

void loop() {
  get_command_from_pc(); // defined in input.cpp
}