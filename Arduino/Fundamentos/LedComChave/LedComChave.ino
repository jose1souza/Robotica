void setup()
{
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  if (digitalRead(3) == HIGH) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  delay(10);
}
