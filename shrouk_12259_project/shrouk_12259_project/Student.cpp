#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(int id, string name, double gpa)
    : Person(name) {
    this->id = id;
    this->gpa = gpa;
}

int Student::getId() {
    return id;
}

double Student::getGpa() {
    return gpa;
}

bool Student::enrollCourse(string course) {
    if (courses.count(course) == 0) {
        courses.insert(course);
        return true;
    }
    return false;
}

void Student::showCourses() {
    if (courses.empty()) {
        cout << "No courses.\n";
        return;
    }

    for (string c : courses) {
        cout << "- " << c << endl;
    }
}

void Student::display() {
    cout << "ID: " << id
         << " Name: " << name
         << " GPA: " << fixed << setprecision(1) << gpa << endl;
}
