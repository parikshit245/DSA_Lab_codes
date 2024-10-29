//Assignment 5
/*Implement a navigation system for a delivery service using a circular linked list to represent routes. 
The navigation system should support the following functionalities: 
a. Add route b. Remove route c. Display route.. */
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1


#include <iostream>
using namespace std;

// Node structure to represent a route in the navigation system
struct Node {
    string route; // Route name or details
    Node* next;   // Pointer to the next route in the list
};

// Class for the navigation system using a circular linked list
class NavigationSystem {
    Node* last; // Pointer to the last node in the circular linked list

public:
    // Constructor to initialize the navigation system
    NavigationSystem() {
        last = nullptr;
    }

    // Function to add a route to the circular linked list
    void addRoute(string routeName) {
        Node* newNode = new Node();
        newNode->route = routeName;

        // If the list is empty
        if (last == nullptr) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next; // Link new node to the first node
            last->next = newNode;       // Link the last node to the new node
            last = newNode;             // Update the last pointer to the new node
        }
        cout << "Route added successfully: " << routeName << endl;
    }

    // Function to remove a route from the circular linked list
    void removeRoute(string routeName) {
        if (last == nullptr) {
            cout << "No routes to remove." << endl;
            return;
        }

        Node* temp = last->next;
        Node* prev = last;

        // Traverse the list to find the node to remove
        do {
            if (temp->route == routeName) {
                if (temp == last && temp->next == last) { // If there's only one node
                    last = nullptr;
                } else if (temp == last) { // If the last node is to be removed
                    prev->next = last->next;
                    last = prev;
                } else {
                    prev->next = temp->next; // Bypass the node to be removed
                }

                delete temp;
                cout << "Route removed successfully: " << routeName << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "Route not found: " << routeName << endl;
    }

    // Function to display all routes in the circular linked list
    void displayRoutes() {
        if (last == nullptr) {
            cout << "No routes to display." << endl;
            return;
        }

        Node* temp = last->next;
        cout << "Routes in the navigation system:" << endl;
        do {
            cout << "- " << temp->route << endl;
            temp = temp->next;
        } while (temp != last->next);
    }
};

int main() {
    NavigationSystem system;
    int choice;
    string routeName;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Route\n";
        cout << "2. Remove Route\n";
        cout << "3. Display Routes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the route to add: ";
            cin >> routeName;
            system.addRoute(routeName);
            break;

        case 2:
            cout << "Enter the route to remove: ";
            cin >> routeName;
            system.removeRoute(routeName);
            break;

        case 3:
            system.displayRoutes();
            break;

        case 4:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); // Continue the menu until user exits

    return 0;
}
