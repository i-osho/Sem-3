#include<iostream>
using namespace std;

double power(double x, int n=2) {
    double result = 1.0;
    for(int i=0; i<n; i++) {
        result *= x;
    }
    return result;
}

int main() {
    double x;
    int n;
    cout << "Enter number: ";
    cin >> x;
    cout << "Enter power: ";
    cin >> n;
    cout << "Result with default power: " << power(x) << endl;
    cout << "Result with user defined power: " << power(x, n) << endl;
    return 0;
}
