/*
Name-Parikshit Rajpurohi
Roll No.-123B1B238

Topic-Write a program to convert infix expression to postfix, infix expression to prefix and evaluation of postfix and prefix expression.

*/

#include <iostream>
#include <string>
using namespace std;

#define MAX 100 // Define the maximum size of the stack

// Class to implement stack functionality
class Stack {
private:
    int arr[MAX]; 
    int top;     

public:
    // Constructor to initialize stack
    Stack() {
        top = -1; // Initialize the top to -1, indicating an empty stack
    }

    // Function to push data onto the stack
    void push(int x) {
        if (top < MAX - 1) {
            arr[++top] = x;  
        }
    }

    // Function to pop data from the stack
    int pop() {
        if (top >= 0) { 
            return arr[top--]; 
        } else {
            return 0; // Return 0 if stack is empty
        }
    }

    // Function to return the top element without removing it
    int peek() {
        if (top >= 0) { 
            return arr[top]; 
        } else {
            return 0; // Return 0 if stack is empty
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1; 
    }
};

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2; 
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(const char infix[], char postfix[]) {
    Stack s; // Create a stack object
    int j = 0; // Index for the postfix expression

    // Loop through the infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i]; // Current character

        // If the character is an operand, add it to the postfix expression
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            postfix[j++] = c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is ')', pop from stack until '(' is found
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); // Pop the '('
        }
        // If the character is an operator
        else {
            // Pop operators from the stack with higher or equal precedence
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix[j++] = s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop the remaining operators in the stack
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

// Function to reverse a string
void reverse(char str[]) {
    int length = 0;
    while (str[length] != '\0') length++; // Find the length of the string
    // Reverse the string by swapping characters
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(const char infix[], char prefix[]) {
    char reversed[MAX]; // Array to hold the reversed infix expression
    int i = 0;

    // Copy infix to reversed
    while (infix[i] != '\0') {
        reversed[i] = infix[i];
        i++;
    }
    reversed[i] = '\0'; // Null-terminate the reversed string
    reverse(reversed);  // Reverse the infix expression

    Stack s;  // Create a stack object
    int j = 0; // Index for the prefix expression

    // Loop through the reversed infix expression
    for (int i = 0; reversed[i] != '\0'; i++) {
        char c = reversed[i]; // Current character

        // If the character is an operand, add it to the prefix expression
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            prefix[j++] = c;
        }
        // If the character is ')', push it onto the stack
        else if (c == ')') {
            s.push(c);
        }
        // If the character is '(', pop from stack until ')' is found
        else if (c == '(') {
            while (!s.isEmpty() && s.peek() != ')') {
                prefix[j++] = s.pop();
            }
            s.pop(); // Pop the ')'
        }
        // If the character is an operator
        else {
            // Pop operators from the stack with lower precedence
            while (!s.isEmpty() && precedence(c) < precedence(s.peek())) {
                prefix[j++] = s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop the remaining operators in the stack
    while (!s.isEmpty()) {
        prefix[j++] = s.pop();
    }

    prefix[j] = '\0';   // Null-terminate the prefix string
    reverse(prefix);    // Reverse the result to get prefix
}

// Function to perform operations for evaluation
int performOperation(char op, int val1, int val2) {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
        default: return 0; // Return 0 for unsupported operations
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char postfix[]) {
    Stack s; // Create a stack object
    // Loop through the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) { // If the character is a digit, push it onto the stack
            s.push(c - '0'); // Convert char to int
        } else { // If the character is an operator
            int val2 = s.pop();
            int val1 = s.pop();
            s.push(performOperation(c, val1, val2)); // Perform the operation
        }
    }
    return s.pop(); // Return the final result
}

// Function to evaluate a prefix expression
int evaluatePrefix(const char prefix[]) {
    Stack s; // Create a stack object
    int length = 0;

    // Find the length of the prefix string
    while (prefix[length] != '\0') length++;

    // Loop through the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isdigit(c)) { // If the character is a digit, push it onto the stack
            s.push(c - '0'); // Convert char to int
        } else { // If the character is an operator
            int val1 = s.pop();
            int val2 = s.pop();
            s.push(performOperation(c, val1, val2)); // Perform the operation
        }
    }
    return s.pop(); // Return the final result
}

int main() {
    char infix[MAX];   
    char postfix[MAX]; 
    char prefix[MAX]; 
    int choice;        

    cout << "\nMenu:\n";
    cout << "1. Convert Infix to Postfix\n";
    cout << "2. Convert Infix to Prefix\n";
    cout << "3. Evaluate Postfix Expression\n";
    cout << "4. Evaluate Prefix Expression\n";
    cout << "5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice; 

        switch (choice) {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> infix; 
                infixToPostfix(infix, postfix); 
                cout << "Postfix expression: " << postfix << endl;
                break;

            case 2:
                cout << "Enter an infix expression: ";
                cin >> infix; 
                infixToPrefix(infix, prefix); // Convert to prefix
                cout << "Prefix expression: " << prefix << endl;
                break;

            case 3:
                cout << "Enter a postfix expression: ";
                cin >> postfix;
                cout << "Evaluation result: " << evaluatePostfix(postfix) << endl;
                break;

            case 4:
                cout << "Enter a prefix expression: ";
                cin >> prefix; 
                cout << "Evaluation result: " << evaluatePrefix(prefix) << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5); // Loop until the user chooses to exit

    return 0;
}
