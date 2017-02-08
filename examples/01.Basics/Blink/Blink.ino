/*
 * Blink
 * Turns on the onboard LED on for one second, then off for one second, repeatedly.
 * This uses delay() to pause between LED toggles.
 */

void setup() {
  pinMode(D6, OUTPUT);  // initialize onboard LED as output
}

void loop() {
  digitalWrite(D6, HIGH);  // turn on LED with voltage HIGH
  delay(1000);                      // wait one second
  digitalWrite(D6, LOW);   // turn off LED with voltage LOW
  delay(1000);                      // wait one second
}
