//Assignment 4
// Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results.
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1

#include <iostream>
using namespace std;

// Node class to represent each word in the text editor
class Node {
public:
    Node *prev, *next;
    string data;

    Node() { prev = next = nullptr; }

    Node(string data) {
        prev = next = nullptr;
        this->data = data;
    }

    // Function to display the word stored in the node
    void display() {
        cout << data << " ";
    }
};

// Text Editor class 
class textEditor {
    Node *head, *tail;

public:
    // Constructor to initialize the text editor
    textEditor() { head = tail = nullptr; }

    // Function to insert a word at the end of the sentence
    void insert() {
        string word;
        cout << "Enter the word to add: ";
        cin >> word;
        
        Node *nn = new Node(word);
        
        if (head == nullptr) {
            // If the list is empty, new word becomes both head and tail
            head = tail = nn;
        } else {
            // Add the new node at the end and adjust pointers
            nn->prev = tail;
            tail->next = nn;
            tail = nn;
        }
        cout << "Word added successfully!" << endl;
    }

    // Function to delete a specific word from the sentence
    void deleteText() {
        if (head == nullptr) {
            cout << "No words in the sentence to delete!" << endl;
            return;
        }

        string word;
        cout << "Enter the word to be deleted: ";
        cin >> word;

        Node *cn = head;
        
        // Traverse through the list to find the word
        while (cn != nullptr) {
            if (cn->data == word) {
                // Word found, now perform deletion
                if (cn == head) {
                    head = head->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    } else {
                        tail = nullptr;
                    }
                } else if (cn == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    cn->prev->next = cn->next;
                    cn->next->prev = cn->prev;
                }
                delete cn;
                cout << "Word deleted successfully!" << endl;
                return;
            }
            cn = cn->next;
        }
        cout << "Word not found in the sentence!" << endl;
    }

    // Function to display the current sentence in normal order
    void displayText() {
        if (head == nullptr) {
            cout << "No words in the sentence!" << endl;
            return;
        }

        Node *cn = head;
        cout << "Current sentence: ";
        while (cn != nullptr) {
            cn->display();
            cn = cn->next;
        }
        cout << endl;
    }

    // Function to display the sentence in reverse order
    void reverseText() {
        if (tail == nullptr) {
            cout << "No words in the sentence!" << endl;
            return;
        }

        Node *cn = tail;
        cout << "Sentence in reverse: ";
        while (cn != nullptr) {
            cn->display();
            cn = cn->prev;
        }
        cout << endl;
    }
};

int main() {
    textEditor text;
    int choice;

    // Menu-driven interface
    do {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Insert a word\n";
        cout << "2. Delete a word\n";
        cout << "3. Display sentence\n";
        cout << "4. Display sentence in reverse\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                text.insert();
                break;
            case 2:
                text.deleteText();
                break;
            case 3:
                text.displayText();
                break;
            case 4:
                text.reverseText();
                break;
            case 5:
                cout << "Exiting the program!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
