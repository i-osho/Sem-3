// Program to calculate sin(x) using Taylor series expansion
#include <iostream>
#include <cmath> // without this output was coming nan
int main() {
    double x, term, sum;
    int n = 1;
    std::cout << "Enter the value of x (in radians): ";
    std::cin >> x;
    sum = x;
    term = x;
    do {
        term *= -1 * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    } while (fabs(term) > fabs(sum * 0.000001));
    std::cout << "Calculated sin(x): " << sum << std::endl;
    return 0;
}

