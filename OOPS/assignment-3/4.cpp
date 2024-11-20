#include<iostream>
using namespace std;

class FLOAT {
private:
    float num;
public:
    FLOAT() {
        num = 0;
    }
    FLOAT(float x) {
        num = x;
    }
    FLOAT operator +(FLOAT f) {
        FLOAT temp;
        temp.num = num + f.num;
        return temp;
    }
    FLOAT operator -(FLOAT f) {
        FLOAT temp;
        temp.num = num - f.num;
        return temp;
    }
    FLOAT operator *(FLOAT f) {
        FLOAT temp;
        temp.num = num * f.num;
        return temp;
    }
    FLOAT operator /(FLOAT f) {
        FLOAT temp;
        temp.num = num / f.num;
        return temp;
    }
    void print() {
        cout << num << endl;
    }
};

int main() {
    FLOAT f1(10.5), f2(5.5), f3;
    f3 = f1 + f2;
    f3.print();
    f3 = f1 - f2;
    f3.print();
    f3 = f1 * f2;
    f3.print();
    f3 = f1 / f2;
    f3.print();
    return 0;
}