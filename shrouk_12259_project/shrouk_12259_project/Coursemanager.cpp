#include "CourseManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CourseManager::readInt(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) { cin.ignore(1000, '\n'); return val; }
        cout << "Invalid input.\n";
        cin.clear(); cin.ignore(1000, '\n');
    }
}

double CourseManager::readDouble(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) { cin.ignore(1000, '\n'); return val; }
        cout << "Invalid input.\n";
        cin.clear(); cin.ignore(1000, '\n');
    }
}

Student* CourseManager::findStudent(int id) {
    auto it = students.find(id);
    if (it == students.end()) { cout << "Student not found.\n"; return nullptr; }
    return &it->second;
}

void CourseManager::addStudent() {
    int id = readInt("Enter Student ID: ");
    if (students.count(id)) { cout << "Error: ID already exists.\n"; return; }

    string name;
    cout << "Enter Name: ";
    getline(cin, name);

    double gpa = readDouble("Enter GPA (0.0 - 4.0): ");
    if (gpa < 0.0 || gpa > 4.0) { cout << "Error: GPA must be 0.0 to 4.0.\n"; return; }

    students.emplace(id, Student(id, name, gpa));
    cout << "Student added successfully.\n";
}

void CourseManager::removeStudent() {
    int id = readInt("Enter Student ID to remove: ");
    if (students.erase(id)) cout << "Student removed.\n";
    else cout << "Student not found.\n";
}

void CourseManager::searchStudent() {
    int id = readInt("Enter Student ID to search: ");
    Student* s = findStudent(id);
    if (s) s->display();
}

void CourseManager::displayAll() {
    if (students.empty()) { cout << "No students registered.\n"; return; }
    cout << "--- All Students ---\n";
    for (auto& pair : students) pair.second.display();
}

void CourseManager::enrollInCourse() {
    int id = readInt("Enter Student ID: ");
    Student* s = findStudent(id);
    if (!s) return;

    string course;
    cout << "Enter Course Name: ";
    getline(cin, course);

    if (s->enrollCourse(course)) cout << "Enrolled in \"" << course << "\" successfully.\n";
    else cout << "Already enrolled in \"" << course << "\".\n";
}

void CourseManager::showStudentCourses() {
    int id = readInt("Enter Student ID: ");
    Student* s = findStudent(id);
    if (!s) return;
    cout << "Courses for " << s->getName() << ":\n";
    s->showCourses();
}

void CourseManager::sortByGPA() {
    if (students.empty()) { cout << "No students to sort.\n"; return; }

    vector<Student> vec;
    for (auto& pair : students) vec.push_back(pair.second);

    sort(vec.begin(), vec.end(), [](const Student& a, const Student& b) {
        return a.getGpa() < b.getGpa();
        });

    cout << "--- Sorted by GPA (low to high) ---\n";
    for (auto& s : vec) s.display();
}