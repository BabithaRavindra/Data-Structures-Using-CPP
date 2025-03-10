#include <iostream>
#include <string>
using namespace std;

class TourPackage
{
private:
    int id;
    string name;
    string destination;
    double price;

public:
    void setDetails(int t_id, string t_name, string t_destination, double t_price)
    {
        id = t_id;
        name = t_name;
        destination = t_destination;
        price = t_price;
    }

    void display()
    {
        cout << "ID: " << id << ", Name: " << name
             << ", Destination: " << destination
             << ", Price: $" << price << endl;
    }

    int getId() { return id; }
    string getDestination() { return destination; }
};

class BookingSystem
{
private:
    TourPackage tours[10];
    int tourCount;

public:
    BookingSystem() : tourCount(0) {}

    void addTour(int id, string name, string destination, double price)
    {
        if (tourCount < 10)
        {
            tours[tourCount].setDetails(id, name, destination, price);
            tourCount++;
        }
        else
        {
            cout << "Cannot add more tours, maximum capacity reached." << endl;
        }
    }

    void searchByDestination(string destination)
    {
        bool found = false;
        for (int i = 0; i < tourCount; i++)
        {
            if (tours[i].getDestination() == destination)
            {
                cout << "Tour found:" << endl;
                tours[i].display();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No tour found for the destination: " << destination << endl;
        }
    }

    void searchById(int id)
    {
        bool found = false;
        for (int i = 0; i < tourCount; i++)
        {
            if (tours[i].getId() == id)
            {
                cout << "Tour found:" << endl;
                tours[i].display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "No tour found with ID: " << id << endl;
        }
    }
};

int main()
{
    BookingSystem system;

    system.addTour(1, "Beach Adventure", "Hawaii", 1500.00);
    system.addTour(2, "Mountain Expedition", "Alps", 2000.00);
    system.addTour(3, "City Tour", "New York", 800.00);
    system.addTour(4, "Desert Safari", "Dubai", 1200.00);

    int choice;
    cout << "Welcome to the Tour Booking System!" << endl;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Search Tour by Destination\n";
        cout << "2. Search Tour by ID\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string destination;
            cout << "Enter destination to search: ";
            cin.ignore();
            getline(cin, destination);
            system.searchByDestination(destination);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter tour ID to search: ";
            cin >> id;
            system.searchById(id);
            break;
        }
        case 3:
            cout << "Thank you for using the Tour Booking System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
