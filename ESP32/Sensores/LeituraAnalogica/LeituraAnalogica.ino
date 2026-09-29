const int analogPin = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  const uint32_t voltageMillivolts = analogReadMilliVolts(analogPin);
  Serial.print("GPIO 34: ");
  Serial.print(voltageMillivolts);
  Serial.println(" mV");
  delay(500);
}