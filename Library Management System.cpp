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
    int getId() const { return bookId; }
    string getName() const { return bookName; }
    bool getAvailability() const { return isAvailable; }

    void displayInfo() const {
        cout << "Book ID      : " << bookId << endl;
        cout << "Book Name    : " << bookName << endl;
        cout << "Author       : " << author << endl;
        cout << "Price        : " << price << endl;
        cout << "Category     : " << category << endl;
        cout << "Availability : " << (isAvailable ? "Available" : "Not Available") << endl;
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
            displayInfo();
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

// CLASS STUDENT
class student {
    int studentid;
    string studentname;
    string department;
    string semester;

public:
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

    int getId() const { return studentid; }

    void registerstudent() {
        cout << "Enter Student ID: ";
        cin >> studentid;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, studentname);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Semester: ";
        getline(cin, semester);
        cout << "Student Registered Successfully!\n";
    }

    void displaystudent() {
        cout << "Student ID       : " << studentid << endl;
        cout << "Student Name     : " << studentname << endl;
        cout << "Department       : " << department << endl;
        cout << "Semester         : " << semester << endl;
    }

    void updatestudent() {
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


// CLASS LIBRARIAN
class Librarian {
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

    int getId() const { return librarianID; }

    void registerLibrarian() {
        cout << "Enter Librarian ID: ";
        cin >> librarianID;
        cin.ignore();
        cout << "Enter Librarian Name: ";
        getline(cin, librarianName);
        cout << "Librarian Registered Successfully!\n";
    }

    void displayLibrarian() {
        cout << "\n----- Librarian Details -----\n";
        cout << "ID   : " << librarianID << endl;
        cout << "Name : " << librarianName << endl;
    }

    void addBook(Book &b) { b.addBook(); }
    void searchBook(Book &b) { b.search(); }
    void updateBook(Book &b) { b.update(); }
    void borrowBook(Book &b) { b.borrow(); }
    void returnBook(Book &b) { b.returnBook(); }
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
        cout << "Enter Fine ID: ";
        cin >> fineId;
        cout << "Enter Student ID this fine belongs to: ";
        cin >> studentId;
        cout << "Enter Book ID this fine belongs to: ";
        cin >> bookId;
        cout << "Enter number of days late: ";
        cin >> daysLate;
        amount = daysLate * 200;
        cout << "Fine Amount: Rs " << amount << endl;
    }

    void displayfine() {
        cout << "Fine ID     : " << fineId << endl;
        cout << "Student ID  : " << studentId << endl;
        cout << "Book ID     : " << bookId << endl;
        cout << "Fine Amount : Rs " << amount << endl;
    }
};

// HELPER FUNCTIONS FOR MAIN

int findBookIndex(Book books[], int bookCount, int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == id) return i;
    }
    return -1;
}

int findStudentIndex(student students[], int studentCount, int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getId() == id) return i;
    }
    return -1;
}

int findLibrarianIndex(Librarian librarians[], int librarianCount, int id) {
    for (int i = 0; i < librarianCount; i++) {
        if (librarians[i].getId() == id) return i;
    }
    return -1;
}

// MAIN FUNCTION

int main() {
    const int MAX = 100;
    Book books[MAX];
    student students[MAX];
    Librarian librarians[MAX];
    Fine fines[MAX];

    int bookCount = 0;
    int studentCount = 0;
    int librarianCount = 0;
    int fineCount = 0;

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Librarian Menu\n";
        cout << "2. Student Menu\n";
        cout << "3. Fine Menu\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        //  LIBRARIAN MENU 
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
                case 1: {
                    if (librarianCount >= MAX) {
                        cout << "Librarian list is full!\n";
                        break;
                    }
                    librarians[librarianCount].registerLibrarian();
                    librarianCount++;
                    break;
                }
                case 2: {
                    if (librarianCount == 0) {
                        cout << "No librarians registered yet!\n";
                        break;
                    }
                    int id;
                    cout << "Enter Librarian ID to display: ";
                    cin >> id;
                    int idx = findLibrarianIndex(librarians, librarianCount, id);
                    if (idx != -1) {
                        librarians[idx].displayLibrarian();
                    }
                    else {
                        cout << "Librarian Not Found!\n";
                    }
                    break;
                }
                case 3: {
                    if (librarianCount == 0) {
                        cout << "No librarians registered! Please register one first.\n";
                        break;
                    }
                    if (bookCount >= MAX) {
                        cout << "Book list is full!\n";
                        break;
                    }
                    int id;
                    cout << "Enter Librarian ID performing this action: ";
                    cin >> id;
                    int idx = findLibrarianIndex(librarians, librarianCount, id);
                    if (idx != -1) {
                        librarians[idx].addBook(books[bookCount]);
                        bookCount++;
                    }
                    else {
                        cout << "Librarian Not Found!\n";
                    }
                    break;
                }
                case 4: {
                    if (bookCount == 0) {
                        cout << "No books available!\n";
                        break;
                    }
                    int id;
                    cout << "Enter ID of the book you want to search: ";
                    cin >> id;
                    int idx = findBookIndex(books, bookCount, id);
                    if (idx != -1) {
                        cout << "\nBook Found!\n";
                        books[idx].displayInfo();
                    }
                    else {
                        cout << "Book Not Found!\n";
                    }
                    break;
                }
                case 5: {
                    if (bookCount == 0) {
                        cout << "No books available!\n";
                        break;
                    }
                    int id;
                    cout << "Enter ID of the book you want to update: ";
                    cin >> id;
                    int idx = findBookIndex(books, bookCount, id);
                    if (idx != -1) {
                   
                        books[idx].update();
                    }
                    else {
                        cout << "Book Not Found!\n";
                    }
                    break;
                }
                case 6: {
                    if (bookCount == 0) {
                        cout << "No books available!\n";
                        break;
                    }
                    int id;
                    cout << "Enter ID of the book to borrow: ";
                    cin >> id;
                    int idx = findBookIndex(books, bookCount, id);
                    if (idx != -1) {
                        books[idx].borrow();
                    }
                    else {
                        cout << "Book Not Found!\n";
                    }
                    break;
                }
                case 7: {
                    if (bookCount == 0) {
                        cout << "No books available!\n";
                        break;
                    }
                    int id;
                    cout << "Enter ID of the book to return: ";
                    cin >> id;
                    int idx = findBookIndex(books, bookCount, id);
                    if (idx != -1) {
                        books[idx].returnBook();
                    }
                    else {
                        cout << "Book Not Found!\n";
                    }
                    break;
                }
                case 8:
                    break;
                default:
                    cout << "Invalid Choice!\n";
                }
            } while (librarianChoice != 8);
            break;
        }

        //  STUDENT MENU 
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
                case 1: {
                    if (studentCount >= MAX) {
                        cout << "Student list is full!\n";
                        break;
                    }
                    students[studentCount].registerstudent();
                    studentCount++;
                    break;
                }
                case 2: {
                    if (studentCount == 0) {
                        cout << "No students registered yet!\n";
                        break;
                    }
                    int id;
                    cout << "Enter Student ID to display: ";
                    cin >> id;
                    int idx = findStudentIndex(students, studentCount, id);
                    if (idx != -1) {
                        students[idx].displaystudent();
                    }
                    else {
                        cout << "Student Not Found!\n";
                    }
                    break;
                }
                case 3: {
                    if (studentCount == 0) {
                        cout << "No students registered yet!\n";
                        break;
                    }
                    int id;
                    cout << "Enter Student ID to update: ";
                    cin >> id;
                    int idx = findStudentIndex(students, studentCount, id);
                    if (idx != -1) {
                        cin.ignore();
                        cout << "Student Found!\n";
                        cout << "Enter New Student Name: ";
                        string tmp;
                        getline(cin, tmp);
                        cout << "Enter New Department: ";
                        string tmp2;
                        getline(cin, tmp2);
                        cout << "Enter New Semester: ";
                        string tmp3;
                        getline(cin, tmp3);
                        students[idx] = student(id, tmp, tmp2, tmp3);
                        cout << "Student Updated Successfully!\n";
                    }
                    else {
                        cout << "Student Not Found!\n";
                    }
                    break;
                }
                case 4: {
                    if (studentCount == 0) {
                        cout << "No students registered yet!\n";
                        break;
                    }
                    int id;
                    cout << "Enter Student ID to search: ";
                    cin >> id;
                    int idx = findStudentIndex(students, studentCount, id);
                    if (idx != -1) {
                        cout << "Student Found!\n";
                        students[idx].displaystudent();
                    }
                    else {
                        cout << "Student Not Found!\n";
                    }
                    break;
                }
                case 5:
                    break;
                default:
                    cout << "Invalid Choice!\n";
                }
            } while (studentChoice != 5);
            break;
        }

        // FINE MENU 
        case 3: {
            int fineChoice;
            do {
                cout << "\n----- FINE MENU -----\n";
                cout << "1. Calculate Fine\n";
                cout << "2. Display Fine\n";
                cout << "3. Display All Fines\n";
                cout << "4. Back\n";
                cout << "Enter Choice: ";
                cin >> fineChoice;

                switch (fineChoice) {
                case 1: {
                    if (fineCount >= MAX) {
                        cout << "Fine list is full!\n";
                        break;
                    }
                    fines[fineCount].calclateFine();
                    fineCount++;
                    break;
                }
                case 2: {
                    if (fineCount == 0) {
                        cout << "No fines recorded yet!\n";
                        break;
                    }
                    int idx;
                    cout << "Enter Fine record number (1 to " << fineCount << "): ";
                    cin >> idx;
                    if (idx >= 1 && idx <= fineCount) {
                        fines[idx - 1].displayfine();
                    }
                    else {
                        cout << "Invalid record number!\n";
                    }
                    break;
                }
                case 3: {
                    if (fineCount == 0) {
                        cout << "No fines recorded yet!\n";
                        break;
                    }
                    for (int i = 0; i < fineCount; i++) {
                        cout << "\n-- Fine Record " << (i + 1) << " --\n";
                        fines[i].displayfine();
                    }
                    break;
                }
                case 4:
                    break;
                default:
                    cout << "Invalid Choice!\n";
                }
            } while (fineChoice != 4);
            break;
        }

        case 4:
            cout << "\nDobara phir aye ga !!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}