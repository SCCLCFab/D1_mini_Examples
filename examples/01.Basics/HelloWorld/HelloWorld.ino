/*
 * Hello World
 * Simply prints Hello World to the serial monitor.
 */

void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello WWillow and Alex.");
  delay(2000);
}
