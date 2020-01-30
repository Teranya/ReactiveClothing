const int ledPin = 5; // the pin that the LED is attached to
int incomingByte = 0;;     // a variable to read incoming serial data into
 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
 Serial.begin(9600);            
 #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
 
void loop() {
    
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();            // Turn OFF all pixels ASAP
  pixels.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)


 if (Serial.available() > 0) {   // see if there's incoming serial data
   incomingByte = Serial.read(); // read it
   if (incomingByte == 'h') {    // if it's a capital H (ASCII 72),
//
             for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

                // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
                // Here we're using a moderately bright green color:
                pixels.setPixelColor(i, pixels.Color(255, 0, 0));
            
                pixels.show();   // Send the updated pixel colors to the hardware.
            
              }
   }
   if (incomingByte == 'l') {    // if it's an L (ASCII 76)
   
                  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
            
                // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
                // Here we're using a moderately bright green color:
                pixels.setPixelColor(i, pixels.Color(255, 153, 204));
            
                pixels.show();   // Send the updated pixel colors to the hardware.
            
                
              }
   }
 }
}
