#include <iostream>
using namespace std;

struct Library
{
private:
    int days;
    float fine;

public:
    void getDays(int d)
    {
        days = d;
        calculateFine();
    }

    void calculateFine()
    {
        if (days > 30)
        {
            cout << "Your membership has been cancelled." << endl;
        }
        else if (days > 10)
        {
            fine = (days - 10) * 5 + 5 * 1 + 5 * 0.5;
        }
        else if (days > 5)
        {
            fine = (days - 5) * 1 + 5 * 0.5;
        }
        else
        {
            fine = days * 0.5;
        }
    }

    void displayFine()
    {
        if (days <= 30)
        {
            cout << "The fine is: " << fine << " rupees." << endl;
        }
    }
};

int main()
{
    Library lib;
    int days;

    cout << "Enter the number of days late book was returned: ";
    cin >> days;

    lib.getDays(days);
    lib.displayFine();

    return 0;
}
