#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Customer {
private:
    int roomNo;
    string name;
    string phone;
    int days;
    double roomPrice;

public:
    Customer() {
        roomNo = 0;
        name = "";
        phone = "";
        days = 0;
        roomPrice = 0;
    }

    Customer(int r, string n, string p, int d, double price) {
        roomNo = r;
        name = n;
        phone = p;
        days = d;
        roomPrice = price;
    }

    int getRoomNo() {
        return roomNo;
    }

    string getName() {
        return name;
    }

    int getDays() {
        return days;
    }

    double getPrice() {
        return roomPrice;
    }

    double getBill() {
        return days * roomPrice;
    }

    void display() {
        cout << left << setw(10) << roomNo
             << setw(20) << name
             << setw(15) << phone
             << setw(10) << days
             << "$" << getBill() << endl;
    }

    void save(ofstream &out) {
        out << roomNo << endl;
        out << name << endl;
        out << phone << endl;
        out << days << endl;
        out << roomPrice << endl;
    }

    void load(ifstream &in) {
        in >> roomNo;
        in.ignore();
        getline(in, name);
        getline(in, phone);
        in >> days;
        in >> roomPrice;
        in.ignore();
    }
};

class Hotel {
private:
    vector<Customer> customers;

public:
    Hotel() {
        loadFromFile();
    }

    ~Hotel() {
        saveToFile();
    }

    bool roomBooked(int room) {
        for (Customer c : customers) {
            if (c.getRoomNo() == room)
                return true;
        }
        return false;
    }

    void addCustomer() {
        int room;
        string name, phone;
        int days;
        int type;
        double price;

        cout << "\nRoom Number: ";
        cin >> room;

        if (roomBooked(room)) {
            cout << "Room already booked!\n";
            return;
        }

        cin.ignore();

        cout << "Customer Name: ";
        getline(cin, name);

        cout << "Phone Number: ";
        getline(cin, phone);

        cout << "Number of Days: ";
        cin >> days;

        cout << "\nRoom Type\n";
        cout << "1. Standard ($50/day)\n";
        cout << "2. Deluxe ($100/day)\n";
        cout << "3. Suite ($180/day)\n";
        cout << "Choose: ";
        cin >> type;

        switch(type) {
        case 1:
            price = 50;
            break;
        case 2:
            price = 100;
            break;
        case 3:
            price = 180;
            break;
        default:
            price = 50;
        }

        customers.push_back(Customer(room, name, phone, days, price));

        cout << "\nCustomer Added Successfully!\n";
    }

    void displayCustomers() {

        if(customers.empty()) {
            cout << "\nNo Customers Found.\n";
            return;
        }
        cout << left
             << setw(10) << "Room"
             << setw(20) << "Name"
             << setw(15) << "Phone"
             << setw(10) << "Days"
             << "Bill\n";
        for(Customer c : customers)
            c.display();
    }

    void searchCustomer() {

        int room;
        cout << "\nEnter Room Number: ";
        cin >> room;

        for(Customer c : customers) {
            if(c.getRoomNo() == room) {
                cout << "\nCustomer Found\n\n";

                cout << left
                     << setw(10) << "Room"
                     << setw(20) << "Name"
                     << setw(15) << "Phone"
                     << setw(10) << "Days"
                     << "Bill\n";

                c.display();
                return;
            }
        }

        cout << "Customer Not Found.\n";
    }

    void availableRooms() {

        cout << "\nAvailable Rooms:\n";

        for(int i=101;i<=110;i++) {

            bool booked = false;

            for(Customer c : customers) {
                if(c.getRoomNo()==i) {
                    booked = true;
                    break;
                }
            }

            if(!booked)
                cout << "Room " << i << endl;
        }
    }

    void saveToFile() {

        ofstream out("hotel.txt");

        out << customers.size() << endl;

        for(Customer c : customers)
            c.save(out);

        out.close();
    }

    void loadFromFile() {

        ifstream in("hotel.txt");

        if(!in)
            return;

        int size;
        in >> size;
        in.ignore();

        for(int i=0;i<size;i++) {

            Customer c;
            c.load(in);
            customers.push_back(c);
        }

        in.close();
    }
    void checkOut() {

        int room;
        cout << "\nEnter Room Number to Check Out: ";
        cin >> room;

        for(int i = 0; i < customers.size(); i++) {

            if(customers[i].getRoomNo() == room) {

                cout << "\nCustomer Checked Out Successfully!\n";
                cout << "Total Bill = $" << customers[i].getBill() << endl;

                customers.erase(customers.begin() + i);

                return;
            }
        }

        cout << "Customer Not Found!\n";
    }

    void generateBill() {

        int room;

        cout << "\nEnter Room Number: ";
        cin >> room;

        for(Customer c : customers) {

            if(c.getRoomNo() == room) {

                cout << "\n";
                cout << "        HOTEL BILL\n";
                cout << "Customer Name : " << c.getName() << endl;
                cout << "Room Number   : " << c.getRoomNo() << endl;
                cout << "Days Stayed   : " << c.getDays() << endl;
                cout << "Total Bill    : $" << c.getBill() << endl;

                return;
            }
        }

        cout << "Customer Not Found!\n";
    }

};

int main() {

    Hotel hotel;

    int choice;

    do {
        cout << "      HOTEL MANAGEMENT SYSTEM\n";
        cout << "1. Add Customer\n";
        cout << "2. Display All Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Display Available Rooms\n";
        cout << "5. Generate Bill\n";
        cout << "6. Check Out Customer\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch(choice) {

        case 1:
            hotel.addCustomer();
            break;

        case 2:
            hotel.displayCustomers();
            break;

        case 3:
            hotel.searchCustomer();
            break;

        case 4:
            hotel.availableRooms();
            break;

        case 5:
            hotel.generateBill();
            break;

        case 6:
            hotel.checkOut();
            break;

        case 7:
            cout << "\nSaving Data...\n";
            cout << "Thank You For Using Hotel Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 7);

    return 0;
}