#include <iostream>
#include <cmath>

using namespace std;

class Polar
{
    float r;
    float theta;

public:
    Polar()
    {
        r = 0;
        theta = 0;
    }
    Polar(float x, float y)
    {
        r = x;
        theta = y;
    }
    void display()
    {
        cout << "radius: " << r << " theta: " << theta << endl;
    }
    Polar operator+(Polar p)
    {
        float x1 = r * cos(theta);
        float y1 = r * sin(theta);
        float x2 = p.r * cos(p.theta);
        float y2 = p.r * sin(p.theta);

        float x = x1 + x2;
        float y = y1 + y2;

        Polar temp;
        temp.r = sqrt(x * x + y * y);
        temp.theta = atan2(y, x);
        return temp;
    }
};

int main()
{
    Polar p1(5, 0.927295);
    Polar p2(3, 0.643501);

    Polar p3 = p1 + p2;
    p3.display();
    p3 = p2 + p3;
    p3.display();

    return 0;
}