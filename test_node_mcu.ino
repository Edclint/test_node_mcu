// LED pin
int ledPin = 4;
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  // OFF
  digitalWrite(ledPin, LOW);
  delay(1000);
  // ON
  digitalWrite(ledPin, HIGH);
  delay(2000);
}
