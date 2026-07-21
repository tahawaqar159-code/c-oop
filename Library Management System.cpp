#include <iostream>
#include <string>
using namespace std;

// CLASS BOOK
class Book {
    int bookId;
    string bookName;
    string author;
    int price;
    string category;
    bool isAvailable;

public:
    Book() {
        bookId = 0;
        bookName = "";
        author = "";
        price = 0;
        category = "";
        isAvailable = true;
    }

    Book(int id, string name, string a, int p, string c) {
        bookId = id;
        bookName = name;
        author = a;
        price = p;
        category = c;
        isAvailable = true;
    }

    void addBook() {
        cout << "Enter ID of book to be added: ";
        cin >> bookId;
        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, bookName);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter Book Category: ";
        getline(cin, category);
        cout << "Book Added Successfully!\n";
    }

    void search() {
        int id;

        cout << "\nEnter ID of the book you want to search: ";
        cin >> id;

        if (id == bookId) {
            cout << "\nBook Found!\n";
            cout << "Book ID      : " << bookId << endl;
            cout << "Book Name    : " << bookName << endl;
            cout << "Author       : " << author << endl;
            cout << "Price        : " << price << endl;
            cout << "Category     : " << category << endl;
            cout << "Availability : "
                 << (isAvailable ? "Available" : "Not Available") << endl;
        }
        else {
            cout << "Book Not Found!\n";
        }
    }

    void update() {
        int id;

        cout << "\nEnter ID of the book you want to update: ";
        cin >> id;
        cin.ignore();

        if (id == bookId) {
            cout << "Book Found!\n";
            cout << "Enter New Book Name: ";
            getline(cin, bookName);
            cout << "Enter New Author Name: ";
            getline(cin, author);
            cout << "Enter New Price: ";
            cin >> price;
            cin.ignore();
            cout << "Enter New Category: ";
            getline(cin, category);
            cout << "Book Updated Successfully!\n";
        }
        else {
            cout << "Book Not Found!\n";
        }
    }

    void borrow() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book Borrowed Successfully!\n";
        }
        else {
            cout << "Sorry! This book is not available.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book Returned Successfully!\n";
        }
        else {
            cout << "This book was not borrowed.\n";
        }
    }
};
//  STUDENT CLASS 
class student {
    int studentid;
    string studentname;
    string department;
    string semester;

    public :
    student() {
        studentid = 0;
        studentname = "";
        department = "";
        semester = "";
    }   
    student(int id, string name, string dept, string sem) {
        studentid = id;
        studentname = name;
        department = dept;
        semester = sem;
    }
    void registerstudent(){
        cout << "Enter Student ID: ";
        cin >> studentid;
        cin.ignore();
        cout << " enter Student Name: ";
        getline(cin, studentname);
        cout << "Enter Department: ";
        getline ( cin, department);
        cout << "Enter Semester: "; 
        getline(cin, semester);
        cout << "Student Registered Successfully!\n";
    }
    void displaystudent (){
        cout << " student id : " << studentid << endl ;
        cout<< " student name : " << studentname << endl ;
        cout << " studenrt's department is : " << department << endl ;
        cout << " student's semester is  : " << semester << endl ;
    }
    void updatestudent(){
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;
        cin.ignore();
        if (id == studentid) {
            cout << "Student Found!\n";
            cout << "Enter New Student Name: ";
            getline(cin, studentname);
            cout << "Enter New Department: ";
            getline(cin, department);
            cout << "Enter New Semester: ";
            getline(cin, semester);
            cout << "Student Updated Successfully!\n";
        }
        else {
            cout << "Student Not Found!\n";
        }
    }
    void searchstudent() {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;
        if (id == studentid) {
            cout << "Student Found!\n";
            displaystudent();
        }
        else {
            cout << "Student Not Found!\n";
        }
    }
};

class Librarian
{
private:
    int librarianID;
    string librarianName;

public:
    Librarian() {
        librarianID = 0;
        librarianName = "";
    }
    Librarian(int id, string name) {
        librarianID = id;
        librarianName = name;
    }
    void registerLibrarian()   {
        cout << "Enter Librarian ID: ";
        cin >> librarianID;
        cin.ignore();
        cout << "Enter Librarian Name: ";
        getline(cin, librarianName);
        cout << "Librarian Registered Successfully!\n";
    }
    void displayLibrarian()    {
        cout << "\n----- Librarian Details -----\n";
        cout << "ID   : " << librarianID << endl;
        cout << "Name : " << librarianName << endl;
    }
    void addBook(Book &b)
    {
        b.addBook();
    }
    void searchBook(Book &b)  {
        b.search();
    }
    void updateBook(Book &b)  {
        b.update();
    }
    void borrowBook(Book &b)  {
        b.borrow();
    }
    void returnBook(Book &b)  {
        b.returnBook();
    }
};

// MAIN FUNCTION
int main() {
// Create an object of the Book class
    Book b1;
    b1.addBook();
    b1.search();
    b1.update();
    b1.borrow();
    b1.returnBook();
    // Create objects of the student class
    // STUDENT S1 , S2
    student s1 ;
    student s2 ;
    s1.registerstudent();
    s1.displaystudent();
    s1.updatestudent();
    s1.searchstudent();
    s2.registerstudent();
    s2.displaystudent();
    s2.updatestudent();
    s2.searchstudent();

    return 0;
}