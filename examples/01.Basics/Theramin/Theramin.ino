/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
 
int speakerPin = 12; /* D6 */
int photocellPin = 0;
int button_pin = D3;
 
void setup()
{
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);  
  pinMode(button_pin, INPUT); 
}
 
void loop()
{
 int reading = analogRead(photocellPin);
 Serial.print("Analog reading = ");
 Serial.println(reading);     // the raw analog reading
 int button_reading = analogRead(button_pin); //Read button value
 int pitch = 1224 + ((reading)-600 + (button_reading)*600) / 2;
 tone(speakerPin, pitch);
}

