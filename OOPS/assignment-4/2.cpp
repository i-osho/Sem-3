#include <iostream>
#include <cstring>
using namespace std;

class X
{
protected:
    char strX[50];

public:
    X(const char *str)
    {
        strcpy(strX, str);
        cout << "Constructor of X called: " << strX << endl;
    }
    ~X()
    {
        cout << "Destructor of X called: " << strX << endl;
    }
};

class Y
{
protected:
    char strY[50];

public:
    Y(const char *str)
    {
        strcpy(strY, str);
        cout << "Constructor of Y called: " << strY << endl;
    }
    ~Y()
    {
        cout << "Destructor of Y called: " << strY << endl;
    }
};

class Z : public X, public Y
{
private:
    char strZ[100];

public:
    Z(const char *str1, const char *str2) : X(str1), Y(str2)
    {
        strcpy(strZ, strX);
        strcat(strZ, strY);
        cout << "Constructor of Z called: " << strZ << endl;
    }
    void displayStrings()
    {
        cout << "String from X: " << strX << endl;
        cout << "String from Y: " << strY << endl;
        cout << "Concatenated String in Z: " << strZ << endl;
    }
    ~Z()
    {
        cout << "Destructor of Z called: " << strZ << endl;
    }
};

int main()
{
    Z obj("Hello, ", "World!");
    obj.displayStrings();
    return 0;
}
