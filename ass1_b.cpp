//Assignment 1-B
/*Consider a student database of SY COMP class (at least 15 records). 
Database contains different fields of every student like Roll No, Name and SGPA. 
 Arrange list of students alphabetically using shell sort  */
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1


#include<iostream>
#include<string>
using namespace std;

class Student {
    string name;   // Variable to store student's name
    int rollno;    // Variable to store student's roll number
    float sgpa;    // Variable to store student's SGPA (Semester Grade Point Average)

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

    // Friend function declaration for Shell Sort
    friend void shellSort(Student s[], int n);
};

// Function to perform Shell Sort on students, sorting by name alphabetically
void shellSort(Student s[], int n) {
    // Start with large gap, then reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for elements with the current gap
        for (int i = gap; i < n; i++) {
            Student key = s[i]; // Take the current student as the key
            int j = i - gap;

            // Compare names and shift elements until the correct position for the key is found
            while (j >= 0 && s[j].name > key.name) {
                s[j + gap] = s[j];
                j -= gap;
            }
            s[j + gap] = key; // Place the key in the correct position
        }
    }
}

int main() {
    Student obj[20]; // Array to store up to 20 students
    int n; // Variable to store the number of students
    int choice; // Variable to store menu choice

    do {
        // Display menu options
        cout << "\nMenu:" << endl;
        cout << "1. Enter student details" << endl;
        cout << "2. Sort students by name (alphabetically)" << endl;
        cout << "3. Display all students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Input student details
                cout << "Enter number of students: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    obj[i].read(i); // Reading each student's details
                }
                break;

            case 2:
                // Sort students by name using Shell Sort
                shellSort(obj, n);
                cout << "Students sorted by name alphabetically." << endl;
                break;

            case 3:
                // Display all student details
                for (int i = 0; i < n; i++) {
                    obj[i].display();
                }
                break;

            case 4:
                // Exit the program
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);  // Loop until the user chooses to exit

    return 0;
}
