// Demostration of public and private access specifiers
#include <iostream>
using namespace std;

struct osho
{
    private:
    int data;
    void priv()
    {
        cout << "This is a private function inside the structure." << endl;
        data = 42;
    }

    int getData()
    {
        return data;
    }

    public:
    void pub()
    {
        cout << "Calling private function from public function inside a structure." << endl;
        priv();
        int result = getData();
        cout << "Data after private function call: " << result << endl;
    }
};

int main()
{
    osho test;
    test.pub();
    return 0;
}
