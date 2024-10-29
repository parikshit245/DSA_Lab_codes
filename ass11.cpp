// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1
// Title:  Consider an employee database of N employees. 
//         Make use of a hash table implementation to quickly look up the employer's id number.


#include <iostream>
using namespace std;

#define size 10  // Define the size of the hash table

// Employee class to store individual employee details
class Employee {
    int EmpId;    // Unique employee ID
    string name;  // Name of the employee
    int salary;   // Salary of the employee

public:
    // Function to return the employee ID
    int get_id() {
        return EmpId;
    }

    // Function to read employee details from user input
    void read() {
        cout << "Enter Employee ID: ";
        cin >> EmpId;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display() {
        cout << "Employee ID: " << EmpId << " | Name: " << name << " | Salary: " << salary << endl;
    }
};

// HashTable class to store Employee objects using open addressing for collision resolution
class Hashtable {
public:
    Employee e[size];  // Array to store employees
    int flag[size];    // Flag array to indicate occupied (1) or empty (0) slots

    // Constructor initializes the flag array to mark all slots as empty
    Hashtable() {
        for (int i = 0; i < size; i++) {
            flag[i] = 0;  // 0 indicates an empty slot
        }
    }

    // Function to insert a new employee into the hash table
    void insert() {
        Employee newR;
        newR.read();  // Read employee details
        int empId = newR.get_id();
        int pos = empId % size;  // Hash function to get initial position

        // Try to find an empty slot using linear probing
        bool inserted = false;
        for (int i = 0; i < size; i++) {
            if (flag[pos] == 0) { // If the slot is empty
                e[pos] = newR;    // Store the employee
                flag[pos] = 1;    // Mark the slot as occupied
                cout << "Employee added at index " << pos << endl;
                inserted = true;
                break;
            }
            pos = (pos + 1) % size; // Move to the next slot (linear probing)
        }

        // If no slot was available, the table is full
        if (!inserted) {
            cout << "Hash table is full. Could not insert employee." << endl;
        }
    }

    // Function to delete an employee by their ID
    void deleteEmp() {
        int id;
        cout << "Enter Emp ID to delete: ";
        cin >> id;

        bool found = false;
        // Loop through the table to find the employee with the given ID
        for (int i = 0; i < size; i++) {
            if (flag[i] == 1 && e[i].get_id() == id) { // If slot is occupied and ID matches
                flag[i] = 0; // Mark the slot as empty
                cout << "Employee with ID " << id << " deleted from index " << i << endl;
                found = true;
                break;
            }
        }

        // If employee was not found, print a message
        if (!found) {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    // Function to display the contents of the hash table
    void displaydata() {
        for (int i = 0; i < size; i++) {
            if (flag[i] == 0) {  // If slot is empty
                cout << "Index " << i << ": --" << endl;
            } else {  // Slot is occupied, display the employee details
                cout << "Index " << i << ": ";
                e[i].display();
            }
        }
    }
};

int main() {
    Hashtable obj;  // Create an instance of Hashtable
    int choice;

    // Menu-driven interface for user interactions
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user's choice
        switch (choice) {
            case 1:
                obj.insert();  // Insert a new employee
                break;
            case 2:
                obj.displaydata();  // Display all employees
                break;
            case 3:
                obj.deleteEmp();  // Delete an employee by ID
                break;
            case 4:
                cout << "Exiting..." << endl;  // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);  // Repeat until the user chooses to exit

    return 0;
}
