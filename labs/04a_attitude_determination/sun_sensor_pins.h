
int sunpx_reading, sunpy_reading, sunnx_reading, sunny_reading; 
int north, east; 
float sun_direction, sun_x, sun_y; 

#ifdef ARDUINO_TEENSY41
  static int sunpx_pin = 24; 
  static int sunpy_pin = 25;
  static int sunnx_pin = 26;
  static int sunny_pin = 27;
#else  // Arduino MKR Zero
  static int sunpx_pin = 18; // (A3)
  static int sunpy_pin = 19; // (A4)
  static int sunnx_pin = 20; // (A5)
  static int sunny_pin = 21; // (A6)
#endif
