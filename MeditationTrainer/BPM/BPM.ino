#include <Adafruit_NeoPixel.h>

int incomingByte = 0;

#define LED_PIN    6
#define LED_COUNT 16

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

//  Variables
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() {   

   Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(20); // Set BRIGHTNESS to about 1/5 (max = 255)

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(250);                           //  Pause for a moment
  }
}

void bpmBreath(){
  
                            int TOTAL_LEDS = 16;
                            float MaximumBrightness = 50;
                            float SpeedFactor1 = 0.05; 
                            float SpeedFactor2 = 0.1;
                            float SpeedFactor3 = 0.2; 
                            float StepDelay = 5; // ms for a step delay on the lights
                            int myBPM = pulseSensor.getBeatsPerMinute();
  
                           Serial.print(myBPM);
                           Serial.print(",");
                           Serial.println(myBPM);
                      
                                if (myBPM<=60){

                                    // Make the lights breathe
                                    for (int i = 0; i < 65535; i++) {
                                    // Intensity will go from 10 - MaximumBrightness in a "breathing" manner
                                    float intensity = MaximumBrightness /2.0 * (1.0 + sin(SpeedFactor1 * i));
                                    strip.setBrightness(intensity);
                                    // Now set every LED to that color
                                    for (int ledNumber=0; ledNumber<TOTAL_LEDS; ledNumber++) {
                                    strip.setPixelColor(ledNumber, 170, 0, 254);
                                    }
                                    
                                    strip.show();
                                    //Wait a bit before continuing to breathe
                                    delay(StepDelay);
                                    
                                    }


                               }
                               else if (myBPM<=100){
                                
                                  // Make the lights breathe
                                  for (int i = 0; i < 65535; i++) {
                                  // Intensity will go from 10 - MaximumBrightness in a "breathing" manner
                                  float intensity = MaximumBrightness /2.0 * (1.0 + sin(SpeedFactor2 * i));
                                  strip.setBrightness(intensity);
                                  // Now set every LED to that color
                                  for (int ledNumber=0; ledNumber<TOTAL_LEDS; ledNumber++) {
                                  strip.setPixelColor(ledNumber, 229, 0, 227);
                                  }
                                  
                                  strip.show();
                                  //Wait a bit before continuing to breathe
                                  delay(StepDelay);
                                  
                                  }
                                  delay(100);

                               }
                               else {
                                
                                  // Make the lights breathe
                                  for (int i = 0; i < 65535; i++) {
                                  // Intensity will go from 10 - MaximumBrightness in a "breathing" manner
                                  float intensity = MaximumBrightness /2.0 * (1.0 + sin(SpeedFactor3 * i));
                                  strip.setBrightness(intensity);
                                  // Now set every LED to that color
                                  for (int ledNumber=0; ledNumber<TOTAL_LEDS; ledNumber++) {
                                  strip.setPixelColor(ledNumber, 200, 0, 0);
                                  }
                                  
                                  strip.show();
                                  //Wait a bit before continuing to breathe
                                  delay(StepDelay);
                                  
                                  }
                                  delay(100);

                               }
}

void trainer(){
                                colorWipe(strip.Color( 219,112,0), 20); 
                                delay(400);
                                colorWipe(strip.Color(  0,   0, 0), 20); 
}


void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

 
           
 Serial.print(myBPM);
 Serial.print(",");
 Serial.println(myBPM);// Print the value inside of myBPM. 

                   
                if (Serial.available() > 0) {   // see if there's incoming serial data
                   incomingByte = Serial.read(); // read it
                    switch (incomingByte) {
                    case 'h':
                       bpmBreath();
                      break;
                    case 'l':
                         trainer();
                      break;
                       default:
                        strip.show();
                    }
//                    if (incomingByte == 'h') {
//                      
//                            bpmBreath();
// 
//           
//                }
//                else if (incomingByte == 'l') {
//
//                              trainer();
//                }
               
            delay(100);

}

                }

                




  
