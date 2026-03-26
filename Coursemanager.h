#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include "Student.h"
#include <map>

class CourseManager {
private:
    map<int, Student> students;

    int      readInt(const string& prompt);
    double   readDouble(const string& prompt);
    Student* findStudent(int id);

public:
    void addStudent();
    void removeStudent();
    void searchStudent();
    void displayAll();
    void enrollInCourse();
    void showStudentCourses();
    void sortByGPA();
};

#endif