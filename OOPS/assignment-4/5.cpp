#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int rollNo;

public:
    virtual void get_data() = 0;
    virtual void display_data() = 0;
    virtual ~Student() {}
};

class Engineering : public Student
{
private:
    string department;

public:
    void get_data() override
    {
        cout << "Enter name of Engineering student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter department: ";
        cin >> department;
    }

    void display_data() override
    {
        cout << "Engineering Student:\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Department: " << department << endl;
    }
};

class Medicine : public Student
{
private:
    string specialization;

public:
    void get_data() override
    {
        cout << "Enter name of Medicine student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter specialization: ";
        cin >> specialization;
    }

    void display_data() override
    {
        cout << "Medicine Student:\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Specialization: " << specialization << endl;
    }
};

class Science : public Student
{
private:
    string field;

public:
    void get_data() override
    {
        cout << "Enter name of Science student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter field: ";
        cin >> field;
    }

    void display_data() override
    {
        cout << "Science Student:\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Field: " << field << endl;
    }
};

int main()
{
    const int NUM_STUDENTS = 3;
    Student *students[NUM_STUDENTS];

    students[0] = new Engineering();
    students[1] = new Medicine();
    students[2] = new Science();

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i]->get_data();
    }

    cout << "\nDisplaying student details:\n";
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        students[i]->display_data();
    }

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        delete students[i];
    }

    return 0;
}
