
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define Motor 2
#define MotorTwo 4
#define BigMotor 7

#define potPin A0

#define ZERO 0 
#define ONE 1
#define TWO 2
#define THREE 3

int state;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
  
  Serial.begin(115200);
  pinMode(Motor, OUTPUT);
  pinMode(MotorTwo, OUTPUT);
  pinMode(BigMotor, OUTPUT);
  state = ZERO;
  Serial.begin(9600); //Set serial baud rate to 9600 bps
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop()
{
  int val;
  digitalWrite(Motor ,LOW);
  digitalWrite(MotorTwo ,LOW);
  digitalWrite(BigMotor ,LOW);
  val=analogRead(0);//Read Gas value from analog 0
  Serial.println(val,DEC);//Print the value to serial port
  lcd.print("C02:  ");
  lcd.print(val,DEC); 
  lcd.print("ppm");
  if (val<350)
  {
  lcd.setCursor(0,1);
  lcd.print("Low C02: OFF");
  }
    else if (val>350 && val<1000)
      {
      lcd.setCursor(0,1);
      lcd.print("Normal C02:  ON");
      digitalWrite(Motor ,HIGH);
      digitalWrite(MotorTwo ,HIGH);
      digitalWrite(BigMotor ,HIGH);     
      }
    else if (val >1000)
      {
    lcd.setCursor(0,1);
    lcd.print("High C02: ON");
    digitalWrite(Motor ,HIGH);
    digitalWrite(MotorTwo ,HIGH);
    digitalWrite(BigMotor ,HIGH);    
    } 
    
  delay(1000);
  lcd.clear();
}
