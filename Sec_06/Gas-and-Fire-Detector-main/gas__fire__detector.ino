#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(13 , 12 , 11 ,10 ,9 ,8);
Servo myServo;

int GasPin = 2;     // MQ2
int FirePin = 3;    // Flame sensor
int buzzer = 4;
int ledRed = 7;
int ledGreen = 6;

void setup()
{
  pinMode(GasPin, INPUT);
  pinMode(FirePin, INPUT);
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  myServo.attach(5);

  lcd.begin(16, 2);
  lcd.clear();

  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  noTone(buzzer);
}

void loop() 
{
  bool gas  = (digitalRead(GasPin)  == HIGH);  
  bool fire = (digitalRead(FirePin) == HIGH);   


  if (gas && !fire)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gas Detected!");
    
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);

    tone(buzzer, 3000);
    delay(200);
    noTone(buzzer);

    delay(200);
  }

  else if (fire && !gas)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Fire Detected!");

    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);

    tone(buzzer, 3500);
    delay(150);

    servoMove();

    noTone(buzzer);
    delay(200);
  }

  else if (gas && fire)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gas + Fire !!!");

    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);

    tone(buzzer, 5000);
    delay(250);

    servoMove();
    
    noTone(buzzer);
    delay(200);
  }

  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Safe Now");

    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);

    noTone(buzzer);
    delay(300);
  }
}


void servoMove()
{
  for (int p = 0; p <= 90; p += 3)
  {
    myServo.write(p);
    delay(20);
  }
  for (int p = 90; p >= 0; p -= 3)
  {
    myServo.write(p);
    delay(20);
  }
}
