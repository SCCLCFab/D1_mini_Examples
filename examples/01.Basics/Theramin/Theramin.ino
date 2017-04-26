/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
 
int speakerPin = D6;
int photocellPin = A0;
 
void setup()
{
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop()
{
 int reading = analogRead(photocellPin);
 Serial.print("Analog reading = ");
 Serial.println(reading);     // the raw analog reading

 int pitch = 200 + reading / 4;
 tone(speakerPin, pitch);
}

