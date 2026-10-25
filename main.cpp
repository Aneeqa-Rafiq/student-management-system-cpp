#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const string FILE_NAME = "students.txt";

struct Student {
    int rollNo;
    string name;
    float marks;
};

void addStudent() {
    ofstream file(FILE_NAME, ios::app);
    if (!file) {
        cout << "Sorry, the student file could not be opened.\n";
        return;
    }

    Student student;

    cout << "Enter roll number: ";
    if (!(cin >> student.rollNo)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid roll number.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student name: ";
    getline(cin, student.name);

    cout << "Enter marks: ";
    if (!(cin >> student.marks)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter valid marks.\n";
        return;
    }

    file << student.rollNo << '\n'
         << student.name << '\n'
         << student.marks << '\n';

    cout << "Student record saved successfully.\n";
}

void viewStudents() {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No student records found. Add a student first.\n";
        return;
    }

    Student student;
    bool foundAny = false;

    cout << "\n--- Student Records ---\n";
    while (file >> student.rollNo) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!getline(file, student.name)) break;
        if (!(file >> student.marks)) break;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nRoll number: " << student.rollNo
             << "\nName: " << student.name
             << "\nMarks: " << student.marks << "\n";
        foundAny = true;
    }

    if (!foundAny) {
        cout << "No student records found.\n";
    }
}

void searchStudent() {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No student records found. Add a student first.\n";
        return;
    }

    int wantedRollNo;
    cout << "Enter roll number to search: ";
    if (!(cin >> wantedRollNo)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid roll number.\n";
        return;
    }

    Student student;
    bool found = false;

    while (file >> student.rollNo) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!getline(file, student.name)) break;
        if (!(file >> student.marks)) break;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (student.rollNo == wantedRollNo) {
            cout << "\nStudent found:"
                 << "\nRoll number: " << student.rollNo
                 << "\nName: " << student.name
                 << "\nMarks: " << student.marks << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No student found with that roll number.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n==============================\n"
             << "     STUDENT MANAGEMENT\n"
             << "==============================\n"
             << "1. Add student\n"
             << "2. View all students\n"
             << "3. Search student by roll number\n"
             << "0. Exit\n"
             << "Choose an option: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from the menu.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 0:
                cout << "Thanks for using Student Management!\n";
                break;
            default:
                cout << "That option is not on the menu. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
