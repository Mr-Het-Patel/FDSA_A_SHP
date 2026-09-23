#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    Song* prev;
    Song* next;
    
    Song(string t) {
        title = t;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Song* head;
    Song* tail;
    int count;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void addAtBeginning(string title) {
        Song* newSong = new Song(title);
        if (head == nullptr) {
            head = tail = newSong;
        } else {
            newSong->next = head;
            head->prev = newSong;
            head = newSong;
        }
        count++;
        cout << "Added to beginning: " << title << "\n";
        display();
    }

    void addAtEnd(string title) {
        Song* newSong = new Song(title);
        if (tail == nullptr) {
            head = tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        count++;
        cout << "Added to end: " << title << "\n";
        display();
    }

    void insertAfter(string targetTitle, string newTitle) {
        Song* current = head;
        while (current != nullptr && current->title != targetTitle) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Song '" << targetTitle << "' not found!\n";
            return;
        }

        if (current == tail) {
            addAtEnd(newTitle);
            return;
        }

        Song* newSong = new Song(newTitle);
        Song* nextSong = current->next;

        current->next = newSong;
        newSong->prev = current;
        newSong->next = nextSong;
        nextSong->prev = newSong;

        count++;
        cout << "Inserted " << newTitle << " after " << targetTitle << "\n";
        display();
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty! Nothing to remove.\n";
            return;
        }

        Song* songToRemove = head;
        cout << "Removed first song: " << songToRemove->title << "\n";

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete songToRemove;
        count--;
        display();
    }

    void display() {
        cout << "Total songs: " << count << " | Playlist: [";
        Song* current = head;
        while (current != nullptr) {
            cout << current->title;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << "]\n------------------------------------\n";
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addAtEnd("Song B");
    myPlaylist.addAtBeginning("Song A");
    myPlaylist.addAtEnd("Song D");
    myPlaylist.insertAfter("Song B", "Song C");
    myPlaylist.removeFirst();

    return 0;
}
