#include "Course.h"
#include <stdexcept>
using namespace std;

Course::Course(string designation, string name, float credits, string grade)
    : designation(designation), name(name), credits(credits), grade(grade) {}

float Course::getGradePoints() const {

    if (grade == "A" || grade == "a") return 4.0f;
    if (grade == "A-" || grade == "a-") return 3.7f;
    if (grade == "B+" || grade == "b+") return 3.3f;
    if (grade == "B" || grade == "b") return 3.0f;
    if (grade == "B-" || grade == "b-") return 2.7f;
    if (grade == "C+" || grade == "c+") return 2.3f;
    if (grade == "C" || grade == "c") return 2.0f;
    if (grade == "C-" || grade == "c-") return 1.7f;
    if (grade == "D+" || grade == "d+") return 1.3f;
    if (grade == "D" || grade == "d") return 1.0f;
    if (grade == "F" || grade == "f") return 0.0f;

    return 0.0f;
}

string Course::getDesignation() const { return designation; }
float Course::getCredits() const { return credits; }
string Course::getGrade() const { return grade; }
void Course::setGrade(string newGrade) { grade = newGrade; }