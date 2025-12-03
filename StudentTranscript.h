#pragma once

#include <string>
#include <vector>
#include "Semester.h"

using namespace std;

class StudentTranscript {
private:
    string studentName;
    vector<Semester> semesters; // Kept private for Encapsulation

public:
    StudentTranscript(string studentName);
    void addSemester(int termID);
    bool deleteSemester(int termID);
    Semester& getLastSemester();
    float calculateCumulativeGPA() const;
    void displaySummary() const;
    void exportToCSV(const string& filename) const;
    void importFromCSV(const string& filename); 
};