#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <string>

class Student : public Person {
private:
    int    id;
    double gpa;
    set<string> courses;

public:
    Student(int id, string name, double gpa);

    int getId()  const;
    double getGpa() const;

    bool enrollCourse(const string& course);
    void showCourses() const;
    void display() const;
};

#endif