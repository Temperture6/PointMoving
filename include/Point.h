#include <MaxMatrix.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int CLK = 7; // CLK pin of MAX7219 module
int CS = 6;  // CS pin of MAX7219 module
int DIN = 5; // DIN pin of MAX7219 module
MaxMatrix m(DIN, CS, CLK, 1);
LiquidCrystal_I2C lcd(0x27, 8, 1);

class Point
{
private:
    int x = 0;
    int y = 0;
public:
    Point();
    ~Point();

    void up();
    void down();
    void left();
    void right();
    void showinfo();
    void reset();
};

Point::Point()
{
    m.init(); //初始化点阵屏
    m.setIntensity(1);
    m.setDot(x, y, 1);
}

Point::~Point()
{
}

void Point::up()
{
    if (y == 0)
    {
        return;
    }
    else
    {
        m.setDot(x, y, 0);
        y--;
        m.setDot(x, y, 1);
    }
}

void Point::down()
{
    if (y == 7)
    {
        return;
    }
    else
    {
        m.setDot(x, y, 0);
        y++;
        m.setDot(x, y, 1);
    }
}

void Point::left()
{
    if (x == 0)
    {
        return;
    }
    else
    {
        m.setDot(x, y, 0);
        x--;
        m.setDot(x, y, 1);
    }
}

void Point::right()
{
    if (x == 7)
    {
        return;
    }
    else
    {
        m.setDot(x, y, 0);
        x++;
        m.setDot(x, y, 1);
    }
}

void Point::showinfo()
{
    lcd.print("X:");
    lcd.print(x + 1);
    lcd.print("    ");
    lcd.print("Y:");
    lcd.print(y + 1);
    lcd.print("      ");
}

void Point::reset()
{
    m.setDot(x, y, 0);
    x = 0; y = 0;
    m.setDot(x, y, 1);
    showinfo();
}