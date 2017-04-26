/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
#include <Adafruit_NeoPixel.h>
 
int speakerPin = D6;
int photocellPin = A0;
#define DIN_PIN D2
#define NUM_PIXELS 12
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, DIN_PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600); 
  strip.begin();
  strip.setBrightness(15);
  strip.show();  
}
 
void loop()
{
    Serial.println("Color Wipe Magenta");
  colorWipe(strip.Color(255, 0, 255), 50);
  delay(pause);
 
}

