#include <WEMOS_Motor.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


//********************* COMPLETE WITH YOUR DETAILS *************
// Get Auth Token in the Blynk App.
char cloudserver[16] = "blynk-cloud.com";
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
// MCL: token for esptest with ESP8266
char auth[] = "045fafca4d5d4a16a4c698ed3f18ae13";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SCCLC Guest";
char pass[] = "";
//****************


int pwm;

//Motor shield I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30,_MOTOR_A, 1000);//Motor A
Motor M2(0x30,_MOTOR_B, 1000);//Motor B


void setup()
{
  Serial.begin(9600);
  Serial.println("\n Starting");
  Blynk.begin(auth, ssid, pass);              // normal Blynk Cloud server connection     
}

void loop() {
  Blynk.run();
}


BLYNK_WRITE(V0) {
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);
  delay(200);
  Serial.println("Motor A&B STOP");

  M1.setmotor(_SHORT_BRAKE);
  M2.setmotor( _SHORT_BRAKE);
  Serial.println("Motor A&B SHORT BRAKE");  
  delay(200);
  
  M1.setmotor(_STANDBY);//Both Motor standby
  M2.setmotor( _STANDBY);
  Serial.println("Motor A&B STANDBY");  
  delay(200);
}

BLYNK_WRITE(V1) {
  int x = scale(param[0].asInt());
  int y = scale(param[1].asInt());

  // Do something with x and y
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);
  if (x > 50) {
    M1.setmotor( _CW, x);
  } else {
    M1.setmotor(_CCW, x);
  }
  if (y > 50) {
    M2.setmotor(_CW, y);
  } else {
    M2.setmotor(_CCW, y);
  }
}

int scale(int val) {
  double scaled = 100.0 * (val/1024.0);
  Serial.print("Scaling ");
  Serial.println(scaled);
  return (int) scaled;
}



