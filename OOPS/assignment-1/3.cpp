// Program to calculate gross salary of an employee
#include<iostream>
using namespace std;
int main() {
    float gross, basic, da, ta, hra;
    cout << "Enter basic salary: ";
    cin >> basic;
    da = 0.46 * basic;
    ta = 0.08 * basic;
    hra = 0.09 * basic;
    gross = basic + da + ta + hra;
    cout << "Gross salary is: " << gross;
    return 0;
}
