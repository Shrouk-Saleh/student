#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(int id, string name, double gpa)
    : Person(name), id(id), gpa(gpa) {
}

int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

bool Student::enrollCourse(const string& course) {
    return courses.insert(course).second;
}

void Student::showCourses() const {
    if (courses.empty()) {
        cout << "  No courses enrolled.\n";
        return;
    }
    for (const string& c : courses)
        cout << "  - " << c << "\n";
}

void Student::display() const {
    cout << "ID: " << id
        << "  Name: " << name
        << "  GPA: " << fixed << setprecision(1) << gpa << "\n";
}