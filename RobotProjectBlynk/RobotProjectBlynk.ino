#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "WEMOS_Motor.h"

int pwm;

//********************* COMPLETE WITH YOUR DETAILS *************
// Get Auth Token in the Blynk App.
char cloudserver[16] = "blynk-cloud.com";
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
// MCL: token for esptest with ESP8266
char auth[] = "c1e204f1c7f746cc867610400b470456";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SCCLC Guest";
char pass[] = "";
//****************

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30,_MOTOR_A, 1000);//Motor A
Motor M2(0x30,_MOTOR_B, 1000);//Motor B


void setup() {
 Serial.begin(9600);
 Serial.println("before blynk.begin");
  Blynk.begin(auth, ssid, pass);
 Serial.println("after blynk.begin");
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1) {

  for (pwm = 0; pwm <= 100; pwm++)
  {
    M1.setmotor( _CW, pwm);
    M2.setmotor(_CW, 100-pwm);
    Serial.printf("A:%d%, B:%d%, DIR:CW\r\n", pwm,100-pwm);
  }
  
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);
  Serial.println("Motor A&B STOP");
  delay(200);
}

BLYNK_WRITE(V2) {
  
  for (pwm = 0; pwm <=100; pwm++)
  {
    M1.setmotor(_CCW, pwm);
    M2.setmotor(_CCW, 100-pwm);
    Serial.printf("A:%d%, B:%d%, DIR:CCW\r\n", pwm,100-pwm);

  }
  
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);
  delay(200);
  Serial.println("Motor A&B STOP");

  M1.setmotor(_SHORT_BRAKE);
  M2.setmotor( _SHORT_BRAKE);
  Serial.println("Motor A&B SHORT BRAKE");  
  delay(1000);
  
  M1.setmotor(_STANDBY);//Both Motor standby
  //M2.setmotor( _STANDBY);
  Serial.println("Motor A&B STANDBY");  
  delay(1000);
  
}
