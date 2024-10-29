// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1

#include<iostream>
using namespace std;

// Node class to represent each website visited
class Node {
    string url;  // Stores the URL of the visited website
public:
    Node *next;  // Pointer to the next node 
    Node() { next = nullptr; }  // Constructor initializes the next pointer to nullptr

    // Function to read a URL from the user
    void readUrl() {
        cout << "Enter the URL of the website: ";
        cin >> url;
    }

    // Function to display the current URL
    void displayUrl() {
        if (!url.empty())
            cout << "Current URL: " << url << endl;
        else
            cout << "No URL to display." << endl;
    }
};

// Class representing the browsing history using a linked list 
class BrowsingHistory {
    Node *top;  // Pointer to the top node (most recent website)
public:
    BrowsingHistory() { top = nullptr; }  // Constructor initializes top pointer to nullptr

    // Function to visit a new page (add new node to the history)
    void visitNewPage();

    // Function to navigate back (remove the most recent node)
    void navigateBack();

    // Function to display the current page (top of the stack)
    void showCurrentPage();
};

// Function to visit a new page and add it to browsing history
void BrowsingHistory::visitNewPage() {
    Node *nn = new Node;  // Create a new node
    nn->readUrl();  // Read the URL from the user

    if (top == nullptr) {  // If the history is empty
        top = nn;  // Make the new node the top node
    } else {
        nn->next = top;  // Set new node's next to point to the current top
        top = nn;  // Move top to the new node
    }

    cout << "You have successfully visited a new page!" << endl;
}

// Function to navigate back (remove the most recent page from the history)
void BrowsingHistory::navigateBack() {
    if (top == nullptr) {
        cout << "Browser history is empty! No page to navigate back to." << endl;
    } else {
        Node *temp = top;  // Temporary pointer to the current top node
        top = top->next;   // Move top to the next node (previous page)
        delete temp;       // Delete the old top node
        cout << "You have navigated back to the previous page." << endl;
    }
}

// Function to display the current page (most recent website)
void BrowsingHistory::showCurrentPage() {
    if (top != nullptr) {
        top->displayUrl();  // Call display function of the top node
    } else {
        cout << "No pages in history." << endl;
    }
}

int main() {
    BrowsingHistory obj;
    int choice;

    do {
        cout << "1. Visit a new page" << endl;
        cout << "2. Navigate back" << endl;
        cout << "3. Show current page" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Handling the user's choice
        switch (choice) {
            case 1:
                obj.visitNewPage();  // Visit a new page
                break;
            case 2:
                obj.navigateBack();  // Navigate back to the previous page
                break;
            case 3:
                obj.showCurrentPage();  // Show the current page
                break;
            case 4:
                cout << "Exiting the browser history system." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);  // Repeat until the user chooses to exit

    return 0;
}
