//Assignment 1-C
/*Consider a student database of SY COMP class (at least 15 records). 
Database contains different fields of every student like Roll No, Name and SGPA. 
 arrange list of students in ascending order of roll number using radix sort */
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1

#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name; // Name of the student
    int rollno;  // Roll number of the student
    float sgpa;  // SGPA of the student

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
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "SGPA: " << sgpa << endl;
    }

    // Friend functions for sorting
    friend void radixSort(Student s[], int n);
    friend void countSort(Student s[], int n, int exp);
    friend int maxElement(Student s[], int n);
};

// Function to perform radix sort
void radixSort(Student s[], int n)
{
    int max = maxElement(s, n); // Find the maximum roll number
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(s, n, exp); // Sort based on each digit
    }
}

// Function to perform counting sort based on a specific digit
void countSort(Student s[], int n, int exp)
{
    Student *output = new Student[n]; // Array to hold sorted students
    int count[10] = {0};              // Initialize count array

    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        int digit = (s[i].rollno / exp) % 10;
        count[digit]++;
    }

    // Change count[i] to contain the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (s[i].rollno / exp) % 10;
        output[count[digit] - 1] = s[i];
        count[digit]--;
    }

    // Copy the output array to s[], so that s[] contains sorted students
    for (int i = 0; i < n; i++)
    {
        s[i] = output[i];
    }

    delete[] output; // Free dynamically allocated memory
}

// Function to find the maximum roll number
int maxElement(Student s[], int n)
{
    int max = s[0].rollno;
    for (int i = 1; i < n; i++)
    {
        if (s[i].rollno > max)
        {
            max = s[i].rollno;
        }
    }
    return max;
}

int main()
{
    Student obj[20]; // Array to hold student objects
    int n = 0;       // Number of students
    int choice;      // User's menu choice

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Sort Students by Roll No\n";
        cout << "3. Display Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add student
        cout << "Enter number of students: ";
               cin >> n;
               for (int i = 0; i < n; i++) {
                   obj[i].read(i);
               }
               break;

        case 2: // Sort students
            if (n > 0)
            {
                radixSort(obj, n);
                cout << "Students sorted by roll number." << endl;
            }
            else
            {
                cout << "No students to sort." << endl;
            }
            break;

        case 3: // Display students
            if (n > 0)
            {
                cout << "\nStudent Details:\n";
                for (int i = 0; i < n; i++)
                {
                    obj[i].display();
                }
            }
            else
            {
                cout << "No students to display." << endl;
            }
            break;

        case 4: // Exit
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); // Continue until user chooses to exit
    return 0;
}