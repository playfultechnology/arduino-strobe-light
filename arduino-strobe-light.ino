// CONSTANTS
const byte potPin = A0;
const byte strobePin = 3;

void setup() {
  pinMode(strobePin, OUTPUT);
}

void loop() {
  // Analog red gives a value between 0-1023
  int potValue = analogRead(potPin);
  // Convert this to a sensible range of values for the strobe delay
  // 50Hz = 20ms between flashes
  int refreshRate = map(potValue, 0, 1023, 100, 1);
  
  // Turn the strobe LED on
  digitalWrite(strobePin, HIGH);
  delayMicroseconds(refreshRate);
  // Turn it off again
  digitalWrite(strobePin, LOW);
  delayMicroseconds(refreshRate);
}
