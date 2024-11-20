#include<iostream>
using namespace std;

double area(double l=1.0, double b=1.0) {
    return l*b;
}

int main() {
    double l, b;
    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of rectangle with default arguments: " << area() << endl;
    cout << "Area of rectangle with user defined arguments: " << area(l, b) << endl;
    return 0;
}