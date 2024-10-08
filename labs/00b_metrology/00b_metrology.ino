// in Arduino (which is based on C++), lines beginning with '//' are ignored

/* you can also create a block comment starting with '/*' 
  
  at a minimum, all arduino programs contain this structure:
  
      setup(){
        some code
      } // end of function setup()

      loop(){ 
        some code
      } // end of function loop()

  the setup() function runs once
  the loop() function continues forever

  
  usually, arduino code also contains some instructions and definitions before or after setup()

  block comments end with this: */



// create variables and constants
// pin assignments for voltage measurement
const int volt_in = A3; 

// create names for variables that will be filled later
int volt_counts; 
float volts; 

void setup() {

  Serial.begin(9600); // opens a serial port that will connect to your PC
  Serial1.begin(9600); // Arduino's hardware serial port
  
  // MKR Zero has a 12-bit ADC, but defaults to 10 bits
  // this line sets resolution to its 12-bit max
  analogReadResolution(12); 
  
  // print a legend at the top of the serial monitor
  Serial.println("time (ms), voltage (counts), voltage (V)");

} // end function setup()

void loop() {

  volt_counts = analogRead(volt_in);

  volts = volt_counts * 1;

  String write_line = ""; 

  write_line += "time_(ms):"; 
	  write_line += millis(); 
    write_line += "\t";
  write_line += "voltage_(counts):";
	  write_line += volts; 
	
	Serial.println(write_line); // write to Arduino USB serial port
	Serial1.println(write_line); // write to Arduino hardware serial port (may be connected to xbee)

  
  delay(100); // wait 100 ms so you're not flooded with data
} // end function loop()

