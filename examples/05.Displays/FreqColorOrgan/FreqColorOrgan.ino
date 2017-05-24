#include <Adafruit_NeoPixel.h>

int analogPin = A0; // read from multiplexer using analog input 0
int strobePin = D6; // strobe is attached to digital pin 2
int resetPin = D3; // reset is attached to digital pin 3
int spectrumValue[7]; // to hold a2d values
#define N_PIXELS  12  // Number of pixels you are using
#define LED_PIN D5
#define COLOR_MAX 255.0
#define FREQ_MAX 1024.0
#define FREQ_MIN 350.0

Adafruit_NeoPixel  strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
 Serial.begin(9600);
 pinMode(analogPin, INPUT);
 pinMode(strobePin, OUTPUT);
 pinMode(resetPin, OUTPUT);
// analogReference(DEFAULT);

 digitalWrite(resetPin, LOW);
 digitalWrite(strobePin, HIGH);
 strip.begin();
 for(int i=0; i<N_PIXELS; i++) { 
   strip.setPixelColor(i,   0);
 }
 strip.show();

 Serial.println("MSGEQ7 test by J Skoba");
}

void loop()
{
 digitalWrite(resetPin, HIGH);
 digitalWrite(resetPin, LOW);

 for (int i = 0; i < 7; i++)
 {
 digitalWrite(strobePin, LOW);
 delayMicroseconds(30); // to allow the output to settle
 spectrumValue[i] = analogRead(analogPin);
 strip.setPixelColor(i, map(spectrumValue[i]));

 // comment out/remove the serial stuff to go faster
 // - its just here for show
 if (spectrumValue[i] < 10)
 {
 Serial.print(" ");
 Serial.print(spectrumValue[i]);
 }
 else if (spectrumValue[i] < 100 )
 {
 Serial.print(" ");
 Serial.print(spectrumValue[i]);
 }
 else
 {
 Serial.print(" ");
 Serial.print(spectrumValue[i]);
 }

 digitalWrite(strobePin, HIGH);
 }
 strip.show(); // Update strip
 Serial.println();
}

// Input a value 0 to 255 to get a color value.
uint32_t map(int audioVal) {
  // We want to map a value in the range 0-1024 into one in the range 0-255
  if (audioVal <= FREQ_MIN) {
    return strip.Color(0, 0, 0);
  }
  double ratio = ((double)audioVal - FREQ_MIN)/(double)(FREQ_MAX- FREQ_MIN);
  byte val = (byte)(ratio * COLOR_MAX);
  return Wheel(val);
}

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


