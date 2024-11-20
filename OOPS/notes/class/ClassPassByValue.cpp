#include<iostream>
using namespace std;

class Demo {
    int x,y;
    public:
    void getdata(int a, int b) {
        x = a, y = b;
    }
    void display() {
        cout << "x : " << x << " y : " << y << endl;
    }
    void swap(Demo d) {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }
};
int main() {
    Demo d1;
    d1.getdata(10, 20);
    d1.display();
    d1.swap(d1);
    d1.display();
    return 0;
}