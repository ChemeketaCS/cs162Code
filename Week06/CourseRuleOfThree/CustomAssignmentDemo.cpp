#include <iostream>
#include "CourseWithEqualsOperatorOverloaded.h" 
using namespace std;

int main()
{
    Course course1("CS162", 5);
    course1.addStudent("Peter Pan");    // Add a student to course1

    //Call copy constructor
    Course course2(course1);

    //Call copy constructor implicitly
    Course course3 = course1;

    //Use assignment operator
    Course course4("CS161", 3);
    course4 = course1;



    course4.addStudent("Lisa Ma");      // Add a student to course2
    course4.addStudent("John Doe");     // Add a student to course2

    cout << "students in course1: " << endl;
    for(int i = 0; i < course1.getNumberOfStudents(); i++) {
        cout << course1.getStudents()[i] << endl;
    }

    cout << "students in course2: " << endl;
    for(int i = 0; i < course4.getNumberOfStudents(); i++) {
        cout << course4.getStudents()[i] << endl;
    }


    cout << "Testing that self assignment does not break object" << endl;
    course1 = course1;

    cout << "students in course1: " << endl;
    for(int i = 0; i < course1.getNumberOfStudents(); i++) {
        cout << course1.getStudents()[i] << endl;
    }

    return 0;
}
