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
        cout << "\n----------------------------------\n";
        cout << "ID         : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Department : " << department << endl;
        cout << "CGPA       : " << cgpa << endl;
        cout << "----------------------------------\n";
    }
};

int main()
{
    Student students[100];
    int totalStudents = 0;
    int choice;

    do
    {
        cout << "\n========== Student Management System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (totalStudents < 100)
            {
                students[totalStudents].addStudent();
                totalStudents++;
                cout << "\nStudent Added Successfully!\n";
            }
            else
            {
                cout << "\nStudent limit reached!\n";
            }
            break;

        case 2:
            if (totalStudents == 0)
            {
                cout << "\nNo students found.\n";
            }
            else
            {
                for (int i = 0; i < totalStudents; i++)
                {
                    students[i].displayStudent();
                }
            }
            break;

        case 3:
            cout << "\nThank you for using the Student Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 3);

    return 0;
}