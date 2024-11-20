#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imaginary;

public:
    void set(float r, float i)
    {
        real = r;
        imaginary = i;
    }

    void display()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    Complex sum(Complex c)
    {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }
};

int main()
{
    Complex c1, c2, c3;
    c1.set(3.2, 4.5);
    c2.set(1.3, 2.1);
    c3 = c1.sum(c2);

    c1.display();
    c2.display();
    c3.display();

    return 0;
}
