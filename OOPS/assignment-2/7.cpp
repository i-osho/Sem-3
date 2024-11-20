#include <iostream>
using namespace std;

class Obj
{
    private:
        static int count;
    public:
        void create() {
            count++;
        }

        void display() {
            cout << "Total objects created: " << count << endl;
        }
};
int Obj::count = 0;
int main()
{
    Obj obj1, obj2, obj3;
    obj1.create();
    obj2.create();
    obj3.create();
    obj3.display();
    return 0;
}
