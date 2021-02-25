#include <Arduino.h>
#include "Point.h"

Point p; //声明点类

int vx = 0;
int vy = 0;
int ms;
int speed = 100;

void setup()
{
  pinMode(A0, INPUT); //X
  pinMode(A1, INPUT); //Y
  pinMode(A2, INPUT); //按下
  lcd.init();
  lcd.backlight();
}

void loop()
{
  vx = analogRead(A0);
  vy = analogRead(A1);
  ms = analogRead(A2);

  if (vy > 874)
  {
    p.right();
    delay(speed);
  }
  else if (vy < 150)
  {
    p.left();
    delay(speed);
  }
  else if (vx < 150)
  {
    p.down();
    delay(speed);
  }
  else if (vx > 874)
  {
    p.up();
    delay(speed);
  }
  else if (ms == LOW)
  {
    p.reset();
    delay(speed);
  }
  p.showinfo();
}
