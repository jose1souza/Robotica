const int tempSensorPin = A1;
const int ledPin = 2;
const int threshold = 600;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const int sensorValue = analogRead(tempSensorPin);
  Serial.println(sensorValue);
  digitalWrite(ledPin, sensorValue > threshold ? HIGH : LOW);
  delay(100);
}
