//Assignment 3
/* Consider the playlist in a music player. Implement a playlist feature in music player application using singly linked list.
Each song in the playlist is represented as a node in the linked list. Each node contains information about the song (such as title or artist or duration, etc.).
The playlist should allow users to: a. Add songs b. Remove songs c. Display the entire playlist d. Play specific songs. */
// Name: Parikshit Rajpurohit
// PRN: 123B1B238
// Batch: D1


#include <iostream>
using namespace std;

// Song class represents an individual song in the playlist
class Song
{
private:
    string title;   // Stores the song title
    string artist;  // Stores the artist name
    float duration; // Stores the song duration in minutes

public:
    Song *next; // Pointer to the next song in the playlist

    // Default constructor initializes next pointer to null
    Song() { next = nullptr; }

    // Parameterized constructor to initialize song attributes
    Song(string t = "", string a = "", float d = 0.0)
    {
        next = nullptr;
        title = t;
        artist = a;
        duration = d;
    }

    // Function to get the title of the song
    string getTitle()
    {
        return this->title;
    }

    // Function to display the details of the song when it is played
    void play()
    {
        cout << "Now playing: " << title << " by " << artist << " [Duration: " << duration << " minutes]" << endl;
    }
};

// Playlist class represents a collection of songs
class playlist
{
public:
    Song *head = nullptr; // Pointer to the first song in the playlist

    // Function to add a song to the end of the playlist
    void addSongAtLast(string t, string a, float d)
    {
        Song *nn = new Song(t, a, d); // Create a new song node
        if (head == nullptr) // If the playlist is empty
        {
            head = nn; // Make the new song the head
        }
        else
        {
           Song *p = head;
           while(p->next){
            p=p->next;
           }
           p->next = nn;
        }
        cout << "Song added at last successfully" << endl;
    }

    // Function to add a song at the beginning of the playlist
    void addSongAtBegining(string t, string a, float d)
    {
        Song *nn = new Song(t, a, d); // Create a new song node
        nn->next = head; // Make the new song point to the current head
        head = nn; // Update the head to the new song
        cout << "Song added at beginning successfully" << endl;
    }

    // Function to remove a song from the playlist by title
    void removeSong(string s)
    {
        if (head == nullptr) // Check if the playlist is empty
        {
            cout << "The playlist is empty!!" << endl;
            return;
        }
        // Check if the song to be removed is the head
        if (head->getTitle() == s)
        {
            Song *temp = head; // Store the current head
            head = head->next; // Move the head to the next song
            delete temp; // Delete the old head
            cout << "Song '" << s << "' removed from the playlist." << endl;
            return;
        }

        Song *prev = head;       // Keep track of the previous song
        Song *current = head->next; // Current song starts from the second song
        // Traverse the list to find the song to be removed
        while (current != nullptr && current->getTitle() != s)
        {
            prev = current;
            current = current->next;
        }
        // If the song is not found
        if (current == nullptr)
        {
            cout << "Song '" << s << "' not found in the playlist." << endl;
        }
        else // If the song is found
        {
            prev->next = current->next; // Remove the song from the list
            delete current; // Delete the song node
            cout << "Song '" << s << "' removed from the playlist." << endl;
        }
    }

    // Function to display the titles of all songs in the playlist
    void displayPlaylist()
    {
        if (head == nullptr) // Check if the playlist is empty
        {
            cout << "The playlist is empty!" << endl;
            return;
        }
        Song *p = head; // Start from the head of the playlist
        while (p != nullptr)
        {
            cout << "Title: " << p->getTitle() << endl; // Print the song title
            p = p->next; // Move to the next song
        }
    }

    // Function to play a song by its title
    void playSong(string s)
    {
        if (head == nullptr) // Check if the playlist is empty
        {
            cout << "The playlist is empty!" << endl;
            return;
        }
        Song *p = head; // Start from the head of the playlist
        // Traverse the list to find the song to be played
        while (p != nullptr)
        {
            if (p->getTitle() == s) // If the song is found
            {
                p->play(); // Play the song
                return;
            }
            p = p->next;
        }
        cout << "Song '" << s << "' not found in the playlist." << endl;
    }
};

int main()
{
    playlist playlist; // Create a playlist object
    int choice;
    do
    {
        // Display the menu to the user
        cout << "\nPlaylist Menu:\n";
        cout << "1. Add Song at last\n";
        cout << "2. Add song at beginning\n";
        cout << "3. Play particular Song\n";
        cout << "4. Remove Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get the user's choice
        cin.ignore(); // Ignore any newline characters in the input

        string title, artist;
        float duration;

        switch (choice)
        {
        case 1: // Add a song at the end of the playlist
            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            cout << "Enter song duration (in minutes): ";
            cin >> duration;
            playlist.addSongAtLast(title, artist, duration);
            break;
        case 2: // Add a song at the beginning of the playlist
            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            cout << "Enter song duration (in minutes): ";
            cin >> duration;
            playlist.addSongAtBegining(title, artist, duration);
            break;
        case 3: // Play a specific song by title
            cout << "Enter song title to play: ";
            getline(cin, title);
            playlist.playSong(title);
            break;
        case 4: // Remove a specific song by title
            cout << "Enter song title to remove: ";
            getline(cin, title);
            playlist.removeSong(title);
            break;
        case 5: // Display the playlist
            playlist.displayPlaylist();
            break;
        case 6: // Exit the menu
            cout << "Exiting the playlist menu. Goodbye!" << endl;
            break;
        default: // Invalid choice
            cout << "Invalid choice! Please choose a valid option." << endl;
        }
    } while (choice != 6); // Keep showing the menu until the user chooses to exit
    return 0;
}
