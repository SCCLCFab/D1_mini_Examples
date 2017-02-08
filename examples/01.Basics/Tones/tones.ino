 /* connect piezo buzzer to ground and speakerPin.
  *  speakerPin = 12 is the same as pin D6
  *  See:
  *  https://github.com/esp8266/Arduino/blob/master/variants/d1_mini/pins_arduino.h#L49-L61
  */
int speakerPin = 12;
 
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   E   D#   E    F    F#   G  C   G#   G  E#  F  G  A#  C 
 
void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}
 
void loop()
{
}

