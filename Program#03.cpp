#include <iostream>
using namespace std;

// Creates a structure of the node
struct Node {
    int Tour_ID;
    string Tour_Destination;
    string Passenger_Name;
    float Tour_Price;
    Node *next;
    Node *prev; // Added previous pointer
} *head, *tail;

class DLL {
public:
    // Constructor
    DLL() {
        head = NULL;
        tail = NULL;
    }

    // Insert at the beginning
    void insertAtBeginning() {
        Node *newnode = new Node;
        if (!newnode) {
        cout << "\033[31mMemory Allocation Failed!\033[0m\n";
        cout << "-----------------------------\n";
        return;}
        cout << "\n-----------------------------\n";
        cout << "\033[34m Please Enter Tour Details:\n \033[0m" << endl;
        cout << "\033[34m1. Tour ID:    \033[0m";
        cin >> newnode->Tour_ID;
        cout << "\033[34m2. Tour Destination:   \033[0m";
        cin >> newnode->Tour_Destination;
        cout << "\033[34m3. Passenger Name:   \033[0m";
        cin >> newnode->Passenger_Name;
        cout << "\033[34m4. Tour Price:   \033[0m";
        cin >> newnode->Tour_Price;

        newnode->next = head;
        newnode->prev = NULL;

        if (head != NULL) {
            head->prev = newnode;
        } else {
            tail = newnode; // Update tail if list was empty
        }

        head = newnode;
        cout << "-----------------------------\n";
        cout << "\033[32mNode Inserted at Beginning Successfully!!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Insert at the end
    void insertAtEnd() {
        Node *newnode = new Node;
        if (!newnode) {
        cout << "\033[31mMemory Allocation Failed!\033[0m\n";
        cout << "-----------------------------\n";
        return;}
        cout << "\n-----------------------------\n";
        cout << "\033[34m Please Enter Tour Details: \033\n[0m" << endl;
        cout << "\033[34m1. Tour ID:    \033[0m";
        cin >> newnode->Tour_ID;
        cout << "\033[34m2. Tour Destination:   \033[0m";
        cin >> newnode->Tour_Destination;
        cout << "\033[34m3. Passenger Name:   \033[0m";
        cin >> newnode->Passenger_Name;
        cout << "\033[34m4. Tour Price:   \033[0m";
        cin >> newnode->Tour_Price;

        newnode->next = NULL;
        newnode->prev = tail;

        if (tail != NULL) {
            tail->next = newnode;
        } else {
            head = newnode; // Update head if list was empty
        }

        tail = newnode;
        cout << "\n-----------------------------\n";
        cout << "\033[32mNode Inserted at End Successfully!!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Insert at Position
    void insertAtPosition(int position) {
        if (position <= 0) {
            cout << "\033[31mInvalid Position!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *newnode = new Node;
        if (!newnode) {
        cout << "\033[31mMemory Allocation Failed!\033[0m\n";
        cout << "-----------------------------\n";
        return;}
        cout << "\n-----------------------------\n";
        cout << "\033[34m Please Enter Tour Details: \033[0m" << endl;
        cout << "\033[34m1. Tour ID:    \033[0m";
        cin >> newnode->Tour_ID;
        cout << "\033[34m2. Tour Destination:   \033[0m";
        cin >> newnode->Tour_Destination;
        cout << "\033[34m3. Passenger Name:   \033[0m";
        cin >> newnode->Passenger_Name;
        cout << "\033[34m4. Tour Price:   \033[0m";
        cin >> newnode->Tour_Price;

        if (position == 1) {
            newnode->next = head;
            newnode->prev = NULL;
            if (head != NULL) head->prev = newnode;
            head = newnode;
            if (tail == NULL) tail = newnode;
            cout << "-----------------------------\n";
            cout << "\033[32mNode Inserted Successfully at Position 1!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *curr = head;
        for (int i = 1; i < position - 1 && curr != NULL; i++) curr = curr->next;

        if (curr == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mPosition out of range!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        newnode->next = curr->next;
        newnode->prev = curr;
        if (curr->next != NULL) curr->next->prev = newnode;
        else tail = newnode;
        curr->next = newnode;
        cout << "-----------------------------\n";
        cout << "\033[32mNode Inserted Successfully at Position " << position << "!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Display the list
    void displayNode() {
        if (head == NULL) {
            cout << "\033[31mList is Empty!!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *curr = head;
        cout << "\033[34m The tour details are:\n\033[0m";
        cout << "-----------------------------\n";
        while (curr != NULL) {
            cout << "\033[34m1. Tour ID:    \033[0m" << curr->Tour_ID << endl;
            cout << "\033[34m2. Tour Destination:   \033[0m" << curr->Tour_Destination << endl;
            cout << "\033[34m3. Passenger Name:   \033[0m" << curr->Passenger_Name << endl;
            cout << "\033[34m4. Tour Price:   \033[0m" << curr->Tour_Price << endl;
            cout << "-----------------------------\n";
            curr = curr->next;
        }
    }

       // Search list by Position
    void searchByPosition(int position) {
        if (position <= 0) {
            cout << "-----------------------------\n";
            cout << "\033[31mInvalid Position!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *curr = head;
        for (int i = 1; i < position && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mPosition out of range!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }
        cout << "-----------------------------\n";
        cout << "\033[34mFound Tour at Position " << position << ":\033[0m\n";
        cout << "-----------------------------\n";
        cout << "\033[34mTour ID: \033[0m" << curr->Tour_ID
             << "\n\033[34mTour Destination: \033[0m" << curr->Tour_Destination
             << "\n\033[34mPassenger Name: \033[0m" << curr->Passenger_Name
             << "\n\033[34mTour Price: \033[0m" << curr->Tour_Price << endl;
        cout << "-----------------------------\n";
    }

    // Search by ID
    void searchByID(int tourID) {
        Node *curr = head;

        while (curr != NULL) {
            if (curr->Tour_ID == tourID) {
                cout << "-----------------------------\n";
                cout << "\033[34mFound Tour with ID " << tourID << ":\033[0m\n";
                cout << "-----------------------------\n";
                cout << "\033[34mTour ID: \033[0m" << curr->Tour_ID
                     << "\n\033[34mTour Destination: \033[0m" << curr->Tour_Destination
                     << "\n\033[34mPassenger Name: \033[0m" << curr->Passenger_Name
                     << "\n\033[34mTour Price: \033[0m" << curr->Tour_Price << endl;
                cout << "-----------------------------\n";
                return;
            }
            curr = curr->next;
        }

        cout << "\033[31mTour with ID " << tourID << " not found!\033[0m\n";
    }

    // Delete from Beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *toDelete = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // Update tail if list becomes empty
        }

        delete toDelete;
        cout << "-----------------------------\n";
        cout << "\033[32mNode Deleted from the Beginning Successfully!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Delete from the End
    void deleteFromEnd() {
        if (tail == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *toDelete = tail;
        tail = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL; // Update head if list becomes empty
        }

        delete toDelete;
        cout << "-----------------------------\n";
        cout << "\033[32mNode Deleted from the End Successfully!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Delete by Position
    void deleteByPosition(int position) {
        if (head == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        if (position <= 0) {
            cout << "-----------------------------\n";
            cout << "\033[31mInvalid Position!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        if (position == 1) {
            Node *toDelete = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL; // List is now empty
            delete toDelete;
            cout << "-----------------------------\n";
            cout << "\033[32mNode Deleted Successfully from Position 1!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        Node *curr = head;
        for (int i = 1; i < position && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mPosition out of range!\033[0m\n";
            cout << "-----------------------------\n";
            return;
        }

        if (curr->prev != NULL) curr->prev->next = curr->next;
        if (curr->next != NULL) curr->next->prev = curr->prev;
        else tail = curr->prev;

        delete curr;
        cout << "-----------------------------\n";
        cout << "\033[32mNode Deleted Successfully from Position " << position << "!\033[0m\n";
        cout << "-----------------------------\n";
    }

    // Delete by ID
    void deleteByID(int tourID) {
        if (head == NULL) {
            cout << "-----------------------------\n";
            cout << "\033[31mList is Empty! Cannot delete.\033[0m";
            cout << "-----------------------------\n";
            return;
        }

        Node *curr = head;

        while (curr != NULL) {
            if (curr->Tour_ID == tourID) {
                if (curr == head) {
                    head = head->next;
                    if (head != NULL)
                        head->prev = NULL;
                    else
                        tail = NULL; // List becomes empty
                } else if (curr == tail) {
                    tail = tail->prev;
                    if (tail != NULL) tail->next = NULL;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                delete curr;
                cout << "-----------------------------\n";
                cout << "\033[32mNode Deleted Successfully with Tour ID " << tourID << "!\033[0m";
                cout << "-----------------------------\n";
                return;
            }

            curr = curr->next;
        }

        cout << "-----------------------------\n";
        cout << "\033[31mTour with ID " << tourID << " not found!\033[0m";
        cout << "-----------------------------\n";
    }

    // Count Nodes
    void countNodes() {
        int count = 0;
        Node *curr = head;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        cout << "\033[34mNumber of Tours: \033[0m" << count << endl;
        cout << "-----------------------------\n";
    }
};

// Main menu
int main() {
    DLL tourList;
    int choice;

    do {
        cout << "\033[96m\n--------------------------------------------------------------------------------------\n\033[0m";
        cout << "\033[96m                                     ᗪ E   ᐯ I ᗩ ᒍ E  \033[0m\n";
        cout << "\033[96m                      T O U R   M A N A G E M E N T   S Y S T E M   M E N U \033[0m\n";
        cout << "\033[96m--------------------------------------------------------------------------------------\033[0m\n";
        cout << "\033[96m   Menu:\033[0m" << endl;
        cout << "\033[96m   1. Insert Tour\033[0m" << endl;
        cout << "\033[96m   2. Display Tours\033[0m" << endl;
        cout << "\033[96m   3. Delete Tour\033[0m" << endl;
        cout << "\033[96m   4. Search Tour\033[0m" << endl;
        cout << "\033[96m   5. Count Tours\033[0m" << endl;
        cout << "\033[96m   6. Exit\033[0m" << endl;
        cout << "\033[96m   Enter Your Choice:      \033[0m";
        cin >> choice;
        cout << "-----------------------------\n";

        if (cin.fail()) { 
            cout << "\033[31mERROR: Invalid input! Enter a number.\033[0m\n";
            cout << "-----------------------------\n";
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Remove bad input
            continue; // Restart loop
        }

        switch (choice) {
        case 1: {
            int insertChoice;
            cout << "\033[34m \nSubmenu: Insert Options\033[0m\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Insert at Specific Position\n";
            cout << "\nEnter your choice: ";
            cin >> insertChoice;
            cout << "\n-----------------------------\n";

            switch (insertChoice) {
            case 1:
                cout << "\033[34m You chose to Insert at Beginning...\033[0m";
                tourList.insertAtBeginning();
                break;
            case 2:
                cout << "\033[34m You chose to Insert at End...\033[0m";
                tourList.insertAtEnd();
                break;
            case 3: {
                int position;
                cout << "\033[34m Enter the Position: \033[0m";
                cin >> position;
                tourList.insertAtPosition(position);
                break;
            }
            default:
                cout << "\033[31m Invalid Choice. Returning to main menu...\033[0m\n";
                cout << "-----------------------------\n";
            }
            break;
        }
        case 2:
            cout << "\033[34m You chose to Display Tours...\033[0m\n";
            cout << "\n-----------------------------\n";
            tourList.displayNode();
            break;

        case 3: {
            int deleteChoice;
            cout << "\033[34m \nSubmenu: Delete Options\033[0m\n";
            cout << "1. Delete from Beginning\n";
            cout << "2. Delete from End\n";
            cout << "3. Delete by Position\n";
            cout << "4. Delete by Tour ID\n";
            cout << "\nEnter your choice: ";
            cin >> deleteChoice;
            cout << "\n-----------------------------\n";

            switch (deleteChoice) {
            case 1:
                cout << "\033[34m You chose to Delete from Beginning...\033[0m\n";
                tourList.deleteFromBeginning();
                break;
            case 2:
                cout << "\033[34m You chose to Delete from End...\033[0m\n";
                tourList.deleteFromEnd();
                break;
            case 3: {
                int position;
                cout << "\033[34m Enter the Position to Delete: \033[0m";
                cin >> position;
                tourList.deleteByPosition(position);
                break;
            }
            case 4: {
                int tourID;
                cout << "\033[34m Enter the Tour ID to Delete: \033[0m";
                cin >> tourID;
                tourList.deleteByID(tourID);
                break;
            }
            default:
                cout << "\033[31m Invalid Choice. Returning to main menu...\033[0m";
            }
            break;
        }
        case 4: {
            int searchChoice;
            cout << "\033[34m \nSubmenu: Search Options\033[0m\n";
            cout << "1. Search by Position\n";
            cout << "2. Search by Tour ID\n";
            cout << "\nEnter your choice: ";
            cin >> searchChoice;
            cout << "\n-----------------------------\n";

            switch (searchChoice) {
            case 1: {
                int position;
                cout << "\033[34m Enter the Position to Search: \033[0m";
                cin >> position;
                tourList.searchByPosition(position);
                break;
            }
            case 2: {
                int tourID;
                cout << "\033[34m Enter the Tour ID to Search: \033[0m";
                cin >> tourID;
                tourList.searchByID(tourID);
                break;
            }
            default:
                cout << "\033[31m Invalid Choice. Returning to main menu...\033[0m\n";
            }
            break;
        }
        case 5:
            cout << "\033[34m You chose to Count Tours...\033[0m\n";
            cout << "-----------------------------\n";
            tourList.countNodes();
            break;

        case 6:
            cout << "\033[34m Exiting the Tour Management System...\033[0m\n";
            cout << "-----------------------------\n";
            return 0;

        default:
            cout << "\033[31m Invalid Choice. Please try again.\033[0m\n";
            cout << "-----------------------------\n";
        }
    } while (choice != 6);
}