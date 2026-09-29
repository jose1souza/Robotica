int poste = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  poste = analogRead(A0);
  if (poste < 550) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
  delay(10); 
}
