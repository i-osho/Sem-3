// Program to determine steel strength
#include<iostream>
using namespace std;
int main() {
    int grade;
    float hardness, carbon, tensile;
    cout << "Enter hardness, carbon content and tensile strength: ";
    cin >> hardness >> carbon >> tensile;
    if (hardness > 50 && carbon < 0.7 && tensile > 5600) {
        grade = 10;
    } else if (hardness > 50 && carbon < 0.7) {
        grade = 9;
    } else if (carbon < 0.7 && tensile > 5600) {
        grade = 8;
    } else if (hardness > 50 && tensile > 5600) {
        grade = 7;
    } else if (hardness > 50 || carbon < 0.7 || tensile > 5600) {
        grade = 6;
    } else {
        grade = 5;
    }
    cout << "Grade of steel: " << grade;
    return 0;
}
