// Program to calculate sum of series
#include <iostream>
using namespace std;
int main()
{
    double term, sum, accuracy = 0.000001;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    sum = 1.0;
    do
    {
        term = 1.0;
        for (int i = 0; i < n; ++i)
        {
            term /= n;
        }
        sum += term;
        n++;
    } 
    while (term > sum * accuracy || term < -sum * accuracy);
    cout << "Calculated SUM: " << sum << endl;
    return 0;
}
