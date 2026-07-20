#include <iostream>
#include <string>
using namespace std;

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

int main() {

    Book b1;
    b1.addBook();
    b1.search();
    b1.update();
    b1.borrow();
    b1.returnBook();
    return 0;
}