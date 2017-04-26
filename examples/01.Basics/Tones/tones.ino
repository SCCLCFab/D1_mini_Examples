 /* connect piezo buzzer to ground and speakerPin.
  *  speakerPin = 12 is the same as pin D6
  *  See:
  *  https://github.com/esp8266/Arduino/blob/master/variants/d1_mini/pins_arduino.h#L49-L61
  */
int speakerPin = 12;
 
int numTones = 10;
int tones[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//            mid C  C#   D    D#   E    F    F#   G    G#   A
 
void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(50);
  }
  noTone(speakerPin);
}
 
void loop()
{
    for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}

