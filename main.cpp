#include "StudentTranscript.h"
#include <limits>
#include "Course.h"
#include "Semester.h"
#include <iostream>
#include <fstream>
void runTestScenario() {

    StudentTranscript transcript("Avery Johnson");
    transcript.addSemester(202440);
    Semester& fall2024 = transcript.getLastSemester();
    fall2024.addCourse({"CSC 101", "Intro Programming", 3.0f, "A"});
    fall2024.addCourse({"ENG 101", "English Comp", 3.0f, "B+"});
    fall2024.addCourse({"MAT 110", "Calculus I", 4.0f, "D"});
    transcript.addSemester(202520);
    Semester& spring2025 = transcript.getLastSemester();

    spring2025.addCourse({"CSC 201", "Data Structures", 3.0f, "A-"});
    spring2025.addCourse({"MAT 110", "Calculus I", 4.0f, "B"});
    transcript.displaySummary();

    cout << "\n--- Viewing Spring 2025 Courses Sorted by Grade ---" << endl;
    spring2025.sortCourses("grade");
    spring2025.displaySemester();

}

int main() {
    runTestScenario();
    return 0;
}