const int triggerPin = 5;
const int echoPin = 18;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  const unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);
  if (duration == 0) {
    Serial.println("Sem eco");
  } else {
    const float distanceCm = duration * 0.0343f / 2.0f;
    Serial.print("Distancia: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  delay(100);
}