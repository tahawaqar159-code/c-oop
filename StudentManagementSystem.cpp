#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int id;
    string name;
    int age;
    string department;
    float cgpa;

public:
    Student()
    {
        id = 0;
        name = "";
        age = 0;
        department = "";
        cgpa = 0.0;
    }

    void addStudent()
    {
        cout << "\nEnter Student ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void displayStudent()
    {
        cout << "\n-----------------------------\n";
        cout << "Student ID : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Department : " << department << endl;
        cout << "CGPA       : " << cgpa << endl;
        cout << "-----------------------------\n";
    }
};

int main()
{
    Student s;

    s.addStudent();

    cout << "\nStudent Record\n";
    s.displayStudent();

    return 0;
}