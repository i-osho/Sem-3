#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Constructor of A" << endl;
    }
    void displayA()
    {
        cout << "Class A: displayA" << endl;
    }
};

class B : virtual public A
{
public:
    B()
    {
        cout << "Constructor of B" << endl;
    }
    void displayB()
    {
        cout << "Class B: displayB" << endl;
    }
};

class C : virtual public A
{
public:
    C()
    {
        cout << "Constructor of C" << endl;
    }
    void displayC()
    {
        cout << "Class C: displayC" << endl;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "Constructor of D" << endl;
    }
    void displayD()
    {
        cout << "Class D: displayD" << endl;
    }
};

int main()
{
    D obj;
    obj.displayA();
    obj.displayB();
    obj.displayC();
    obj.displayD();

    return 0;
}
