#include <iostream>
using namespace std;

class Polygon
{
protected:
    double width;
    double height;

public:
    void set_values(double w, double h)
    {
        width = w;
        height = h;
    }
    virtual void calculate_area() {}
    virtual ~Polygon() {}
};

class Rectangle : public Polygon
{
public:
    void calculate_area() override
    {
        double area = width * height;
        cout << "Rectangle Area: " << area << endl;
    }
};

class Triangle : public Polygon
{
public:
    void calculate_area() override
    {
        double area = 0.5 * width * height;
        cout << "Triangle Area: " << area << endl;
    }
};

int main()
{
    Polygon *polyPtr;
    Rectangle rect;
    Triangle tri;

    polyPtr = &rect;
    polyPtr->set_values(10.0, 5.0);
    cout << "Using Base Pointer for Rectangle:" << endl;
    polyPtr->calculate_area();

    polyPtr = &tri;
    polyPtr->set_values(10.0, 5.0);
    cout << "Using Base Pointer for Triangle:" << endl;
    polyPtr->calculate_area();

    return 0;
}
