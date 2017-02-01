/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
Connect microphone out to A0
****************************************/
#include <Adafruit_NeoPixel.h>

#define N_PIXELS  12  // Number of pixels you are using
// Max is 1024 for tall mics, 512 for short ones
#define MAX_VOLUME 512
#define MIC_PIN   A0  // Microphone is attached to A0
#define LED_PIN   D2  // NeoPixel LED strand is connected to D2

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

Adafruit_NeoPixel  strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
   Serial.begin(9600);
   strip.begin();
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
   double height = 0;
   uint8_t i = 0;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(MIC_PIN);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   Serial.println(peakToPeak);

   // Now turn sound into color
   height = (N_PIXELS + 1) * peakToPeak / (long)MAX_VOLUME;
   Serial.print("height ");
   Serial.println(height);
   // Color pixels based on rainbow gradient
   for(i=0; i<N_PIXELS; i++) {  
     if(i >= height) {          
       strip.setPixelColor(i,   0,   0, 0);
     } else {
       strip.setPixelColor(i,Wheel(map(i,0,strip.numPixels()-1,30,150)));
     }
   }
   strip.show(); // Update strip
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


