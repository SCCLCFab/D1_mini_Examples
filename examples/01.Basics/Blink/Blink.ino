/*
 * Blink
 * Turns on the onboard LED on for one second, then off for one second, repeatedly.
 * This uses delay() to pause between LED toggles.
 */

void setup() {
  pinMode(D3, OUTPUT);  // initialize onboard LED as output
}

void loop() {
  digitalWrite(D3, HIGH);  // turn on LED with voltage HIGH
  delay(10000);                      // wait one second
  digitalWrite(D3, LOW);   // turn off LED with voltage LOW
  delay(10000);                      // wait one second
}
