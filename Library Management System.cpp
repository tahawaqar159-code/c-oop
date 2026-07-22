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

// LIBRARIAN CLASS

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

// CLASS FINE 

class Fine {
    int fineId;
    int studentId;
    int bookId;
    double amount;

public:
    Fine() {
        fineId = 0;
        studentId = 0;
        bookId = 0;
        amount = 0.0;
    }

    Fine(int id, int sid, int bid, double amt) {
        fineId = id;
        studentId = sid;
        bookId = bid;
        amount = amt;
    }
    void calclateFine() {
        int daysLate;
        cout << "Enter number of days late: ";
        cin >> daysLate;
        amount = daysLate * 200;
        cout << "Fine Amount: Rs " << amount << endl;
    }
    void displayfine(){
        cout << "Fine ID: " << fineId << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Fine Amount: Rs " << amount << endl;
    }
};

// MAIN FUNCTION
int main() {
 Book books[100];
student students[100];
Librarian librarians[100];
Fine fines[100];

int bookCount = 0;
int studentCount = 0;
int librarianCount = 0;
int fineCount = 0;

    int choice;

    do {
        cout << "LIBRARY MANAGEMENT SYSTEM\n";
        cout << "1. Librarian Menu\n";
        cout << "2. Student Menu\n";
        cout << "3. Fine Menu\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int librarianChoice;

            do {
                cout << "\n----- LIBRARIAN MENU -----\n";
                cout << "1. Register Librarian\n";
                cout << "2. Display Librarian\n";
                cout << "3. Add Book\n";
                cout << "4. Search Book\n";
                cout << "5. Update Book\n";
                cout << "6. Borrow Book\n";
                cout << "7. Return Book\n";
                cout << "8. Back\n";
                cout << "Enter Choice: ";
                cin >> librarianChoice;

                switch (librarianChoice) {
                case 1:
                    librarians[librarianCount].registerLibrarian();
                      librarianCount++;
                    break;
                case 2:
                    l1.displayLibrarian();
                    break; 
                case 3:
                   l1.addBook(books[bookCount]);
                      bookCount++;
                case 4:
                   int index;
                   cout << "Enter Librarian Number: ";
                   cin >> index;

                   if(index >= 1 && index <= librarianCount)
                    {
                     librarians[index-1].displayLibrarian();
                    }
                       else
{
                    cout << "Invalid Librarian!\n";
}
                    break;
                case 5:
                    l1.updateBook(b1);
                    break;
                case 6:
                    l1.borrowBook(b1);
                    break;
                case 7:
                    l1.returnBook(b1);
                    break;
                case 8:
                    break;
                default:
                    cout << "Invalid Choice!\n";
                }
            } while (librarianChoice != 8);
            break;
        }
        case 2: {
            int studentChoice;
            do {
                cout << "\n----- STUDENT MENU -----\n";
                cout << "1. Register Student\n";
                cout << "2. Display Student\n";
                cout << "3. Update Student\n";
                cout << "4. Search Student\n";
                cout << "5. Back\n";
                cout << "Enter Choice: ";
                cin >> studentChoice;

                switch (studentChoice) {
                case 1:
                 students[studentCount].registerstudent();
                    studentCount++;
                    break;
                case 2:
                    s1.displaystudent();
                    break;
                case 3:
                    s1.updatestudent();
                    break;
                case 4:
                    s1.searchstudent();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid Choice!\n";
                }
            } while (studentChoice != 5);
            break;
        }
        case 3: {

            int fineChoice;
            do {

                cout << "\n FINE MENU \n";
                cout << "1. Calculate Fine\n";
                cout << "2. Display Fine\n";
                cout << "3. Back\n";
                cout << "Enter Choice: ";
                cin >> fineChoice;
                switch (fineChoice) {
                case 1:
                    f1.calclateFine();
                    break;
                case 2:
                    f1.displayfine();
                    break;
                case 3:
                    break;

                default:
                    cout << "Invalid Choice!\n";
                }
            } while (fineChoice != 3);

            break;
        }
        case 4:
            cout << "\nThank You For Using Library Management System.\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 4);
    return 0;
}