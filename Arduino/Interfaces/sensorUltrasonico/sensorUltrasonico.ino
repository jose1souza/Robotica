#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH, 30000UL);
}

void setup()
{
  lcd_1.begin(16, 2);

  lcd_1.clear();
  lcd_1.print("### IFMG ###");
  delay(2000); 
  lcd_1.clear();
}

void loop()
{
  const long duration = readUltrasonicDistance(2, 3);
  lcd_1.setCursor(0, 0);
  lcd_1.print("                ");
  lcd_1.setCursor(0, 0);
  if (duration == 0) {
    lcd_1.print("Sem eco");
  } else {
    lcd_1.print("D = ");
    lcd_1.print(0.01723 * duration);
    lcd_1.print(" cm");
  }
  delay(60);
}
