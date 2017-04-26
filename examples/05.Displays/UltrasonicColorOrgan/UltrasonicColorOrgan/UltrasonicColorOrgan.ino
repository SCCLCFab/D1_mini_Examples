/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
Connect microphone out to A0
****************************************/
#include <Adafruit_NeoPixel.h>

#define N_PIXELS  12  // Number of pixels you are using
#define echoPin D7 // Echo Pin
#define trigPin D5 // Trigger Pin
#define LED_PIN   D2  // NeoPixel LED strand is connected to D2
#define MAX_DISTANCE 50 // cm, measurement gets noisy after that

double distInCm;
double height;
Adafruit_NeoPixel  strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  strip.begin();
}
 
 
void loop() 
{
  distInCm = readDistance();
  Serial.print("Distance: ");
  Serial.print(distInCm);
  Serial.println(" cm.");

   // Now turn distance into color
   height = (N_PIXELS + 1) * distInCm / (long)MAX_DISTANCE;
   Serial.print("height ");
   Serial.println(height);
   // Color pixels based on rainbow gradient
   uint8_t i = 0;
   for(i=0; i<N_PIXELS; i++) {  
     if(i >= height) {          
       strip.setPixelColor(i,   0,   0, 0);
     } else {
       strip.setPixelColor(i,Wheel(map(i,0,strip.numPixels()-1,30,150)));
     }
   }
   strip.show(); // Update strip
   //Delay 50ms before next reading.
   delay(50);
}

double readDistance()
{
  double distance, duration; // Duration used to calculate distance
  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
  return distance;
}


// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


