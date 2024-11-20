#include <iostream>
#include <cmath>

using namespace std;

class Rectangle;

class Polar
{
    float radius;
    float angle;

public:
    Polar() : radius(0), angle(0) {}
    Polar(float r, float theta) : radius(r), angle(theta) {}

    float getRadius() const { return radius; }
    float getAngle() const { return angle; }

    void display() const
    {
        cout << "Polar Coordinates: (radius: " << radius << ", angle: " << angle << ")" << endl;
    }
    Polar(const Rectangle &rect);
};

class Rectangle
{
    float xCoord;
    float yCoord;

public:
    Rectangle() : xCoord(0), yCoord(0) {}
    Rectangle(float x, float y) : xCoord(x), yCoord(y) {}

    float getX() const { return xCoord; }
    float getY() const { return yCoord; }

    void display() const
    {
        cout << "Rectangle Coordinates: (x: " << xCoord << ", y: " << yCoord << ")" << endl;
    }
    Rectangle(const Polar &polar)
    {
        xCoord = polar.getRadius() * cos(polar.getAngle());
        yCoord = polar.getRadius() * sin(polar.getAngle());
    }
};

Polar::Polar(const Rectangle &rect)
{
    radius = sqrt(rect.getX() * rect.getX() + rect.getY() * rect.getY());
    angle = atan2(rect.getY(), rect.getX());
}

int main()
{
    Rectangle rect(3, 4);
    rect.display();

    Polar polar = rect;
    polar.display();

    Rectangle rect2 = polar;
    rect2.display();

    return 0;
}