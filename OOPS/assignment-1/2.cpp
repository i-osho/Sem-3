// Program to convert Celsius to Fahrenheit
#include<iostream>
using namespace std;
int main() {
    float c, f;
    cout << "Enter the temperature in Celsius: ";
    cin >> c;
    f = (c * 9.0 / 5.0) + 32;
    cout << "Temperature in Fahrenheit is: " << f;
    return 0;
}