// Program to calulate fine
#include<iostream>
using namespace std;
int main() {
    int days;
    float fine=0;
    cout << "Enter number of days: ";
    cin >> days;
    if (days <= 5) {
        fine = 0.5 * days;
    } else if (days <= 10) {
        fine = 0.5 * 5 + 1 * (days - 5);
    } else if (days <= 30) {
        fine = 0.5 * 5 + 1 * 5 + 5 * (days - 10);
    } else {
        cout << "Membership cancelled" << endl;
    }
    if (fine != 0)
        cout << "Fine: " << fine << endl;
    return 0;
}
