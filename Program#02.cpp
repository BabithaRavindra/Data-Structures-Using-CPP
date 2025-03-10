#include <iostream>
using namespace std;

// Creates a structure of the node
struct Node
{
    int Tour_ID;
    string Tour_Destination;
    string Passenger_Name;
    float Tour_Price;
    Node *next;
} *head, *temp;

class SLL
{
public:
    // Constructor
    SLL()
    {
        head = NULL;
        temp = head;
    }

    // Insert at the beginning
    void insertAtBeginning()
    {
        Node *newnode = new Node;
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
        newnode->next = head;
        head = newnode;
        cout << "\033[32mNode Inserted at Beginning Successfully!!\033[0m\n";
    }

    // Insert at the end
    void insertAtEnd()
    {
        Node *newnode = new Node;
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
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << "\033[32mNode Inserted at End Successfully!!\033[0m\n";
    }                                                                                                                                                                                                                                                                                                    

    // Insert at a specific position
    void insertAtPosition()
    {
        int pos;
        cout << "\033[34mEnter the Position: \033[0m";
        cin >> pos;

        if (pos <= 0)
        {
            cout << "\033[31mInvalid Position!\033[0m\n";
            return;
        }

        Node *newnode = new Node; 
        cout << "\033[34m Please Enter Tour Details: \033[0m" << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        cout << "\033[34m1. Tour ID:    \033[0m";
        cin >> newnode->Tour_ID;
        cout << "\033[34m2. Tour Destination:   \033[0m";
        cin >> newnode->Tour_Destination;
        cout << "\033[34m3. Passenger Name:   \033[0m";
        cin >> newnode->Passenger_Name;
        cout << "\033[34m4. Tour Price:   \033[0m";
        cin >> newnode->Tour_Price;

        if (pos == 1)
        {
            newnode->next = head;
            head = newnode;
            cout << "\033[32mNode Inserted Successfully at Position 1!!\033[0m\n";
            return;
        }

        temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\033[31mPosition out of range!\033[0m\n";
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
            cout << "\033[32mNode Inserted Successfully at Position " << pos << "!!\033[0m\n";
        }
    }

    // Display the list
    void displayNode()
    {
        Node *curr = head;
        if (head == NULL)
        {
            cout << "\033[31mList is Empty!!\033[0m\n";
            return;
        }
        cout << "\033[34m The tour details are:\033[0m";
        while (curr != NULL)
        {
            cout << "\033[34m1. Tour ID:    \033[0m" << curr->Tour_ID << endl;
            cout << "\033[34m2. Tour Destination:   \033[0m" << curr->Tour_Destination << endl;
            cout << "\033[34m3. Passenger Name:   \033[0m" << curr->Passenger_Name << endl;
            cout << "\033[34m4. Tour Price:   \033[0m" << curr->Tour_Price << endl;
            cout << "\n-----------------------------\n";
            curr = curr->next;
        }
    }

    // Delete From Beginning
    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            return;
        }

        Node *toDelete = head;
        head = head->next;
        delete toDelete;

        cout << "\033[32mNode Deleted from the Beginning Successfully!\033[0m\n";
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            return;
        }

        if (head->next == NULL)
        { // If only one node exists
            delete head;
            head = NULL;
            cout << "\033[32mNode Deleted from the End Successfully!\033[0m\n";
            return;
        }

        Node *curr = head;
        Node *prev = NULL;

        while (curr->next != NULL)
        { // Traverse to the last node
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL; // Update second last node's next pointer
        delete curr;

        cout << "\033[32mNode Deleted from the End Successfully!\033[0m\n";
    }

    // Delete by Tour ID
    void deleteByID()
    {
        if (head == NULL)
        {
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            return;
        }

        int tourID;
        cout << "\033[34mEnter the Tour ID to delete: \033[0m";
        cin >> tourID;

        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            if (curr->Tour_ID == tourID)
            { // Found the node to delete
                if (curr == head)
                { // If the node is the head
                    head = head->next;
                }
                else
                {
                    prev->next = curr->next; // Update previous node's next pointer
                }

                delete curr;
                cout << "\033[32mNode Deleted Successfully!\033[0m\n";
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "\033[31mNode Not Found with Tour ID: " << tourID << "!\033[0m\n";
    }

    // Delete by Position
    void deleteByPosition(int position)
    {
        if (head == NULL)
        {
            cout << "\033[31mList is Empty! Cannot delete.\033[0m\n";
            return;
        }

        if (position == 1)
        { // If position is 1, delete the first node
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "\033[32mNode Deleted from the Beginning!\033[0m\n";
            return;
        }

        Node *curr = head;
        Node *prev = NULL;

        for (int i = 1; i < position && curr != NULL; i++)
        { // Traverse to the node at the desired position
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        { // If position is beyond the length of the list
            cout << "\033[31mPosition Out of Range! Cannot delete.\033[0m\n";
            return;
        }

        prev->next = curr->next; // Update links for deletion
        delete curr;

        cout << "\033[32mNode Deleted Successfully from Position " << position << "!\033[0m\n";
    }

    void countNodes()
    {
        int count = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        cout << "\033[34mNumber of Tours: \033[0m" << count << endl;
    }

    // Search for a tour
    void searchNode()
    {
        int choice;
        cout << "\033[34mSearch By:\033[0m\n";
        cout << "1. Position\n2. Tour Destination\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int pos;
            cout << "\033[34mEnter Position: \033[0m";
            cin >> pos;

            Node *curr = head;
            for (int i = 1; i < pos && curr != NULL; i++)
            {
                curr = curr->next;
            }

            if (curr == NULL)
            {
                cout << "\033[31mPosition out of range!\033[0m\n";
            }
            else
            {
                cout << "\033[34mFound Tour:\033[0m\n";
                cout << "\033[34mTour ID: \033[0m" << curr->Tour_ID
                     << "\n\033[34mTour Destination: \033[0m" << curr->Tour_Destination
                     << "\n\033[34mPassenger Name: \033[0m" << curr->Passenger_Name
                     << "\n\033[34mTour Price: \033[0m" << curr->Tour_Price << endl;
            }
        }
        else if (choice == 2)
        {
            string destination;
            cout << "\033[34mEnter Tour Destination to Search: \033[0m";
            cin >> destination;

            Node *curr = head;
            while (curr != NULL)
            {
                if (curr->Tour_Destination == destination)
                {
                    cout << "\033[34mFound Tour:\033[0m\n";
                    cout << "\033[34mTour ID: \033[0m" << curr->Tour_ID
                         << "\n\033[34mTour Destination: \033[0m" << curr->Tour_Destination
                         << "\n\033[34mPassenger Name: \033[0m" << curr->Passenger_Name
                         << "\n\033[34mTour Price: \033[0m" << curr->Tour_Price << endl;
                    return;
                }
                curr = curr->next;
            }
            cout << "\033[31mTour Not Found!\033[0m\n";
        }
        else
        {
            cout << "\033[31mInvalid Choice!\033[0m\n";
        }
    }
};

int main()
{
    int choice;
    SLL tourList;

    while (true)
    {
        cout << "\033[96m\n--------------------------------------------------------------------------------------\n\033[0m";
        cout << "\033[96m                                     ᗪ E   ᐯ I ᗩ ᒍ E  \033[0m\n";
        cout << "\n\033[96m                  T O U R   M A N A G E M E N T   S Y S T E M   M E N U \033[0m\n";
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
        cout << "\n-----------------------------\n";

        switch (choice)
        {
        case 1:
        {
            int insertChoice;
            cout << "\033[96m Submenu: Insert Options\033[0m\n";
            cout << "\033[96m1. Insert at Beginning\n\033[0m";
            cout << "\033[96m2. Insert at End\n\033[0m";
            cout << "\033[96m3. Insert at Specific Position\n\033[0m";
            cout << "\033[96mEnter your choice: \033[0m";
            cin >> insertChoice;
            cout << "-----------------------------\n";

            switch (insertChoice)
            {
            case 1:
                cout << "\033[34m You chose to Insert at Beginning...\033[0m";
                tourList.insertAtBeginning();
                break;
            case 2:
                cout << "\033[34m You chose to Insert at End...\033[0m\n";
                tourList.insertAtEnd();
                break;
            case 3:
                cout << "\033[34m You chose to Insert at Specific Position...\033[0m\n";
                tourList.insertAtPosition();
                break;
            default:
                cout << "\033[31m Invalid Choice. Returning to main menu...\033[0m\n";
            }
            break;
        }
        case 2:
            cout << "\033[34m You chose to Display Tours...\033[0m\n";
            cout << "\n-----------------------------\n";
            tourList.displayNode();
            break;

        case 3:
        {
            int deleteChoice;
            cout << "\033[34m Submenu: Delete Options\033[0m\n";
            cout << "1. Delete from Beginning\n";
            cout << "2. Delete from End\n";
            cout << "3. Delete by Tour ID\n";
            cout << "4. Delete by Position\n";
            cout << "Enter your choice: ";
            cin >> deleteChoice;
            cout << "\n-----------------------------\n";

            switch (deleteChoice)
            {
            case 1:
                cout << "\033[34m You chose to Delete from Beginning...\033[0m\n";
                tourList.deleteFromBeginning();
                break;
            case 2:
                cout << "\033[34m You chose to Delete from End...\033[0m\n";
                tourList.deleteFromEnd();
                break;
            case 3:
                cout << "\033[34m You chose to Delete by Tour ID...\033[0m\n";
                tourList.deleteByID();
                break;
            case 4:
                int position;
                cout << "\033[34m You chose to Delete by Position...\033[0m\n";
                cout << "\n-----------------------------\n";
                cout << "Enter the position of the tour you want to delete: ";
                cin >> position;
                tourList.deleteByPosition(position);
                break;
            default:
                cout << "\033[31m Invalid Choice. Returning to main menu...\033[0m\n";
            }
            break;
        }
        case 4:
            cout << "\033[34m You chose to Search Tour...\033[0m\n";
            cout << "\n-----------------------------\n";
            tourList.searchNode();
            break;

        case 5:
            cout << "\033[34m You chose to Count Tours...\033[0m\n";
            cout << "\n-----------------------------\n";
            tourList.countNodes();
            break;

        case 6:
            cout << "\033[34m Exiting the Tour Management System...\033[0m\n";
            cout << "-----------------------------\n";
            return 0;

        default:
            cout << "\033[31m Invalid Choice. Please try again.\033[0m\n";
        }
    }
}
