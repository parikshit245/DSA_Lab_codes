#include <iostream>
#define MAX_SIZE 5  

using namespace std;

class Queue {
public:
    int front, rear;     
    int arr[MAX_SIZE];  

    
    Queue() {
        front = rear = 0;  // Initially, front and rear are set to 0 (empty queue)
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == rear;  // If front and rear are the same, the queue is empty
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;  // If the queue wraps around, it's full
    }

    // Enqueue operation for customer arrival
    void addCustomer(int val) {
        if (isFull()) {
            cout << "Checkout queue is full! Please wait.\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;  // Move the rear pointer circularly
        arr[rear] = val;  // Add customer to the queue
        cout << "Customer " << val << " has arrived.\n";
    }

    // Dequeue operation for customer checkout
    void checkoutCustomer() {
        if (isEmpty()) {
            cout << "No customers in queue.\n";
            return;
        }
        front = (front + 1) % MAX_SIZE;  // Move the front pointer circularly
        cout << "Customer has completed checkout.\n";
    }

    // Utility to display the current customers in the queue
    void printQueue() {
        if (isEmpty()) {
            cout << "No customers in the queue.\n";
            return;
        }
        cout << "Customers in the queue: ";
        for (int i = (front + 1) % MAX_SIZE; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;  // Print the last customer in the queue
    }

    // Close the checkout counter (reset the queue)
    void closeCounter() {
        front = rear = 0;  // Reset front and rear to 0 (empty queue)
        cout << "Checkout counter closed. All customers have left.\n";
    }
};

int main() {
    Queue checkoutQueue;
    int choice, customerID;

    do {
        // Display menu options
        cout << "\n----- Supermarket Checkout System -----\n";
        cout << "1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. View Customers\n";
        cout << "4. Close Checkout Counter\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Customer Arrival
                cout << "Enter Customer ID: ";
                cin >> customerID;
                checkoutQueue.addCustomer(customerID);
                break;

            case 2:
                // Customer Checkout
                checkoutQueue.checkoutCustomer();
                break;

            case 3:
                // View Customers
                checkoutQueue.printQueue();
                break;

            case 4:
                // Close Checkout Counter
                checkoutQueue.closeCounter();
                break;

            case 5:
                // Exit
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
