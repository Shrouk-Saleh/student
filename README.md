# Student Course Management System

A C++ console application for managing student records and course enrollments, developed as an individual project for the C++ Programming course.

## 📋 Overview

This system provides a menu-driven interface for academic administrators and course coordinators to efficiently manage student data and course enrollments. The application demonstrates practical application of Object-Oriented Programming (OOP) principles and the Standard Template Library (STL).

## ✨ Features

- **Add Student** - Register new students with unique ID, name, and GPA (0.0-4.0)
- **Remove Student** - Delete student records by ID
- **Search Student** - Look up and display specific student information
- **Display All Students** - List all registered students
- **Enroll Student in Course** - Assign courses with automatic duplicate prevention
- **Show Student Courses** - View all courses a student is enrolled in
- **Sort Students by GPA** - Display students sorted by GPA (ascending order)

## 🛠️ Technologies Used

- C++ (C++11 or later)
- Standard Template Library (STL):
  - `std::map` - Student storage with O(log n) lookup
  - `std::set` - Course storage with automatic duplicate prevention
  - `std::vector` - Temporary storage for sorting operations
- Object-Oriented Programming (inheritance, encapsulation)
