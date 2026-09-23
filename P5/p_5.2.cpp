#include <iostream>
#include <string>

using namespace std;

struct StudentNodeSingle {
    string studentName;
    StudentNodeSingle* nextStudent;
    
    StudentNodeSingle(string name) {
        studentName = name;
        nextStudent = nullptr;
    }
};

class SinglyCircularCircle {
private:
    StudentNodeSingle* firstStudent;
    int totalStudents;

public:
    SinglyCircularCircle() {
        firstStudent = nullptr;
        totalStudents = 0;
    }

    void joinCircle(string name) {
        StudentNodeSingle* newStudent = new StudentNodeSingle(name);
        
        if (firstStudent == nullptr) {
            firstStudent = newStudent;
            newStudent->nextStudent = firstStudent;
        } else {
            StudentNodeSingle* current = firstStudent;
            while (current->nextStudent != firstStudent) {
                current = current->nextStudent;
            }
            current->nextStudent = newStudent;
            newStudent->nextStudent = firstStudent;
        }
        
        totalStudents++;
        display();
    }

    void leaveCircle(string name) {
        if (firstStudent == nullptr) {
            return;
        }

        StudentNodeSingle* current = firstStudent;
        StudentNodeSingle* previous = nullptr;
        bool found = false;

        do {
            if (current->studentName == name) {
                found = true;
                break;
            }
            previous = current;
            current = current->nextStudent;
        } while (current != firstStudent);

        if (!found) {
            return;
        }

        if (totalStudents == 1) {
            firstStudent = nullptr;
        } else {
            if (current == firstStudent) {
                StudentNodeSingle* lastStudent = firstStudent;
                while (lastStudent->nextStudent != firstStudent) {
                    lastStudent = lastStudent->nextStudent;
                }
                firstStudent = firstStudent->nextStudent;
                lastStudent->nextStudent = firstStudent;
            } else {
                previous->nextStudent = current->nextStudent;
            }
        }

        delete current;
        totalStudents--;
        display();
    }

    void display() {
        if (firstStudent == nullptr) {
            cout << "Empty Circle" << endl;
            return;
        }
        
        StudentNodeSingle* current = firstStudent;
        do {
            cout << current->studentName << " ";
            current = current->nextStudent;
        } while (current != firstStudent);
        cout << endl;
    }
};

struct StudentNodeDouble {
    string studentName;
    StudentNodeDouble* prevStudent;
    StudentNodeDouble* nextStudent;
    
    StudentNodeDouble(string name) {
        studentName = name;
        prevStudent = nullptr;
        nextStudent = nullptr;
    }
};

class DoublyCircularCircle {
private:
    StudentNodeDouble* firstStudent;
    int totalStudents;

public:
    DoublyCircularCircle() {
        firstStudent = nullptr;
        totalStudents = 0;
    }

    void joinCircle(string name) {
        StudentNodeDouble* newStudent = new StudentNodeDouble(name);
        
        if (firstStudent == nullptr) {
            firstStudent = newStudent;
            newStudent->nextStudent = firstStudent;
            newStudent->prevStudent = firstStudent;
        } else {
            StudentNodeDouble* lastStudent = firstStudent->prevStudent;
            
            lastStudent->nextStudent = newStudent;
            newStudent->prevStudent = lastStudent;
            newStudent->nextStudent = firstStudent;
            firstStudent->prevStudent = newStudent;
        }
        
        totalStudents++;
        display();
    }

    void leaveCircle(string name) {
        if (firstStudent == nullptr) {
            return;
        }

        StudentNodeDouble* current = firstStudent;
        bool found = false;

        do {
            if (current->studentName == name) {
                found = true;
                break;
            }
            current = current->nextStudent;
        } while (current != firstStudent);

        if (!found) {
            return;
        }

        if (totalStudents == 1) {
            firstStudent = nullptr;
        } else {
            if (current == firstStudent) {
                firstStudent = firstStudent->nextStudent;
            }
            current->prevStudent->nextStudent = current->nextStudent;
            current->nextStudent->prevStudent = current->prevStudent;
        }

        delete current;
        totalStudents--;
        display();
    }

    void display() {
        if (firstStudent == nullptr) {
            cout << "Empty Circle" << endl;
            return;
        }
        
        StudentNodeDouble* current = firstStudent;
        do {
            cout << current->studentName << " ";
            current = current->nextStudent;
        } while (current != firstStudent);
        cout << endl;
    }
};

int main() {
    SinglyCircularCircle singleCircle;
    DoublyCircularCircle doubleCircle;

    singleCircle.joinCircle("Alice");
    singleCircle.joinCircle("Bob");
    singleCircle.joinCircle("Charlie");
    singleCircle.leaveCircle("Bob");

    doubleCircle.joinCircle("Alice");
    doubleCircle.joinCircle("Bob");
    doubleCircle.joinCircle("Charlie");
    doubleCircle.leaveCircle("Bob");

    return 0;
}
