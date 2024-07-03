// arducam pin = arduino pin


#ifdef ARDUINO_TEENSY41 
// if using teensy (green)
const int CS  = 10; // arducam pin 1 to arduino pin 10 (CS)
      // MOSI = 11 (MOSI) (may be labelled COPI)
      // MISO = 12 (MISO) (may be labelled CIPO)
      // SCLK = 13 (SCK)
      // GND  = GND (rail)
      // +5V  = Vcc (rail--3.3V may be OK for 2MP arducam)
      // SDA  = 18 (SDA)
      // SCL  = 19 (SCL) 

#else

//if using mkrzero (blue)
const int CS  = 7; // arducam pin 1 to arduino pin 7 
      // MOSI = 8 MOSI (may be labelled COPI)
      // MISO = 10 MISO (may be labelled CIPO)
      // SCLK = 9 SCK
      // GND  = GND (rail)
      // +5V  = Vcc (rail--3.3V may be OK for 2MP arducam)
      // SDA  = 11 SDA 
      // SCL  = 12 SCL 


#endif



