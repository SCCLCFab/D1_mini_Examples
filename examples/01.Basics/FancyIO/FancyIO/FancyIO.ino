/*
 * Basic IO
 * Use a pushbutton to toggle the onboard LED.
 *
 * Add a pushbutton or switch between D3 and GND. D3 and D4 have built-in
 * pullup resistors needed to make this work.
 */

int button1Pin = D3;  // pushbutton connected to digital pin D3, pullup
int button2Pin = D4;  // pushbutton connected to digital pin D4, pullup
int button3Pin = D8;  // pushbutton connected to digital pin D8, pulldown
int button4Pin = D7;  // pushbutton connected to digital pin D7, resistor needed
int outputPin = D6; // LED connected to D6
int button1Val = 0;        // variable to store the read value
int button2Val = 0;        // variable to store the read value
int button3Val = 0;        // variable to store the read value
int button4Val = 0;        // variable to store the read value

void setup() {
   // initialize serial communications at 9600 bps
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);  // set onboard LED as output
  pinMode(button1Pin, INPUT);      // set pin as input
  pinMode(button2Pin, INPUT);      // set pin as input
  pinMode(button3Pin, INPUT);      // set pin as input
  pinMode(button4Pin, INPUT);      // set pin as input
}

void loop() {
  button1Val = digitalRead(button1Pin);     // read the input pin
  Serial.print("Button 1 value: ");
  Serial.println(button1Val);
  button2Val = digitalRead(button2Pin);     // read the input pin
  Serial.print("Button 2 value: ");
  Serial.println(button2Val);
  button3Val = digitalRead(button3Pin);     // read the input pin
  Serial.print("Button 3 value: ");
  Serial.println(button3Val);
  button4Val = digitalRead(button4Pin);     // read the input pin
  Serial.print("Button 4 value: ");
  Serial.println(button4Val);
  digitalWrite(outputPin, button1Val);  // sets the LED to the button's value
  delay(500);
}

