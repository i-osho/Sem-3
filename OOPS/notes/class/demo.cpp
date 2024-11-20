#include<iostream>
using namespace std;

class Marks {
    private:
    int DM, DAA, DCCN, OOPS, AI;
    public:
    void getMarks() {
        cout << "Enter marks in DM: ";
        cin >> DM;
        cout << "Enter marks in DAA: ";
        cin >> DAA;
        cout << "Enter marks in DCCN: ";
        cin >> DCCN;
        cout << "Enter marks in OOPS: ";
        cin >> OOPS;
        cout << "Enter marks in AI: ";
        cin >> AI;
    }
};
class Address {
    private:
    string house, street, city;
    int pincode;
    public:
    void getAddress() {
        cout << "Enter house number: ";
        cin >> house;
        cout << "Enter street: ";
        cin >> street;
        cout << "Enter city: ";
        cin >> city;
        cout << "Enter pincode: ";
        cin >> pincode;
    }
};
class Student {
    private:
    string fname, lname;
    int roll;
    public:
    Marks marks;
    Address address;
};

int main() {
    Student s;
    s.marks.getMarks();

    return 0;
}