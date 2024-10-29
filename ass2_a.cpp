//Assignment 2-A
/*Consider Employee database of PCCOE (at least 20 records).
 Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary.
   Arrange list of employees according to EMP-ID in ascending order using Quick Sort */
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1


#include<iostream>
using namespace std;

// Employee class to store employee information
class Employee{
public:
    int emp_id;           // Employee ID
    string emp_name;      // Employee Name
    float emp_salary;     // Employee Salary

    // Constructor to initialize Employee object
    Employee(int id=0, string name="", float salary=0.0){
        this->emp_id = id;
        this->emp_name = name;
        this->emp_salary = salary;
    }

    // Function to print the details of an employee
    void print(){
        cout << "ID: " << emp_id << endl;
        cout << "Name: " << emp_name << endl;
        cout << "Salary: " << emp_salary << endl;
    }
};

// Swapping two employees in the array based on their index
void swaping(Employee *emp, int i, int j){
    Employee temp = emp[i]; 
    emp[i] = emp[j];        
    emp[j] = temp;          
}

// Partition function to rearrange the array around a pivot (QuickSort)
int partition(Employee *emp, int low, int high){
    Employee pivot = emp[low]; // Set the first element as pivot
    int left = low + 1;        // Left pointer starts just after pivot
    int right = high;          // Right pointer starts at the end of the array

    // Continue until the two pointers cross
    while(left <= right){
        // Move the left pointer to the right until we find an element greater than the pivot
        while(left <= right && emp[left].emp_id <= pivot.emp_id){
            left++;
        }
        // Move the right pointer to the left until we find an element less than or equal to the pivot
        while(left <= right && emp[right].emp_id > pivot.emp_id){
            right--;
        }
        // If left pointer is still less than right, swap the two elements
        if(left < right){
            swaping(emp, left, right);
        }
    }
    // Swap the pivot with the element at the right pointer (to place it at its correct sorted position)
    swaping(emp, low, right);
    return right;
}

// QuickSort function to recursively sort the array
void QuickSort(Employee *emp, int low, int high){
    if(low < high){
        int parIndex = partition(emp, low, high); // Get partition index
        QuickSort(emp, low, parIndex);            // Recursively sort left part
        QuickSort(emp, parIndex + 1, high);       // Recursively sort right part
    }
}

// Function to handle employee data input
void inputEmployees(Employee *emp, int n){
    for(int i = 0; i < n; i++){
        int id;
        string name;
        float salary;

        cout << "Enter details of employee " << i + 1 << ":" << endl;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Salary: "; cin >> salary;

        // Create a new Employee object and assign it to the array
        emp[i] = Employee(id, name, salary);
    }
}

// Function to display all employees
void displayEmployees(Employee *emp, int n){
    cout << "\nEmployee Data:" << endl;
    for(int i = 0; i < n; i++){
        emp[i].print(); 
        cout << endl;
    }
}

// Main function
int main(){
    int choice, n;
    Employee *emp = nullptr; // Pointer to hold dynamic array of employees

    do {
        // Display menu options
        cout << "\nEmployee Management Menu:\n";
        cout << "1. Enter Employee Details\n";
        cout << "2. Display Employee Data\n";
        cout << "3. Sort Employees by ID (QuickSort)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Input the number of employees and their details
                cout << "Enter the number of employees: ";
                cin >> n;
                emp = new Employee[n]; // Allocate memory for n employees
                inputEmployees(emp, n); // Get employee data
                break;

            case 2:
                // Display the employee data
                if (emp != nullptr) {
                    displayEmployees(emp, n);
                } else {
                    cout << "No employee data available!" << endl;
                }
                break;

            case 3:
                // Sort the employees based on their IDs using QuickSort
                if (emp != nullptr) {
                    QuickSort(emp, 0, n - 1); // Sort the array
                    cout << "Employees sorted by ID successfully!" << endl;
                } else {
                    cout << "No employee data available to sort!" << endl;
                }
                break;

            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                // Handle invalid menu options
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 4); // Loop until the user selects 'Exit'

    // Clean up dynamically allocated memory (if any)
    if (emp != nullptr) {
        delete[] emp;
    }

    return 0;
}
