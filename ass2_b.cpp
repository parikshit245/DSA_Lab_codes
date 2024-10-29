//Assignment 2-B
/*Consider Employee database of PCCOE (at least 20 records).
 Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary.
   Arrange list of Employee alphabetically using Merge Sort. */
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

// Merge function to combine two halves sorted by employee name
void merge(Employee *emp, int left, int mid, int right){
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary arrays to hold the two halves
    Employee *leftArray = new Employee[n1];
    Employee *rightArray = new Employee[n2];

    // Copy data into the temporary arrays
    for(int i = 0; i < n1; i++)
        leftArray[i] = emp[left + i];
    for(int j = 0; j < n2; j++)
        rightArray[j] = emp[mid + 1 + j];

    // Merging the two halves back into the original array
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftArray[i].emp_name <= rightArray[j].emp_name){
            emp[k] = leftArray[i];
            i++;
        } else {
            emp[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArray (if any)
    while(i < n1){
        emp[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArray (if any)
    while(j < n2){
        emp[k] = rightArray[j];
        j++;
        k++;
    }

    // Deallocate temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// MergeSort function to recursively divide and merge the array
void mergeSort(Employee *emp, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(emp, left, mid);
        mergeSort(emp, mid + 1, right);

        // Merge the two sorted halves
        merge(emp, left, mid, right);
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
        emp[i].print(); // Print each employee's details
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
        cout << "3. Sort Employees by Name (MergeSort)\n";
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
                // Sort the employees based on their names using MergeSort
                if (emp != nullptr) {
                    mergeSort(emp, 0, n - 1); // Sort the array by name
                    cout << "Employees sorted by Name successfully!" << endl;
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

    return 0;
}
