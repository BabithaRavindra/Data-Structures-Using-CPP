#include <iostream>
using namespace std;

class Queue {
public:
    struct Tour {
        int Tour_ID;
        string Origin, Destination;
        string Passenger_Name;
        int Passenger_Age;
        int Price;
    };

    int front, rear, size;
    Tour *queue;

    // Constructor
    Queue() {
        rear = -1;
        front = -1;
        cout << "\033[96mEnter the size of the Queue: \033[0m";
        cin >> size;
        queue = new Tour[size];
    }

    // Function to enqueue a tour booking
    void enqueue() {
        if (rear == size - 1) {
            cout << "\033[31mQueue Overflow! Cannot add more bookings.\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        Tour newTour;
        cout << "\n\033[34mPlease Enter Tour Details:\033[0m\n";
        cout << "-----------------------------\n";
        cout << "\033[34m1. Tour ID: \033[0m";
        cin >> newTour.Tour_ID;
        cout << "\033[34m2. Origin: \033[0m";
        cin >> newTour.Origin;
        cout << "\033[34m3. Destination: \033[0m";
        cin >> newTour.Destination;
        cout << "\033[34m4. Passenger Name: \033[0m";
        cin >> newTour.Passenger_Name;
        cout << "\033[34m5. Passenger Age: \033[0m";
        cin >> newTour.Passenger_Age;

        // Set base fare based on destination
        char choice;
        cout << "\033[34m6. Is the destination Inside the country or Outside? (I/O): \033[0m";
        cin >> choice;
        if (choice == 'I' || choice == 'i') {
            newTour.Price = 10000;
        } else if (choice == 'O' || choice == 'o') {
            newTour.Price = 20000;
        } else {
            cout << "\033[31mInvalid input! Assuming Inside Country fare.\033[0m\n";
            cout << "-----------------------------\n";
            newTour.Price = 10000;
        }

        // Add extra fare based on age
        if (newTour.Passenger_Age >= 0 && newTour.Passenger_Age <= 12) {
            newTour.Price += 3000;
        } else if (newTour.Passenger_Age >= 13) {
            newTour.Price += 5000;
        } else {
            cout << "\033[31mInvalid Age! Assuming Adult Fare.\033[0m\n";
            cout << "-----------------------------\n";
            newTour.Price += 5000;
        }

        queue[++rear] = newTour;
        cout << "-----------------------------\n";
        cout << "\033[32mBooking Added Successfully!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Function to dequeue a booking
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "\033[31mQueue Underflow! No bookings to remove.\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        cout << "\n\033[33mBooking Removed:\033[0m\n";
        cout << "-----------------------------\n";
        cout << "\033[34mTour ID: \033[0m" << queue[front].Tour_ID << endl;
        cout << "\033[34mOrigin: \033[0m" << queue[front].Origin << endl;
        cout << "\033[34mDestination: \033[0m" << queue[front].Destination << endl;
        cout << "\n\033[34mPassenger Name: \033[0m" << queue[front].Passenger_Name << endl;
        cout << "\033[34mPassenger Age: \033[0m" << queue[front].Passenger_Age << endl;
        cout << "\n\033[34mTotal Price: ₹\033[0m" << queue[front].Price << endl;
        cout << "-----------------------------\n";

        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Function to peek at the front booking
    void peek() {
        if (front == -1 || front > rear) {
            cout << "\033[31mQueue is Empty!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        cout << "\n\033[34mNext Booking in Queue:\033[0m\n";
        cout << "-----------------------------\n";
        cout << "\033[34mTour ID: \033[0m" << queue[front].Tour_ID << endl;
        cout << "\033[34mOrigin: \033[0m" << queue[front].Origin << endl;
        cout << "\033[34mDestination: \033[0m" << queue[front].Destination << endl;
        cout << "\n\033[34mPassenger Name: \033[0m" << queue[front].Passenger_Name << endl;
        cout << "\033[34mPassenger Age: \033[0m" << queue[front].Passenger_Age << endl;
        cout << "\n\033[34mTotal Price: ₹\033[0m" << queue[front].Price << endl;

        cout << "-----------------------------\n";
    }

    // Function to display all bookings
    void display() {
        if (front == -1 || front > rear) {
            cout << "\033[31mQueue is Empty!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        cout << "\n\033[34mAll Tour Bookings:\033[0m\n";
        cout << "-----------------------------\n";
        for (int i = front; i <= rear; i++) { 
            cout << "\033[34mTour ID: \033[0m" << queue[i].Tour_ID << endl;
            cout << "\033[34mOrigin: \033[0m" << queue[i].Origin << endl;
            cout << "\033[34mDestination: \033[0m" << queue[i].Destination << endl;
            cout << "\n\033[34mPassenger Name: \033[0m" << queue[i].Passenger_Name << endl;
            cout << "\033[34mPassenger Age: \033[0m" << queue[i].Passenger_Age << endl;
            cout << "\n\033[34mTotal Price: ₹\033[0m" << queue[i].Price << endl;
            cout << "\n-----------------------------\n";
        }
    }

    // Function to search bookings 
    void search() {
        if (front == -1 || front > rear) {
            cout << "\033[31mQueue is Empty!\033[0m\n";
            return;
        }

        int searchChoice;
        cout << "\033[34mSearch By:\033[0m\n";
        cout << "1. Position\n2. Tour ID\n3. Passenger Name\n";
        cout << "\033[34mEnter your choice: \033[0m";
        cin >> searchChoice;
        cout << "-----------------------------\n";

        switch (searchChoice) {
        case 1: {
            int position;
            cout << "\033[34mEnter Position: \033[0m";
            cin >> position;
            if (position < 1 || position > (rear - front + 1)) {
                cout << "\033[31mInvalid Position!\033[0m\n";
                return;
            }
            cout << "\033[34mFound at Position " << position << ": \033[0m\n";
            cout << "\033[34mTour ID: \033[0m" << queue[front + position - 1].Tour_ID << endl;
            cout << "\033[34mOrigin: \033[0m" << queue[front + position - 1].Origin << endl;
            cout << "\033[34mDestination: \033[0m" << queue[front + position - 1].Destination << endl;
            cout << "\n\033[34mPassenger Name: \033[0m" << queue[front + position - 1].Passenger_Name << endl;
            cout << "\033[34mPassenger Age: \033[0m" << queue[front + position - 1].Passenger_Age << endl;
            cout << "\n\033[34mTotal Price: ₹\033[0m" << queue[front + position - 1].Price << endl;
            cout << "-----------------------------\n";
            break;
        }
        case 2: {
            int id;
            cout << "\033[34mEnter Tour ID: \033[0m";
            cin >> id;
            for (int i = front; i <= rear; i++) {
                if (queue[i].Tour_ID == id) {
                    cout << "\033[34mTour Found!\033[0m\n";
                    cout << "\033[34mTour ID: \033[0m" << queue[i].Tour_ID << endl;
                    cout << "\033[34mOrigin: \033[0m" << queue[i].Origin << endl;
                    cout << "\033[34mDestination: \033[0m" << queue[i].Destination << endl;
                    cout << "\n\033[34mPassenger Name: \033[0m" << queue[i].Passenger_Name << endl;
                    cout << "\033[34mPassenger Age: \033[0m" << queue[i].Passenger_Age << endl;
                    cout << "\n\033[34mTotal Price: ₹\033[0m" << queue[i].Price << endl;
                    cout << "-----------------------------\n";
                    return;
                } 
            }
            cout << "\033[31mTour ID Not Found!\033[0m\n";
            cout << "-----------------------------\n";
            break;
        }
        case 3: {
            string name;
            cout << "\033[34mEnter Passenger Name: \033[0m";
            cin >> name;
            for (int i = front; i <= rear; i++) {
                if (queue[i].Passenger_Name == name) {
                    cout << "\033[34mTour ID: \033[0m" << queue[i].Tour_ID << endl;
                    cout << "\033[34mOrigin: \033[0m" << queue[i].Origin << endl;
                    cout << "\033[34mDestination: \033[0m" << queue[i].Destination << endl;
                    cout << "\n\033[34mPassenger Name: \033[0m" << queue[i].Passenger_Name << endl;
                    cout << "\033[34mPassenger Age: \033[0m" << queue[i].Passenger_Age << endl;
                    cout << "\n\033[34mTotal Price: ₹\033[0m" << queue[i].Price << endl;
                    cout << "-----------------------------\n";
                    return;
                }
            }
            cout << "\033[31mPassenger Name Not Found!\033[0m\n";
            cout << "-----------------------------\n";
            break;
        }
        default:
            cout << "\033[31mInvalid Choice!\033[0m\n";
            cout << "-----------------------------\n";
        }
    }

void update() {
    if (front == -1 || front > rear) {
        cout << "\033[31mQueue is Empty!\033[0m\n";
        cout << "-----------------------------\n";
        return;
    }

    int id;
    cout << "\033[34mEnter Tour ID to Update: \033[0m";
    cin >> id;

    for (int i = front; i <= rear; i++) {
        if (queue[i].Tour_ID == id) {
            int choice;
            do {
                cout << "\033[34mWhat would you like to update?\033[0m\n";
                cout << "1. Passenger Name\n";
                cout << "2. Origin\n";
                cout << "3. Destination\n";
                cout << "4. Passenger Age\n";
                cout << "5. Tour ID\n";
                cout << "6. Exit Update Menu\n";
                cout << "\033[34mEnter your choice: \033[0m";
                cin >> choice;
                cout << "-----------------------------\n";
                switch (choice) {
                    case 1:
                        cout << "\033[34mEnter New Passenger Name: \033[0m";
                        cin >> queue[i].Passenger_Name;
                        cout << "\033[32mPassenger Name Updated Successfully!\033[0m\n";
                        cout << "-----------------------------\n";
                        break;
                    case 2:
                        cout << "\033[34mEnter New Origin: \033[0m";
                        cin >> queue[i].Origin;
                        cout << "\033[32mOrigin Updated Successfully!\033[0m\n";
                        cout << "-----------------------------\n";
                        break;
                    case 3:
                        cout << "\033[34mEnter New Destination: \033[0m";
                        cin >> queue[i].Destination;
                        cout << "\033[32mDestination Updated Successfully!\033[0m\n";
                        cout << "-----------------------------\n";
                        break;
                    case 4:
                        cout << "\033[34mEnter New Passenger Age: \033[0m";
                        cin >> queue[i].Passenger_Age;
                        cout << "\033[32mPassenger Age Updated Successfully!\033[0m\n";
                        cout << "-----------------------------\n";
                        break;
                    case 5:
                        cout << "\033[34mEnter New Tour ID: \033[0m";
                        cin >> queue[i].Tour_ID;
                        cout << "\033[32mTour ID Updated Successfully!\033[0m\n";
                        cout << "-----------------------------\n";
                        break;
                    case 6:
                        cout << "\033[32mExiting Update Menu...\033[0m\n";
                        cout << "-----------------------------\n";
                        return;
                    default:
                        cout << "\033[31mInvalid Choice! Please try again.\033[0m\n";
                        cout << "-----------------------------\n";
                }
            } while (choice != 6);
            return;
        }
    }
    cout << "\033[31mTour ID Not Found!\033[0m\n";
    cout << "-----------------------------\n";
}


    // Destructor
    ~Queue() {
        cout << "\033[32mMemory Freed!\033[0m\n";
        cout << "-----------------------------\n";
        delete[] queue;
    }
};

// Main Function
int main() {
    Queue q;
    int choice;

    do {
        cout << "\033[96m\n--------------------------------------------------------------------------------------\n\033[0m";
        cout << "\033[96m                                     ᗪ E   ᐯ I ᗩ ᒍ E  \033[0m\n";
        cout << "\033[96m                      T O U R   B O O K I N G   S Y S T E M \033[0m\n";
        cout << "\033[96m--------------------------------------------------------------------------------------\033[0m\n";
        cout << "\033[96m   Menu:\033[0m" << endl;
        cout << "\033[96m   1. Enqueue\033[0m" << endl;
        cout << "\033[96m   2. Dequeue\033[0m" << endl;
        cout << "\033[96m   3. Peek\033[0m" << endl;
        cout << "\033[96m   4. Search\033[0m" << endl;
        cout << "\033[96m   5. Update\033[0m" << endl;
        cout << "\033[96m   6. Display \033[0m" << endl;
        cout << "\033[96m   7. Exit\033[0m" << endl;
        cout << "\033[96m   Enter Your Choice:      \033[0m";
        cin >> choice;
        cout << "-----------------------------\n";

        if (cin.fail()) { 
            cout << "\033[31mERROR: Invalid input! Enter a number.\033[0m\n";
            cout << "-----------------------------\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: 
                cout << "\033[34m You chose to Enqueue / Add a Booking...\033[0m\n";
                cout << "-----------------------------\n";
                q.enqueue(); 
                break;
            case 2: 
                cout << "\033[34m You chose to Dequeue / Remove a Booking...\033[0m\n";
                cout << "-----------------------------\n";
                q.dequeue(); 
                break;
            case 3: 
                cout << "\033[34m You chose to Peek at the Next Booking...\033[0m\n";
                cout << "-----------------------------\n";
                q.peek(); 
                break;
            case 4: 
                cout << "\033[34m You chose to Search a Booking...\033[0m\n";
                cout << "-----------------------------\n";
                q.search(); 
                break;
	        case 5: 
                cout << "\033[34m You chose to Update a Booking...\033[0m\n";
                cout << "-----------------------------\n";
                q.update(); 
                break;
            case 6: 
                cout << "\033[34m You chose to Display All Bookings...\033[0m\n";
                cout << "-----------------------------\n";
                q.display(); 
                break;
            case 7:
                cout << "\033[34m Exiting the Tour Booking System...\033[0m\n";
                cout << "-----------------------------\n";
                return 0;
            default:
                cout << "\033[31m Invalid Choice. Please try again.\033[0m\n";
                cout << "-----------------------------\n";
        }
    } while (choice != 7);
}
