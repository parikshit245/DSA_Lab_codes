// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1
// Title:   Implement a job scheduling system for a manufacturing plant using a double-ended queue. 
//          The system needs to efficiently manage the processing of jobs on various machines throughout the plant. Each job has a Job_priority. 
//          The system should support the following operations: 
//            a. Add Job b. Remove Job c. Display Job d. Search Job.



#include <iostream>
using namespace std;

// Job class to store job details such as name, time, and priority
class Job {
    string jobname; // Name of the job
    int time;       // Time required for the job
    int priority;   // Priority level of the job

public:
    Job *next, *prev; // Pointers for doubly linked list

    // Constructor to initialize pointers to null
    Job() {
        next = prev = nullptr;
    }

    // Method to get job details from the user
    void getdata() {
        cout << "Enter Job name: ";
        cin.ignore();
        getline(cin, jobname);
        cout << "Enter Time: ";
        cin >> time;
        cout << "Enter Priority: ";
        cin >> priority;
    }

    // Method to display job details
    void displaydata() {
        cout << "Job name: " << jobname << ", Time: " << time << ", Priority: " << priority << endl;
    }

    // Method to get the priority of the job
    int getPriority() {
        return priority;
    }
};

// dequeJob class that manages a doubly-ended queue of jobs based on priority
class dequeJob {
    Job *f, *r; // Front and rear pointers for the deque

public:
    // Constructor to initialize front and rear pointers to null
    dequeJob() {
        f = r = nullptr;
    }

    // Insert a new job in the deque according to its priority
    void insertByPriority() {
        Job *nn = new Job; // Create a new job node
        nn->getdata();     // Read job details

        // If deque is empty, make the new job both front and rear
        if (f == nullptr) { 
            f = r = nn;
        } else {
            // If priority is high enough, insert job at the front
            if (nn->getPriority() >= f->getPriority()) {
                nn->next = f;
                f->prev = nn;
                f = nn;
            } 
            // If priority is low, insert job at the rear
            else if (nn->getPriority() <= r->getPriority()) {
                r->next = nn;
                nn->prev = r;
                r = nn;
            } 
            // If job priority doesn't meet insertion criteria, don't add it
            else {
                cout << "Job not added due to priority constraints." << endl;
                delete nn; // Clean up memory for unused job
            }
        }
    }

    // Delete a job from the front of the deque
    void deletefront() {
        if (f == nullptr) return; // Check if deque is empty
        Job *temp = f;            // Store current front for deletion
        f = f->next;               // Move front to the next node
        if (f != nullptr) {
            f->prev = nullptr;     // Set previous of new front to null
        } else {
            r = nullptr;           // If deque becomes empty, set rear to null
        }
        delete temp;               // Delete the old front job
    }

    // Delete a job from the back of the deque
    void deleteback() {
        if (r == nullptr) return; // Check if deque is empty
        Job *temp = r;            // Store current rear for deletion
        r = r->prev;              // Move rear to the previous node
        if (r != nullptr) {
            r->next = nullptr;    // Set next of new rear to null
        } else {
            f = nullptr;          // If deque becomes empty, set front to null
        }
        delete temp;              // Delete the old rear job
    }

    // Display all jobs in the deque from front to rear
    void display() {
        if (f == nullptr) { // Check if deque is empty
            cout << "No jobs to display." << endl;
            return;
        }
        Job *cn = f; // Start from front
        while (cn != nullptr) { // Traverse until the end of the deque
            cn->displaydata();
            cn = cn->next;
        }
    }
};

// Main function to present a menu-driven interface to the user
int main() {
    dequeJob obj; // Create an instance of dequeJob
    int choice;   // Store user's menu choice

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Job by Priority (Front or Rear)" << endl;
        cout << "2. Delete Job from Front" << endl;
        cout << "3. Delete Job from Back" << endl;
        cout << "4. Display Jobs" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user's choice
        switch (choice) {
            case 1:
                obj.insertByPriority();  // Insert a new job by priority
                break;
            case 2:
                obj.deletefront();       // Delete a job from the front
                break;
            case 3:
                obj.deleteback();        // Delete a job from the back
                break;
            case 4:
                obj.display();           // Display all jobs
                break;
            case 5:
                cout << "Exiting program." << endl; // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again." << endl; // Invalid input handler
        }
    } while (choice != 5); // Loop until user selects exit option

    return 0;
}
