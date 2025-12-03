#pragma once

#include <string>
#include <iostream>
using namespace std;

class Course {
private:
    string designation;
    string name;        
    float credits;           
    string grade;       

public:
    // Constructor
    Course(string designation, string name, float credits, string grade);

    // Accessors
    string getDesignation() const;
    float getCredits() const;
    string getGrade() const;
    
    // Core method for GPA calculation
    float getGradePoints() const; 

    // Mutator
    void setGrade(string newGrade);
};