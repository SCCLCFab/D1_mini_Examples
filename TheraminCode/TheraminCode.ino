
int speakerPin = D6;
int photocellPin = A0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int reading = analogRead(photocellPin);
  int pitch = 200 + reading / 4;
  tone(speakerPin, pitch);

}
