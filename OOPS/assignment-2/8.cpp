#include <iostream>
using namespace std;
class Obj
{
private:
    static int count;
public:
    static void create() {
        count++;
    }

    static void display() {
        cout << "Total objects created: " << count << endl;
    }
};
int Obj::count = 0;
int main()
{
    Obj::create();
    Obj::create();
    Obj::create();
    Obj::display();
    return 0;
}
