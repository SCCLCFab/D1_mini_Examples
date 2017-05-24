#include <SoftwareSerial.h>

SoftwareSerial sSerial(0,1); // RX, TX Pins
void setup()
{
    sSerial.begin(1200);
}

void loop()
{
    
   // The 434MHz RF Link has a lot of noise. The Receiver side is looking for the character sequence Temp  
   // before each temperature reading. The sequence is unlikely to occur in random noise data.
   // Send some nulls to get the RF receiver to listen at our signal to noise level (improves reliablilty of getting "T")
   // Then send our data marker character sequence (Temp in the case)
   // Then send the temperature reading
   SendNulls();
   sSerial.write("Temp");
   sSerial.print(440);

   delay(5000); // wait 5 seconds
 
}

void SendNulls()
{
  for(int i=0; i<5; i++)
  {
    sSerial.write((uint8_t)0);
  }
}
