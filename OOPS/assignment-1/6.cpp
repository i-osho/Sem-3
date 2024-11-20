// Variations of for, while, and do-while loops
#include<iostream>
using namespace std;
int main() {
    // normal for loop
    cout << "For loop" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << "\t";
    }

    // for loop without initialization
    cout << endl << endl << "For loop without initialization" << endl;
    int j = 0;
    for ( ; j<  10; j++) {
        cout << j << "\t";
    }

    // for loop without initialization and increment
    cout << endl << endl << "For loop without initialization and increment" << endl;
    int k = 0;
    for ( ; k < 10; ) {
        cout << k << "\t";
        k++;
    }

    // while loop
    cout << endl << endl << "while loop" << endl;
    int l = 0;
    while (l < 10) {
        cout << l << "\t";
        l++;
    }

    // do-while loop
    cout << endl << endl << "do-while loop" << endl;
    int m = 0;
    do {
        cout << m << "\t";
        m++;
    } while (m < 10);

    // do-while loop like operation without do
    cout << endl << endl << "do-while loop like operation without do" << endl;
    int n = 0;
    while (true)
    {
        cout << n << "\t";
        n++;
        if (n >= 10)
            break;
    }
    return 0;
}