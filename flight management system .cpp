#include <iostream>
#include <string>

using namespace std;

const int MAX_FLIGHTS = 100;

// -------------------- Flight Class --------------------
class Flight
{
public:
    int flightNumber;
    string airline;
    string origin;
    string destination;
    string departureTime;
    string arrivalTime;
    int totalSeats;
    int bookedSeats;
    double ticketPrice;

    Flight() : flightNumber(0), totalSeats(0), bookedSeats(0), ticketPrice(0.0) {}

    Flight(int fn, string al, string org, string dest, string dep,
           string arr, int total, double price)
        : flightNumber(fn), airline(al), origin(org), destination(dest),
          departureTime(dep), arrivalTime(arr), totalSeats(total),
          bookedSeats(0), ticketPrice(price) {}

    int availableSeats() const
    {
        return totalSeats - bookedSeats;
    }

    void display() const
    {
        cout << "No: " << flightNumber
             << " | Airline: " << airline
             << " | From: " << origin
             << " | To: " << destination
             << " | Departs: " << departureTime
             << " | Arrives: " << arrivalTime
             << " | Seats Available: " << availableSeats()
             << " | Price: " << ticketPrice
             << endl;
    }
};

// -------------------- Flight Management System --------------------
class FlightManagementSystem
{
private:
    Flight flights[MAX_FLIGHTS];
    int flightCount;

    int findFlightIndex(int flightNumber)
    {
        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].flightNumber == flightNumber)
                return i;
        }
        return -1;
    }

public:
    FlightManagementSystem() : flightCount(0) {}

    void addFlight()
    {
        if (flightCount >= MAX_FLIGHTS)
        {
            cout << "Flight list is full!\n";
            return;
        }

        int fn, seats;
        string airline, origin, dest, dep, arr;
        double price;

        cout << "\nEnter Flight Number: ";
        cin >> fn;

        if (findFlightIndex(fn) != -1)
        {
            cout << "Flight with this number already exists!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Airline Name: ";
        getline(cin, airline);
        cout << "Enter Origin: ";
        getline(cin, origin);
        cout << "Enter Destination: ";
        getline(cin, dest);
        cout << "Enter Departure Time (HH:MM): ";
        getline(cin, dep);
        cout << "Enter Arrival Time (HH:MM): ";
        getline(cin, arr);
        cout << "Enter Total Seats: ";
        cin >> seats;
        cout << "Enter Ticket Price: ";
        cin >> price;

        flights[flightCount] = Flight(fn, airline, origin, dest, dep, arr, seats, price);
        flightCount++;
        cout << "Flight added successfully!\n";
    }

    void displayAllFlights() const
    {
        if (flightCount == 0)
        {
            cout << "\nNo flights available.\n";
            return;
        }

        cout << "\n===== All Flights =====\n";
        for (int i = 0; i < flightCount; i++)
            flights[i].display();
    }

    void searchFlight()
    {
        string origin, dest;
        cin.ignore();
        cout << "\nEnter Origin: ";
        getline(cin, origin);
        cout << "Enter Destination: ";
        getline(cin, dest);

        bool found = false;
        cout << "\n===== Search Results =====\n";

        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].origin == origin && flights[i].destination == dest)
            {
                flights[i].display();
                found = true;
            }
        }

        if (!found)
            cout << "No matching flights found.\n";
    }

    void bookTicket()
    {
        int fn, seats;
        cout << "\nEnter Flight Number: ";
        cin >> fn;

        int idx = findFlightIndex(fn);
        if (idx == -1)
        {
            cout << "Flight not found!\n";
            return;
        }

        Flight &f = flights[idx];
        cout << "Available Seats: " << f.availableSeats() << endl;
        cout << "Enter number of seats to book: ";
        cin >> seats;

        if (seats <= 0)
        {
            cout << "Invalid seat count.\n";
        }
        else if (seats > f.availableSeats())
        {
            cout << "Not enough seats available!\n";
        }
        else
        {
            f.bookedSeats += seats;
            double total = seats * f.ticketPrice;
            cout << "Booking confirmed! Total cost: " << total << endl;
        }
    }

    void cancelBooking()
    {
        int fn, seats;
        cout << "\nEnter Flight Number: ";
        cin >> fn;

        int idx = findFlightIndex(fn);
        if (idx == -1)
        {
            cout << "Flight not found!\n";
            return;
        }

        Flight &f = flights[idx];
        cout << "Currently Booked Seats: " << f.bookedSeats << endl;
        cout << "Enter number of seats to cancel: ";
        cin >> seats;

        if (seats <= 0 || seats > f.bookedSeats)
        {
            cout << "Invalid cancellation amount.\n";
        }
        else
        {
            f.bookedSeats -= seats;
            cout << "Cancellation successful.\n";
        }
    }

    void deleteFlight()
    {
        int fn;
        cout << "\nEnter Flight Number to delete: ";
        cin >> fn;

        int idx = findFlightIndex(fn);
        if (idx == -1)
        {
            cout << "Flight not found!\n";
            return;
        }

        // shift all later flights one position left
        for (int i = idx; i < flightCount - 1; i++)
        {
            flights[i] = flights[i + 1];
        }
        flightCount--;
        cout << "Flight deleted successfully.\n";
    }
};

// -------------------- Utility --------------------
void clearInputError()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

// -------------------- Main Menu --------------------
int main()
{
    FlightManagementSystem fms;
    int choice;

    do
    {
        cout << "\n===== Flight Management System =====\n";
        cout << "1. Add Flight\n";
        cout << "2. Display All Flights\n";
        cout << "3. Search Flight (Origin/Destination)\n";
        cout << "4. Book Ticket\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Delete Flight\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            clearInputError();
            choice = -1;
        }

        switch (choice)
        {
            case 1: fms.addFlight(); break;
            case 2: fms.displayAllFlights(); break;
            case 3: fms.searchFlight(); break;
            case 4: fms.bookTicket(); break;
            case 5: fms.cancelBooking(); break;
            case 6: fms.deleteFlight(); break;
            case 7: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }

    } while (choice != 7);

    return 0;
}