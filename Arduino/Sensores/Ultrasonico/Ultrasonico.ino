const int triggerPin = 7;
const int echoPin = 6;
const int ledPin = 13;
unsigned long duration;
int distance;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000UL);
  distance = duration * 0.034 / 2; // Conversão para cm
  Serial.println(distance);

  digitalWrite(ledPin, duration > 0 && distance < 20 ? HIGH : LOW);
  delay(60);
}
