#include "StudentTranscript.h"
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>z
#include <fstream>
#include <stdexcept> // Needed for getLastSemester error checking
StudentTranscript::StudentTranscript(string studentName) : studentName(studentName) {}
void StudentTranscript::addSemester(int termID) {
    semesters.emplace_back(termID); // Uses Semester constructor
}
float StudentTranscript::calculateCumulativeGPA() const {
    std::map<std::string, std::pair<float, float>> effectiveCourses;

    for (const auto& semester : semesters) {
        for (const auto& course : semester.getCourses()) {
            effectiveCourses[course.getDesignation()] =
                {course.getGradePoints(), course.getCredits()};
        }
    }

    float totalPoints = 0.0f;
    float totalCredits = 0.0f;

    for (const auto& pair : effectiveCourses) {
        float gradePoints = pair.second.first;
        float credits = pair.second.second;

        totalPoints += (gradePoints * credits);
        totalCredits += credits;
    }

    if (totalCredits == 0.0f) return 0.0f;
    return totalPoints / totalCredits;
}

void StudentTranscript::displaySummary() const {
    std::cout << "\n--- Student Transcript Summary: " << studentName << " ---" << std::endl;
    float cumulativeGPA = calculateCumulativeGPA();
    float totalCredits = 0.0f;

    for (const auto& semester : semesters) {
        std::cout << "Term " << semester.getTermID()
             << " | Credits: " << semester.getSemesterCredits()
             << " | Term GPA: " << semester.calculateSemesterGPA() << std::endl;
        totalCredits += semester.getSemesterCredits();
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Total Attempted Credits: " << totalCredits << std::endl;
    std::cout << "CUMULATIVE GPA (Effective Grade): " << cumulativeGPA << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

// ... (exportToCSV remains the same) ...

void StudentTranscript::importFromCSV(const string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        // ... logic to read and parse CSV data and create Course/Semester objects ...
        inFile.close();
        std::cout << "Data imported from " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file for reading." << std::endl;
    }
    // FIX: The definition for getLastSemester MUST NOT be here!
} // <--- importFromCSV ENDS HERE

// FIX 3: Define the new method as its own function outside of any other method
Semester& StudentTranscript::getLastSemester() {
    // Add the safety check (requires <stdexcept>)
    if (semesters.empty()) {
        throw std::out_of_range("Transcript has no semesters.");
    }
    return semesters.back();
}