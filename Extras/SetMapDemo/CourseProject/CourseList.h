#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

// Stores an array of Courses, responsible for their memory
class CourseList {
public:
  // Creates CourseList from text file
  CourseList();

  // Deep copy of an existing course list
  CourseList(const CourseList& other);

  // Assignment operator to do deep copy
  CourseList& operator=(const CourseList& other);

  ~CourseList(); // Destructor

  int getNumCourses() const;

  // Returns pointer to nth course in array
  Course* getCourseByIndex(int n) const;

  // Returns pointer to course with given name
  //  or nullptr if not found
  Course* getCourseByCRN(int crn) const;

private:
  Course* courses; // Pointer is to array of Course on the heap
  int numCourses;
};

#endif // COURSELIST_H
