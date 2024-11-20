// Demostration of structure
#include<iostream>
using namespace std;
struct Student {
    private:
    string name, degree, hostel;
    int roll;
    float cgpa;

    public:
    void addDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter degree: ";
        cin >> degree;
        cout << "Enter hostel: ";
        cin >> hostel;
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter cgpa: ";
        cin >> cgpa;
    }

    void updateDetails() {
        cout << "Updating Details for roll no: " << roll << endl;
        cout << "Which detail you want to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Degree" << endl;
        cout << "3. Hostel" << endl;
        cout << "4. Cgpa" << endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                break;
            case 2:
                cout << "Enter degree: ";
                cin >> degree;
                break;
            case 3:
                cout << "Enter hostel: ";
                cin >> hostel;
                break;
            case 4:
                cout << "Enter cgpa: ";
                cin >> cgpa;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    void updateCGPA() {
        cout << "Updating CGPA for " << roll << " " << name << endl;
        cout << "Enter new cgpa: ";
        cin >> cgpa;
    }

    void updateResidence() {
        cout << "Updating Residence for " << roll << " " << name << endl;
        cout << "Enter new hostel: ";
        cin >> hostel;
    }

    void displayDetails() {
        cout << endl <<"Name: " << name << endl;
        cout << "Degree: " << degree << endl;
        cout << "Hostel: " << hostel << endl;
        cout << "Roll: " << roll << endl;
        cout << "Cgpa: " << cgpa << endl;
    }
};

int main() {
    Student s1, s2;
    s1.addDetails();
    s2.addDetails();
    s1.updateDetails();
    s2.updateCGPA();
    s2.updateResidence();
    s1.displayDetails();
    s2.displayDetails();
    return 0;
}
