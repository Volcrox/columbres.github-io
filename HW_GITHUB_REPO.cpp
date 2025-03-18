#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    double gpa;
};

vector<Student> students;  // Dynamic student list

void addStudent();
void editStudent();
void deleteStudent();
void viewStudents();
void displayMenu();
int findStudentById(int id);

int main() {
    int choice;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {  // Input validation
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        cin.ignore();  // Clear newline after number input

        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: viewStudents(); break;
            case 5: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid option! Please try again.\n"; break;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\n====== Student Management System ======\n";
    cout << "[1] Add Student\n";
    cout << "[2] Edit Student\n";
    cout << "[3] Delete Student\n";
    cout << "[4] View Students\n";
    cout << "[5] Exit Program\n";
    cout << "=======================================\n";
}

void addStudent() {
    Student s;

    cout << "Enter Student ID: ";
    while (!(cin >> s.id)) {  // Validate integer input
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID! Enter a valid number: ";
    }
    cin.ignore();

    if (findStudentById(s.id) != -1) {
        cout << "Error: Student ID already exists!\n";
        return;
    }

    cout << "Enter First Name: ";
    getline(cin, s.firstName);
    cout << "Enter Last Name: ";
    getline(cin, s.lastName);
    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter GPA: ";
    while (!(cin >> s.gpa)) {  // Validate GPA input
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid GPA! Enter a valid number: ";
    }
    cin.ignore();

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void editStudent() {
    if (students.empty()) {
        cout << "No student records available!\n";
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
    while (!(cin >> students[index].gpa)) {  // Validate GPA input
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid GPA! Enter a valid number: ";
    }
    cin.ignore();

    cout << "Student data updated!\n";
}

void deleteStudent() {
    if (students.empty()) {
        cout << "No student records available!\n";
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

    students.erase(students.begin() + index);
    cout << "Student deleted successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No student records available!\n";
        return;
    }

    cout << "\n======================================== Student Records =======================================\n";
    cout << left << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name" 
         << setw(15) << "Course" << setw(6) << "GPA" << "\n";
    cout << string(70, '-') << "\n";

    for (const auto& s : students) {
        cout << left << setw(10) << s.id
             << setw(15) << s.firstName
             << setw(15) << s.lastName
             << setw(15) << s.course
             << setw(6) << fixed << setprecision(2) << s.gpa << "\n";
    }
}

int findStudentById(int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}
