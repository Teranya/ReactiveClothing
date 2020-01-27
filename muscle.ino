#include <Servo.h>
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

Servo myservo;  // create servo object to control a servo

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int pos = 45;    // variable to store the servo position
void setup() {
 myservo.attach(9); 
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 300, 45, 90);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.println(sensorValue);
//myservo.write(outputValue);
//
////Servo control

//
if (sensorValue < 40){
 myservo.write(45); 
 delay(100);
    
}
else {
   myservo.write(90); 
   delay(100);
}
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
//  delay(2);
}
