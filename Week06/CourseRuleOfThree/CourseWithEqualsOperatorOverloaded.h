#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course
{
private:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;

public:
    //------------Rule of Three Memory Managers------------
    // Copy constructor
    Course(const Course&);
    // Destructor
    ~Course();
    // Assignment Operator
    Course& operator=(const Course& course);

    //------------Other------------------------------------
    Course(const string &courseName, int capacity);
    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name);
    string* getStudents() const;
    int getNumberOfStudents() const;

};

#endif
