#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    double gpa;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void editStudent();
void deleteStudent();
void viewStudents();
void displayMenu();
int findStudentById(int id);

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: viewStudents(); break;
            case 5: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid option! Please try again.\n"; break;
        }
    } while (true);
    return 0;
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "[1] Add Student\n";
    cout << "[2] Edit Student\n";
    cout << "[3] Delete Student\n";
    cout << "[4] View Students\n";
    cout << "[5] Exit Program\n";
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student record is full!\n";
        return;
    }

    int id;
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    if (findStudentById(id) != -1) {
        cout << "Duplicate ID!\n";
        return;
    }

    students[studentCount].id = id;
    cout << "Enter First Name: ";
    getline(cin, students[studentCount].firstName);
    cout << "Enter Last Name: ";
    getline(cin, students[studentCount].lastName);
    cout << "Enter Course: ";
    getline(cin, students[studentCount].course);
    cout << "Enter GPA: ";
    cin >> students[studentCount].gpa;
    cin.ignore();

    studentCount++;
    cout << "Student added successfully!\n";
}

void editStudent() {
    if (studentCount == 0) {
        cout << "No records available!\n";
        return;
    }

    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;
    cin.ignore();

    int index = findStudentById(id);
    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter New First Name: ";
    getline(cin, students[index].firstName);
    cout << "Enter New Last Name: ";
    getline(cin, students[index].lastName);
    cout << "Enter New Course: ";
    getline(cin, students[index].course);
    cout << "Enter New GPA: ";
    cin >> students[index].gpa;
    cin.ignore();

    cout << "Student data updated!\n";
}

void deleteStudent() {
    if (studentCount == 0) {
        cout << "No records available!\n";
        return;
    }

    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    cin.ignore();

    int index = findStudentById(id);
    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    cout << "Student deleted successfully!\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No records to display!\n";
        return;
    }

    cout << "\nStudent Records:\n";
    cout << left << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "Course" << setw(6) << "GPA" << "\n";
    cout << string(60, '-') << "\n";
    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(10) << students[i].id
             << setw(15) << students[i].firstName
             << setw(15) << students[i].lastName
             << setw(15) << students[i].course
             << setw(6) << fixed << setprecision(2) << students[i].gpa << "\n";
    }
}

int findStudentById(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}
