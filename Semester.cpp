#include "Semester.h"
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// VITAL: Constructor
Semester::Semester(int termID) : termID(termID) {}

// Course Management Methods
void Semester::addCourse(const Course& course) {
    courses.push_back(course);
}

// VITAL: deleteCourse must be fully implemented
bool Semester::deleteCourse(const string& designation) {
    auto it = remove_if(courses.begin(), courses.end(),
        [&](const Course& c){ return c.getDesignation() == designation; });

    bool deleted = (it != courses.end());
    courses.erase(it, courses.end());
    return deleted;
}

// Calculation Methods
float Semester::calculateSemesterGPA() const {
    float totalPoints = 0.0f;
    float totalCredits = 0.0f;

    for (const auto& course : courses) {
        // Requires Course::getGradePoints() to be implemented in Course.cpp
        totalPoints += (course.getGradePoints() * course.getCredits());
        totalCredits += course.getCredits();
    }

    if (totalCredits == 0.0f) return 0.0f;
    return totalPoints / totalCredits;
}

float Semester::getSemesterCredits() const {
    float totalCredits = 0.0f;
    for (const auto& course : courses) {
        totalCredits += course.getCredits();
    }
    return totalCredits;
}

// Sorting and Display Methods
void Semester::sortCourses(const string& sortBy) {
    if (sortBy == "number") {
        sort(courses.begin(), courses.end(),
            [](const Course& a, const Course& b) {
                return a.getDesignation() < b.getDesignation();
            });
    } else if (sortBy == "grade") {
        sort(courses.begin(), courses.end(),
            [](const Course& a, const Course& b) {
                return a.getGradePoints() > b.getGradePoints();
            });
    }
}

void Semester::displaySemester() const {
    cout << "Semester: " << termID << endl;
    cout << "  GPA: " << calculateSemesterGPA() << endl;
    for (const auto& course : courses) {
        cout << "  - " << course.getDesignation() << " (" << course.getCredits()
             << " credits): " << course.getGrade() << endl;
    }
}

// Accessors
int Semester::getTermID() const { return termID; }
const vector<Course>& Semester::getCourses() const { return courses; }