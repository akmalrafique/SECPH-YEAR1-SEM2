#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    float marks;

public:
    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    void display() {
        cout << "ID: " << id 
             << " | Name: " << name 
             << " | Marks : " << marks << endl;
    }

    int getID() { return id; }
    float getMarks() { return marks; }

    void updateMarks(float m) {
        marks = m;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;
        float marks;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(id, name, marks));
        cout << "Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }

        for (auto &s : students) {
            s.display();
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (auto &s : students) {
            if (s.getID() == id) {
                cout << "Student found:\n";
                s.display();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void updateStudent() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;

        for (auto &s : students) {
            if (s.getID() == id) {
                float newMarks;
                cout << "Enter new marks: ";
                cin >> newMarks;
                s.updateMarks(newMarks);
                cout << "Updated successfully!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n===== Student Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.searchStudent();
                break;
            case 4:
                manager.updateStudent();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
