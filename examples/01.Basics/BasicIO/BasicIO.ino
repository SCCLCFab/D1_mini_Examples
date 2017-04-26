/*
 * Basic IO
 * Use a pushbutton to toggle the onboard LED.
 *
 * Add a pushbutton or switch between D3 and GND. D3 and D4 have built-in
 * pullup resistors needed to make this work.
 */

int inputPin = D2;  // pushbutton connected to digital pin D2
int val = 0;        // variable to store the read value

void setup() {
  pinMode(D5, OUTPUT);  // set onboard LED as output
  pinMode(inputPin, INPUT);      // set pin as input
}

void loop() {
  val = digitalRead(inputPin);     // read the input pin
  digitalWrite(D5, val);  // sets the LED to the button's value
}
