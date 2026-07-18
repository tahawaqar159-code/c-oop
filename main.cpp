#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }
};

int main()
{
    Student s1("Taha", 19);

    s1.display();

    return 0;
}