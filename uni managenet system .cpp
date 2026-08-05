
#include <iostream>
#include <string>
using namespace std;
 
const int MAX_STUDENTS  = 50;
const int MAX_PROFESSORS = 20;
const int MAX_COURSES    = 30;
 
// ==================================================
// Base class: Person
// ==================================================
class Person {
protected:
    int id;
    string name;
    int age;
 
public:
    Person() : id(0), age(0) {}
    Person(int id, string name, int age) : id(id), name(name), age(age) {}
 
    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Age: " << age;
    }
 
    int getId() const { return id; }
    string getName() const { return name; }
 
    virtual ~Person() {}
};
 
// ==================================================
// Derived class: Student
// ==================================================
class Student : public Person {
private:
    string department;
    double gpa;
 
public:
    Student() : Person(), gpa(0.0) {}
    Student(int id, string name, int age, string department, double gpa)
        : Person(id, name, age), department(department), gpa(gpa) {}
 
    void display() const override {
        Person::display();
        cout << " | Department: " << department
             << " | GPA: " << gpa << " [Student]" << endl;
    }
 
    string getDepartment() const { return department; }
    double getGpa() const { return gpa; }
 
    void setGpa(double newGpa) { gpa = newGpa; }
    void setDepartment(const string& dept) { department = dept; }
};
 
// ==================================================
// Derived class: Professor
// ==================================================
class Professor : public Person {
private:
    string subject;
    double salary;
 
public:
    Professor() : Person(), salary(0.0) {}
    Professor(int id, string name, int age, string subject, double salary)
        : Person(id, name, age), subject(subject), salary(salary) {}
 
    void display() const override {
        Person::display();
        cout << " | Subject: " << subject
             << " | Salary: " << salary << " [Professor]" << endl;
    }
 
    string getSubject() const { return subject; }
};
 
// ==================================================
// Course class
// ==================================================
class Course {
private:
    int courseId;
    string courseName;
    int credits;
 
public:
    Course() : courseId(0), credits(0) {}
    Course(int courseId, string courseName, int credits)
        : courseId(courseId), courseName(courseName), credits(credits) {}
 
    void display() const {
        cout << "Course ID: " << courseId
             << " | Name: " << courseName
             << " | Credits: " << credits << endl;
    }
 
    int getCourseId() const { return courseId; }
};
 
// ==================================================
// University class (manages everything)
// ==================================================
class University {
private:
    Student students[MAX_STUDENTS];
    int studentCount;
 
    Professor professors[MAX_PROFESSORS];
    int professorCount;
 
    Course courses[MAX_COURSES];
    int courseCount;
 
    string universityName;
 
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(10000, '\n');
    }
 
    int findStudentIndex(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getId() == id) return i;
        }
        return -1;
    }
 
public:
    University(string name)
        : studentCount(0), professorCount(0), courseCount(0), universityName(name) {}
 
    // ---------------- Student operations ----------------
    void addStudent() {
        if (studentCount >= MAX_STUDENTS) {
            cout << "Student list is full!\n";
            return;
        }
 
        int id, age;
        string name, dept;
        double gpa;
 
        cout << "\nEnter Student ID: ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter numeric ID: ";
            clearInputBuffer();
        }
 
        if (findStudentIndex(id) != -1) {
            cout << "Student with ID " << id << " already exists.\n";
            return;
        }
 
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
 
        cout << "Enter Age: ";
        while (!(cin >> age)) {
            cout << "Invalid input. Enter numeric age: ";
            clearInputBuffer();
        }
 
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, dept);
 
        cout << "Enter GPA (0.0 - 4.0): ";
        while (!(cin >> gpa) || gpa < 0.0 || gpa > 4.0) {
            cout << "Invalid input. Enter GPA between 0.0 and 4.0: ";
            clearInputBuffer();
        }
 
        students[studentCount++] = Student(id, name, age, dept, gpa);
        cout << "Student added successfully!\n";
    }
 
    void displayStudents() {
        if (studentCount == 0) {
            cout << "\nNo students found.\n";
            return;
        }
        cout << "\n--- All Students ---\n";
        for (int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }
 
    void searchStudent() {
        int id;
        cout << "\nEnter Student ID to search: ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter numeric ID: ";
            clearInputBuffer();
        }
 
        int idx = findStudentIndex(id);
        if (idx == -1) {
            cout << "Student not found.\n";
            return;
        }
        cout << "\n--- Student Found ---\n";
        students[idx].display();
    }
 
    void updateStudent() {
        int id;
        cout << "\nEnter Student ID to update: ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter numeric ID: ";
            clearInputBuffer();
        }
 
        int idx = findStudentIndex(id);
        if (idx == -1) {
            cout << "Student not found.\n";
            return;
        }
 
        double newGpa;
        string newDept;
 
        cin.ignore();
        cout << "Enter new Department (leave blank to keep current): ";
        getline(cin, newDept);
        if (!newDept.empty()) students[idx].setDepartment(newDept);
 
        cout << "Enter new GPA (enter -1 to keep current): ";
        while (!(cin >> newGpa)) {
            cout << "Invalid input. Enter numeric GPA (-1 to keep): ";
            clearInputBuffer();
        }
        if (newGpa != -1.0) students[idx].setGpa(newGpa);
 
        cout << "Student updated successfully!\n";
    }
 
    void deleteStudent() {
        int id;
        cout << "\nEnter Student ID to delete: ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter numeric ID: ";
            clearInputBuffer();
        }
 
        int idx = findStudentIndex(id);
        if (idx == -1) {
            cout << "Student not found.\n";
            return;
        }
 
        // Shift remaining students left by one position
        for (int i = idx; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "Student deleted successfully!\n";
    }
 
    // ---------------- Professor operations ----------------
    void addProfessor() {
        if (professorCount >= MAX_PROFESSORS) {
            cout << "Professor list is full!\n";
            return;
        }
 
        int id, age;
        string name, subject;
        double salary;
 
        cout << "\nEnter Professor ID: ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter numeric ID: ";
            clearInputBuffer();
        }
 
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
 
        cout << "Enter Age: ";
        while (!(cin >> age)) {
            cout << "Invalid input. Enter numeric age: ";
            clearInputBuffer();
        }
 
        cin.ignore();
        cout << "Enter Subject Taught: ";
        getline(cin, subject);
 
        cout << "Enter Salary: ";
        while (!(cin >> salary)) {
            cout << "Invalid input. Enter numeric salary: ";
            clearInputBuffer();
        }
 
        professors[professorCount++] = Professor(id, name, age, subject, salary);
        cout << "Professor added successfully!\n";
    }
 
    void displayProfessors() {
        if (professorCount == 0) {
            cout << "\nNo professors found.\n";
            return;
        }
        cout << "\n--- All Professors ---\n";
        for (int i = 0; i < professorCount; i++) {
            professors[i].display();
        }
    }
 
    // ---------------- Course operations ----------------
    void addCourse() {
        if (courseCount >= MAX_COURSES) {
            cout << "Course list is full!\n";
            return;
        }
 
        int id, credits;
        string name;
 
        cout << "\nEnter Course ID: ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter numeric ID: ";
            clearInputBuffer();
        }
 
        cin.ignore();
        cout << "Enter Course Name: ";
        getline(cin, name);
 
        cout << "Enter Credits: ";
        while (!(cin >> credits)) {
            cout << "Invalid input. Enter numeric credits: ";
            clearInputBuffer();
        }
 
        courses[courseCount++] = Course(id, name, credits);
        cout << "Course added successfully!\n";
    }
 
    void displayCourses() {
        if (courseCount == 0) {
            cout << "\nNo courses found.\n";
            return;
        }
        cout << "\n--- All Courses ---\n";
        for (int i = 0; i < courseCount; i++) {
            courses[i].display();
        }
    }
 
    void displaySummary() {
        cout << "\n=== " << universityName << " Summary ===\n";
        cout << "Total Students:   " << studentCount << endl;
        cout << "Total Professors: " << professorCount << endl;
        cout << "Total Courses:    " << courseCount << endl;
    }
};
 
// ==================================================
// Menu
// ==================================================
void showMenu() {
    cout << "\n========== UNIVERSITY MANAGEMENT SYSTEM ==========\n";
    cout << " 1. Add Student\n";
    cout << " 2. Display All Students\n";
    cout << " 3. Search Student\n";
    cout << " 4. Update Student\n";
    cout << " 5. Delete Student\n";
    cout << " 6. Add Professor\n";
    cout << " 7. Display All Professors\n";
    cout << " 8. Add Course\n";
    cout << " 9. Display All Courses\n";
    cout << "10. Display Summary\n";
    cout << "11. Exit\n";
    cout << "====================================================\n";
    cout << "Enter your choice: ";
}
 
// ==================================================
// Main
// ==================================================
int main() {
    University uni("Global Institute of Technology");
    int choice;
 
    cout << "Welcome to the University Management System!\n";
 
    do {
        showMenu();
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number (1-11): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
 
        switch (choice) {
            case 1:  uni.addStudent(); break;
            case 2:  uni.displayStudents(); break;
            case 3:  uni.searchStudent(); break;
            case 4:  uni.updateStudent(); break;
            case 5:  uni.deleteStudent(); break;
            case 6:  uni.addProfessor(); break;
            case 7:  uni.displayProfessors(); break;
            case 8:  uni.addCourse(); break;
            case 9:  uni.displayCourses(); break;
            case 10: uni.displaySummary(); break;
            case 11: cout << "\nGoodbye!\n"; break;
            default: cout << "Invalid choice. Please select 1-11.\n";
        }
    } while (choice != 11);
 
    return 0;
}
 