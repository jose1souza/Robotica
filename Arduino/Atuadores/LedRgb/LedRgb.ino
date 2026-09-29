void setup()
{
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  analogWrite(3, 255);
  analogWrite(6, 204);
  analogWrite(5, 153);
  delay(2200); 
  analogWrite(3, 255);
  analogWrite(6, 255);
  analogWrite(5, 102);
  delay(800);
  analogWrite(3, 255);
  analogWrite(6, 0);
  analogWrite(5, 0);
  delay(2200); 
}
