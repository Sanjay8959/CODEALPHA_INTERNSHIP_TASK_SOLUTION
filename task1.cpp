#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double grade;
    int creditHours;
};

int main() {
    int numCourses;
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;
    
    cout << "===== CGPA Calculator =====" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    vector<Course> courses(numCourses);
    
    // Input for each course
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << (i + 1) << ":" << endl;
        
        cout << "Enter course name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, courses[i].name);
        
        cout << "Enter grade (e.g., 4.0, 3.7, 3.3, etc.): ";
        cin >> courses[i].grade;
        
        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;
        
        // Calculate grade points for this course
        double courseGradePoints = courses[i].grade * courses[i].creditHours;
        totalGradePoints += courseGradePoints;
        totalCreditHours += courses[i].creditHours;
    }
    
    // Calculate CGPA
    double cgpa = 0.0;
    if (totalCreditHours > 0) {
        cgpa = totalGradePoints / totalCreditHours;
    }
    
    // Display results
    cout << "\n===== Results =====" << endl;
    cout << "Course Details:" << endl;
    cout << left << setw(20) << "Course Name" << setw(10) << "Grade" << setw(15) << "Credit Hours" << setw(15) << "Grade Points" << endl;
    cout << string(60, '-') << endl;
    
    for (const auto& course : courses) {
        cout << left << setw(20) << course.name 
             << setw(10) << course.grade 
             << setw(15) << course.creditHours 
             << setw(15) << (course.grade * course.creditHours) << endl;
    }
    
    cout << string(60, '-') << endl;
    cout << "Total Credit Hours: " << totalCreditHours << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;
    
    return 0;
}