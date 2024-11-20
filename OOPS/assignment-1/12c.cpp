#include <iostream>
#include <cmath> // without this output was coming nan
using namespace std;

int main()
{
    double x, term, sum, accuracy = 0.000001;
    int n = 1;
    cout << "Enter the value of x (in radians): ";
    cin >> x;
    sum = 1.0;
    term = 1.0;
    do
    {
        term *= -1 * x * x / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }
    while (fabs(term) >= accuracy * fabs(sum));
    cout << "Calculated cos(x): " << sum << endl;
    return 0;
}
