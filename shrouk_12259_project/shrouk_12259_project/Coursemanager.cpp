#include "CourseManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Student* CourseManager::findStudent(int id) {
    map<int, Student>::iterator it = students.find(id);

    if (it == students.end()) {
        cout << "Student not found.\n";
        return NULL;
    }

    return &(it->second);
}

void CourseManager::addStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    if (students.count(id)) {
        cout << "ID already exists!\n";
        return;
    }

    string name;
    cout << "Enter Name: ";
    getline(cin, name);

    double gpa;
    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4) {
        cout << "Invalid GPA!\n";
        return;
    }

    Student s(id, name, gpa);
    students.insert(pair<int, Student>(id, s));

    cout << "Student added!\n";
}

void CourseManager::displayAll() {
    if (students.empty()) {
        cout << "No students.\n";
        return;
    }

    map<int, Student>::iterator it;

    for (it = students.begin(); it != students.end(); it++) {
        it->second.display();
    }
}

void CourseManager::removeStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    if (students.erase(id))
        cout << "Deleted.\n";
    else
        cout << "Not found.\n";
}

void CourseManager::searchStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    Student* s = findStudent(id);
    if (s != NULL)
        s->display();
}

void CourseManager::enrollInCourse() {
    int id;
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    Student* s = findStudent(id);
    if (s == NULL) return;

    string course;
    cout << "Enter course: ";
    getline(cin, course);

    if (s->enrollCourse(course))
        cout << "Added!\n";
    else
        cout << "Already exists!\n";
}

void CourseManager::showStudentCourses() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    Student* s = findStudent(id);
    if (s != NULL)
        s->showCourses();
}

void CourseManager::sortByGPA() {
    vector<Student> list;

    map<int, Student>::iterator it;

    for (it = students.begin(); it != students.end(); it++) {
        list.push_back(it->second);
    }

    sort(list.begin(), list.end(),
        [](Student a, Student b) {
            return a.getGpa() < b.getGpa();
        });

    for (int i = 0; i < list.size(); i++) {
        list[i].display();
    }
}
