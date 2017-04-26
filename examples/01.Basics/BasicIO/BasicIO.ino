/*
 * Basic IO
 * Use a pushbutton to toggle the onboard LED.
 *
 * Add a pushbutton or switch between D3 and GND. D3 and D4 have built-in
 * pullup resistors needed to make this work.
 */

int inputPin = D3;  // pushbutton connected to digital pin D3
int val = 0;        // variable to store the read value

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);  // set onboard LED as output
  pinMode(inputPin, INPUT);      // set pin as input
}

void loop() {
  val = digitalRead(inputPin);     // read the input pin
  digitalWrite(BUILTIN_LED, val);  // sets the LED to the button's value
}
