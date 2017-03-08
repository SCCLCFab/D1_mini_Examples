/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  Rotate a servo using a slider!

  App project setup:
    Simple LCD displaying instructions 'Tap R then L'
                                       'ends of slider'
    Slider widget (0...160) on V3
    Advanced LCD display for feedback to customer on V1

 Physical circuit setup:
    LED + to D1 
    with 270 resister on GND side
    
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e4c6b2d30b0b4524a9316eaec4a570b7";

// Your WiFi credentials.
// Set password to "" for open networks.
/*
char ssid[] = "CEREBRO_GUEST";
char pass[] = "17flyonWater";
*/
char ssid[] = "SCCLC Guest";
char pass[] = "";


Servo servo;
int pos = 0;

// Initialize LCD widget
WidgetLCD lcd(V1);  

BLYNK_WRITE(V3)
{
  pos = param.asInt();
  servo.write(pos);
  Serial.println(pos);

  //  flash LED twice & turn back on & loading message
  if (pos > 140) { 
    digitalWrite(D1, HIGH);
    delay(250);
    digitalWrite(D1, HIGH);
    delay(250);
    digitalWrite(D1, LOW);
    delay(250);
    digitalWrite(D1, HIGH);
    delay(250);
    digitalWrite(D1, LOW);
    delay(250);
    digitalWrite(D1, HIGH);
    lcd.print(0,0, "Loading..");
  }
  //  flash LED twice, turn back on & have a great day message
  else if (pos < 20) { 
    lcd.print(0,0, "Have a great day!");
    digitalWrite(D1, HIGH);
    delay(250);
    digitalWrite(D1, LOW);
    delay(250);
    digitalWrite(D1, HIGH);
    delay(250);
    digitalWrite(D1, LOW);
    delay(250);    
    digitalWrite(D1, HIGH);
    lcd.clear();
  } 
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);
  // Clear LCD widget
  lcd.clear();
  // Initialize servo
  servo.attach(2);  // GPIO2 = D4 on WeMos
  
  // Initialize LED pin on D1, flash twice and turn it on
  pinMode(D1, OUTPUT);
  digitalWrite(D1, HIGH);
  delay(1000);
  digitalWrite(D1, LOW);
  delay(1000);
  digitalWrite(D1, HIGH);
  delay(1000);
  digitalWrite(D1, LOW);
  delay(1000);
  digitalWrite(D1, HIGH);
}

void loop()
{
  Blynk.run();
}

