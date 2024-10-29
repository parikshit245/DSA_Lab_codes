//Assignment 7
// Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results.
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1

#include <iostream>
using namespace std;

// Node to represent each term of the polynomial
class Node {
public:
    int coefficient;  // Coefficient of the term
    int exponent;     // Exponent of the term
    Node* next;       // Pointer to the next term (node)

    Node(int coeff, int exp) {
        coefficient = coeff;
        exponent = exp;
        next = nullptr;
    }
};

// Class to represent the polynomial as a linked list
class Polynomial {
private:
    Node* head;  // Pointer to the head of the list (first term)

public:
    Polynomial() { head = nullptr; }  // Constructor initializes head to nullptr

    // Function to insert a new term into the polynomial
    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display the polynomial
    void display() {
        if (head == nullptr) {
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp != nullptr) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    // Function to add two polynomials and return the result as a new polynomial
    Polynomial addPolynomials(Polynomial poly2) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = poly2.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->exponent == p2->exponent) { //If exponents are equal add the coefficients
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exponent > p2->exponent) { //If p1's exponent is greater, add it to result linked list
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else { //If p2's exponent is greater, add it to result linked list
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }

        // Add any remaining terms from the first polynomial
        while (p1 != nullptr) {
            result.insertTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }

        // Add any remaining terms from the second polynomial
        while (p2 != nullptr) {
            result.insertTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        return result;
    }
};

// Main function with a menu-driven interface
int main() {
    Polynomial poly1, poly2, result;
    int choice, coeff, exp;

    do {
        cout << "\n--- Polynomial Operations Menu ---" << endl;
        cout << "1. Enter the first polynomial" << endl;
        cout << "2. Enter the second polynomial" << endl;
        cout << "3. Add the two polynomials" << endl;
        cout << "4. Display the result" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter terms of the first polynomial (coefficient and exponent, -1 -1 to stop):" << endl;
                while (true) {
                    cin >> coeff >> exp;
                    if (coeff == -1 && exp == -1) break;
                    poly1.insertTerm(coeff, exp);
                }
                break;

            case 2:
                cout << "Enter terms of the second polynomial (coefficient and exponent, -1 -1 to stop):" << endl;
                while (true) {
                    cin >> coeff >> exp;
                    if (coeff == -1 && exp == -1) break;
                    poly2.insertTerm(coeff, exp);
                }
                break;

            case 3:
                result = poly1.addPolynomials(poly2);
                cout << "Polynomials added successfully!" << endl;
                break;

            case 4:
                cout << "Resultant polynomial: ";
                result.display();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
