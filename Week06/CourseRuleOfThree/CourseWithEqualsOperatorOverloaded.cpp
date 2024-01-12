#include "CourseWithEqualsOperatorOverloaded.h"
#include <iostream>
using namespace std;

Course::Course(const string& theCourseName, int theCapacity) {
  numberOfStudents = 0;
  this->courseName = theCourseName;
  this->capacity = theCapacity;
  students = new string[theCapacity];
}

Course::~Course() {
  delete[] students;
}

string Course::getCourseName() const {
  return courseName;
}

void Course::addStudent(const string& name) {
  if (numberOfStudents >= capacity) {
    cout << "The maximum size of array exceeded" << endl;
    cout << "Program terminates now" << endl;
    exit(0);
  }

  students[numberOfStudents] = name;
  numberOfStudents++;
}

void Course::dropStudent(const string& name) {
  // Left as an exercise
}

string* Course::getStudents() const {
  return students;
}

int Course::getNumberOfStudents() const {
  return numberOfStudents;
}

//// BAD Default Copy Constructor
// Course::Course(const Course& course)
//{
//     courseName = course.courseName;
//     numberOfStudents = course.numberOfStudents;
//     capacity = course.capacity;
//     students = course.students;
// }

// Copy constructor
Course::Course(const Course& course) {
  cout << "Using copy constructor..." << endl;
  // copy basic info
  courseName = course.courseName;
  numberOfStudents = course.numberOfStudents;
  capacity = course.capacity;

  // allocate new array and copy data
  students = new string[capacity];
  for (int i = 0; i < numberOfStudents; i++)
    students[i] = course.students[i];
}

Course& Course::operator=(const Course& otherCourse) {
  cout << "Using assignment operator..." << endl;
  if (this != &otherCourse) // Do nothing with self-assignment
  {
    // copy basic info from other
    courseName = otherCourse.courseName;
    numberOfStudents = otherCourse.numberOfStudents;
    capacity = otherCourse.capacity;

    delete[] students; // Delete our old array

    // Create a new array with the same capacity as course
    //   and copy data
    students = new string[capacity];
    for (int i = 0; i < numberOfStudents; i++)
      students[i] = otherCourse.students[i];
  }

  // return this object by reference for chained assignment
  return *this;
}
