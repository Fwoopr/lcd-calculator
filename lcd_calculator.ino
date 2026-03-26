#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
float num1;
float num2;
float answer;
String op;
String space=" ";
String equals=" =";

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.home();
  lcd.print("Enter your");
  lcd.setCursor(0, 1);
  lcd.print("first number:");
  while (Serial.available()==0) {
    lcd.blink();
  }
  num1 = Serial.parseFloat();
  lcd.clear();

  lcd.home();
  lcd.print("Enter operator:");
  lcd.setCursor(0, 1);
  lcd.print("(+,-,*,/)");
  while (Serial.available()==0) {
    lcd.blink();
  }
  op = Serial.readString();
  lcd.clear();

  lcd.home();
  lcd.print("Enter your");
  lcd.setCursor(0, 1);
  lcd.print("second number:");
  while (Serial.available()==0) {
    lcd.blink();
  }
  num2 = Serial.parseFloat();
  lcd.clear();
  lcd.noBlink();

  if (op == "+") {
    answer = num1 + num2;
  }
  if (op == "-") {
    answer = num1 - num2;
  }
  if (op == "*") {
    answer = num1 * num2;
  }
  if (op == "/") {
    answer = num1 / num2;
  }

  lcd.home();
  lcd.print(num1+space+op+space+num2+equals);
  lcd.setCursor(0, 1);
  lcd.print(answer);
  delay(2500);
}
