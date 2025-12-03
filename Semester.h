#pragma once
#include <vector>
#include <string>
#include "Course.h"
#include <iostream>

using namespace std;

class Semester {
private:
    int termID;
    vector<Course> courses;

public:
    Semester(int termID);

    void addCourse(const Course& course);
    bool deleteCourse(const string& designation);

    int getTermID() const;
    const vector<Course>& getCourses() const;
    float calculateSemesterGPA() const;
    float getSemesterCredits() const;
    void displaySemester() const;
    void sortCourses(const string& sortBy);
};