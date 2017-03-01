#define echoPin D7 // Echo Pin
#define trigPin D6 // Trigger Pin
 
double distInCm; 
 
void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{
  distInCm = readDistance();
  Serial.print("Distance: ");
  Serial.print(distInCm);
  Serial.println(" cm.");
  //Delay 50ms before next reading.
  delay(50);
}

double readDistance()
{
  double distance, duration; // Duration used to calculate distance
  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
  return distance;
}

