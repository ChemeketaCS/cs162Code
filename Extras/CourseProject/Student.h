#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <string>

using namespace std;

class Student {
public:
  Student(string name, int numberOfCourses);

  // copy constructor
  Student(const Student& other);

  // assignment operator
  Student& operator=(const Student& other);

  // destructor
  ~Student();

  string getName() const;
  void setName(string val);

  void addClass(Course* theCourse);

  string getInfo() const;

private:
  string name;

  // Stores a dynamic array contianing
  //   pointers to the Courses this Student is taking
  //   We own the memory for dynamic array,
  //   but not the Course*s it contains
  Course** courses;

  int numCourses;      // how many courses this student is taking
  int nextCourseIndex; // what slot next course goes in
};

#endif // STUDENT_H
