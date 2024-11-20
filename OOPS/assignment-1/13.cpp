// Program to calulate electricity bill using units
#include<iostream>
using namespace std;
struct Consumer {
    private:
    string name;
    int units ;
    double bill = 50;
    public:
    void getAndCalculate() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter units: ";
        cin >> units;

        if (units <= 100)
            bill += units * 0.6;
        else if (units > 100 && units <= 300)
            bill += 100 * 0.6 + (units - 100) * 0.8;
        else {
            bill += 100 * 0.6 + 200 * 0.8 + (units - 300) * 0.9;
            bill += bill * 0.15;
        }
    }
    void display() {
        cout << endl << "Name: " << name << endl;
        cout << "Units: " << units << endl;
        cout << "Bill: " << bill << endl;
    }
};
int main() {
    int n;
    cout << "Enter number of consumers: ";
    cin >> n;
    Consumer consumers[n];
    for (int i = 0; i < n; i++) {
        consumers[i].getAndCalculate();
    }
    for (int i = 0; i < n; i++) {
        consumers[i].display();
    }
    return 0;
}
