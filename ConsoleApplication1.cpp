#include "CourseManager.h"
#include <iostream>
using namespace std;

int main() {
    CourseManager manager;
    int choice;

    do {
        cout << "\n===== Student Course Management =====\n"
            << "1. Add Student\n"
            << "2. Remove Student\n"
            << "3. Search Student\n"
            << "4. Display All Students\n"
            << "5. Enroll Student in Course\n"
            << "6. Show Student Courses\n"
            << "7. Sort Students by GPA\n"
            << "8. Exit\n"
            << "Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear(); cin.ignore(1000, '\n');
            choice = 0; continue;
        }

        switch (choice) {
        case 1: manager.addStudent();         break;
        case 2: manager.removeStudent();      break;
        case 3: manager.searchStudent();      break;
        case 4: manager.displayAll();         break;
        case 5: manager.enrollInCourse();     break;
        case 6: manager.showStudentCourses(); break;
        case 7: manager.sortByGPA();          break;
        case 8: cout << "Goodbye!\n";         break;
        default: cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}