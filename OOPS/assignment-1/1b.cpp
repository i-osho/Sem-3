// Implemention of control characters : \n, \t, \r, \a
#include<iostream>
using namespace std;
int main() {
    cout << "This is a" << endl << "new line using endl" << endl;
    cout << "This is a \t tab using \\t" << endl;
    cout << "This is carriage return using \\r \r";
    cout << "Cursor returned" << endl;
    cout << "THis is a alert sound using \\a \a";
    return 0;
}
