#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <string>
using namespace std;

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int id, string name, double gpa);

    int getId();
    double getGpa();

    bool enrollCourse(string course);
    void showCourses();
    void display();
};

#endif
