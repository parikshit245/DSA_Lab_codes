//Assignment 1-A
/*Consider a student database of SY COMP class (at least 15 records). 
Database contains different fields of every student like Roll No, Name and SGPA. 
 Arrange list of students to find out first ten toppers from a class using insertion sort. */
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1


#include<iostream>
using namespace std;

class Student {
    char name[10]; // Name of the student
    int rollno;    // Roll number of the student
    float sgpa;    // SGPA of the student

public:
    // Function to read student details
   void read(int i) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter roll no of student " << i + 1 << ": ";
        cin >> rollno;
        cout << "Enter sgpa of student " << i + 1 << ": ";
        cin >> sgpa;
    }

    // Function to display student details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "SGPA: " << sgpa << endl;
    }

    // Friend function to perform insertion sort based on SGPA
    friend void insertionSort(Student s[], int n);
};

// Function to perform insertion sort based on SGPA
void insertionSort(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student S = s[i]; // Take the i-th student as the key
        int j = i - 1;

        // Sort students in descending order based on SGPA
        while (s[j].sgpa < S.sgpa && j >= 0) {
            s[j + 1] = s[j]; // Shift the elements
            j--;
        }
        s[j + 1] = S; // Insert the student at the correct position
    }
}

int main() {
    Student obj[20]; // Array to hold up to 20 student objects
    int n = 0;       // Number of students
    int choice;      // User's menu choice

    do {
        // Display the menu options
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Sort Students by SGPA\n";
        cout << "3. Display All Students\n";
        cout << "4. Display Toppers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add student details
                 cout << "Enter number of students: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    obj[i].read(i); // Reading each student's details
                }
                break;

            case 2:
                // Sort students by SGPA using insertion sort
                if (n > 0) {
                    insertionSort(obj, n);
                    cout << "Students sorted by SGPA (Highest to Lowest)." << endl;
                } else {
                    cout << "No students to sort." << endl;
                }
                break;

            case 3:
                // Display all students
                if (n > 0) {
                    cout << "\nStudent Details:\n";
                    for (int i = 0; i < n; i++) {
                        obj[i].display();
                    }
                } else {
                    cout << "No students to display." << endl;
                }
                break;

            case 4:
                // Display top 3 students (toppers)
                if (n > 0) {
                    cout << "Toppers are:\n";
                    int topN = (n < 3) ? n : 3; // Handle cases with less than 3 students
                    for (int i = 0; i < topN; i++) {
                        obj[i].display();
                    }
                } else {
                    cout << "No students available to find toppers." << endl;
                }
                break;

            case 5:
                // Exit the program
                cout << "Exiting the program." << endl;
                break;

            default:
                // Invalid choice handling
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // Continue until the user chooses to exit

    return 0;
}
