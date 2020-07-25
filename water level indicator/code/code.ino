/*

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  LiquidCrystal.h ---  Library originally added 18 Apr 2008
  by David A. Mellis
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 6;

long duration;
int distance;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // TODO: min distance is 50 , change this value in production after calibration.
  if ( distance <= 50 )
  {
    tone(buzzer, 2000); // Send 2KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
    //digitalWrite(ledRed, HIGH);
    delay(500);
    //digitalWrite(ledRed, LOW);
    delay(500);

  }


  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  // TODO: min distance is 50 , change this value in production after calibration.
  lcd.print("Min level:50.0 cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Cur level:");
  lcd.print(distance);
  lcd.print(" cm");
  delay(10);
}
