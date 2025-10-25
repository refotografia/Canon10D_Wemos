
int Trigger = 4;
int Meter = 5;

void setup() {
  // Declaring pins as outputs
  pinMode(Trigger, OUTPUT);
  pinMode(Meter, OUTPUT);

  // Turning off pins
  digitalWrite(Trigger, LOW);
  digitalWrite(Meter, LOW);
}

void loop() {
  // Delay should allow for an extra second inside takePhoto function
  delay(4000);
  takePhoto();
}

void takePhoto() {
  // Half-press (focus/meter)
  digitalWrite(Meter, HIGH);
  delay(500);

  // Full-press (trigger)
  digitalWrite(Trigger, HIGH);
  delay(500);

  // Release
  digitalWrite(Trigger, LOW);
  digitalWrite(Meter, LOW);
}
