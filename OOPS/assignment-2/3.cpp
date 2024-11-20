#include<iostream>
using namespace std;

inline double cube(double s) {
    return s * s * s;
}

int main() {
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The cube of " << num << " is " << cube(num) << endl;
    return 0;
}