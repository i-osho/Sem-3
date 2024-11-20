#include <iostream>
using namespace std;

class Base
{
public:
    int publicVar = 1;

protected:
    int protectedVar = 2;

private:
    int privateVar = 3;
};

class PublicDerived : public Base
{
public:
    void display()
    {
        cout << "PublicDerived:\n";
        cout << "Public: " << publicVar << endl;
        cout << "Protected: " << protectedVar << endl;
        cout << "Private: " << "Not Accessible" << endl;
    }
};

class ProtectedDerived : protected Base
{
public:
    void display()
    {
        cout << "ProtectedDerived:\n";
        cout << "Public (now Protected): " << publicVar << endl;
        cout << "Protected: " << protectedVar << endl;
        cout << "Private: " << "Not Accessible" << endl;
    }
};

class PrivateDerived : private Base
{
public:
    void display()
    {
        cout << "PrivateDerived:\n";
        cout << "Public (now Private): " << publicVar << endl;
        cout << "Protected (now Private): " << protectedVar << endl;
        cout << "Private: " << "Not Accessible" << endl;
    }
};

int main()
{
    PublicDerived pubObj;
    pubObj.display();
    cout << "Accessing Public Var in PublicDerived: " << pubObj.publicVar << "\n\n";

    ProtectedDerived protObj;
    protObj.display();

    PrivateDerived privObj;
    privObj.display();

    return 0;
}
