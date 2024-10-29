#include <iostream>
using namespace std;

// Node class to represent each customer in the waitlist
class Node {
public:
    int customer_id;  // stores the ID of the customer
    Node* next;  // pointer to the next customer in the waitlist

    // Constructor to initialize 'next' as nullptr
    Node() { next = nullptr; }

    // Function to read the customer ID from user input
    void read() {
        cout << "Enter customer id: ";
        cin >> customer_id;
    }

    // Function to display the customer ID
    void display() {
        cout << "Customer ID: " << customer_id << endl;
    }
};

// Waitlist class to manage the queue of customers
class waitlist {
    Node* front;  // pointer to the front of the queue (first customer)
    Node* rear;   // pointer to the rear of the queue (last customer)

public:
    // Constructor to initialize front and rear as nullptr (empty queue)
    waitlist() { front = rear = nullptr; }

    // Function to add a new customer to the waitlist (enqueue)
    void addCustomer() {
        Node* nn = new Node;  // create a new customer node
        nn->read();  // read the customer ID from input

        // If the waitlist is empty, both front and rear point to the new node
        if (front == nullptr) {
            front = rear = nn;
        } else {
            // Otherwise, add the new node at the end of the queue
            rear->next = nn;
            rear = nn;  // update the rear pointer
        }
        cout << "Customer added successfully!" << endl;
    }

    // Function to serve a customer (dequeue)
    void serveCustomer() {
        // If there are no customers, print an error message
        if (front == nullptr) {
            cout << "No customer to serve" << endl;
            return;
        }

        // Store the front node in a temporary pointer to delete later
        Node* temp = front;
        cout << "Serving customer with ID " << front->customer_id << endl;

        // If there's only one customer, set both front and rear to nullptr
        if (front == rear) {
            front = rear = nullptr;
        } else {
            // Otherwise, move the front pointer to the next customer
            front = front->next;
        }

        delete temp;  // delete the served customer to free memory
    }

    // Function to display all customers in the waitlist
    void displayCustomer() {
        // If the queue is empty, print a message
        if (front == nullptr) {
            cout << "No customers to display" << endl;
            return;
        }

        Node* temp = front;  // temporary pointer to traverse the queue
        cout << "Waitlist: " << endl;

        // Traverse the queue and display each customer's ID
        while (temp != nullptr) {
            temp->display();
            temp = temp->next;
        }
    }
};

int main() {
    waitlist obj;  // create an instance of the waitlist
    int choice;    // variable to store the user's menu choice

    // Loop to display the menu until the user chooses to exit
    do {
        // Display the menu options
        cout << "\nMenu:\n";
        cout << "1. Add customer to waitlist\n";
        cout << "2. Serve customer\n";
        cout << "3. Display waitlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // read the user's choice

        // Execute the corresponding function based on the user's choice
        switch (choice) {
        case 1:
            obj.addCustomer();  // Add a customer to the waitlist
            break;

        case 2:
            obj.serveCustomer();  // Serve the customer at the front of the waitlist
            break;

        case 3:
            obj.displayCustomer();  // Display the waitlist
            break;

        case 4:
            cout << "Exiting the program..." << endl;  // Exit the program
            break;

        default:
            cout << "Invalid choice, please try again!" << endl;  // Invalid input handling
            break;
        }

    } while (choice != 4);  // Repeat the menu until the user selects 'Exit'

    return 0;  // Return 0 to indicate successful program termination
}
