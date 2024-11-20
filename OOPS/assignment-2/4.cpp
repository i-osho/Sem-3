#include<iostream>
using namespace std;

class Student
{
    private:
    string Name, Degree, Hostel;
    int RollNo;
    float CurrentCGPA;
    public:
    void addDetails()
    {
        cout<<"Enter the name of the student: ";
        cin>>Name;
        cout<<"Enter the degree of the student: ";
        cin>>Degree;
        cout<<"Enter the roll number of the student: ";
        cin>>RollNo;
        cout<<"Enter the current CGPA of the student: ";
        cin>>CurrentCGPA;
        cout<<"Enter the hostel of the student: ";
        cin>>Hostel;
    }
    void updateDetails()
    {
        int choice;
        cout<<"Enter which attibute to be updated: \n";
        cout<<"1. Name\n";
        cout<<"2. Degree\n";
        cout<<"3. Roll Number\n";
        cout<<"4. Current CGPA\n";
        cout<<"5. Hostel\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the new name: ";
            cin>>Name;
            break;
            case 2:
            cout<<"Enter the new degree: ";
            cin>>Degree;
            break;
            case 3:
            cout<<"Enter the new roll number: ";
            cin>>RollNo;
            break;
            case 4:
            cout<<"Enter the new CGPA: ";
            cin>>CurrentCGPA;
            break;
            case 5:
            cout<<"Enter the new hostel: ";
            cin>>Hostel;
            break;
            default:
            cout<<"Invalid choice\n";
        }
    }
    void updateCGPA()
    {
        cout<<"Enter the new CGPA: ";
        cin>>CurrentCGPA;
    }
    void updateResidenceInfo()
    {
        cout<<"Enter the new hostel: ";
        cin>>Hostel;
    }
    void displaydetails()
    {
        cout<<"Name: "<<Name<<endl;
        cout<<"Degree: "<<Degree<<endl;
        cout<<"Roll Number: "<<RollNo<<endl;
        cout<<"Current CGPA: "<<CurrentCGPA<<endl;
        cout<<"Hostel: "<<Hostel<<endl;
    }
};

int main() {
    Student s1;
    s1.addDetails();
    s1.displaydetails();
    s1.updateDetails();
    s1.displaydetails();
    s1.updateCGPA();
    s1.displaydetails();
    s1.updateResidenceInfo();
    s1.displaydetails();
    return 0;
}