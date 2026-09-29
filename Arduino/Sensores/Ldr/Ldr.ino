const int ledPin = 10;
const int ldrPin = A0;
const int darknessThreshold = 500;

void setup() {
	pinMode(ledPin, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	const int lightLevel = analogRead(ldrPin);
	Serial.println(lightLevel);

	digitalWrite(ledPin, lightLevel < darknessThreshold ? HIGH : LOW);
	delay(100);
}
