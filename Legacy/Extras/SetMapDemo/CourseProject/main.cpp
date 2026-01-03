#include <iostream>

#include "Course.h"
#include "CourseList.h"
#include "Student.h"

using namespace std;

int main() {
  CourseList masterCourseList; // Contains all our courses

  // Make a copy
  CourseList masterCourseList2(masterCourseList);
  // Change one of the items in the copy - this should NOT change the
  //   course in masterCourseList
  Course* temp = masterCourseList2.getCourseByIndex(0);
  temp->setRoom("Online");

  // Print courses
  for (int i = 0; i < masterCourseList.getNumCourses(); i++) {
    Course* currentCourse = masterCourseList.getCourseByIndex(i);
    cout << currentCourse->getInfo() << endl;
  }

  cout << "----------------------------" << endl;

  Student s1("Joe", 2);
  Course* classToAdd = masterCourseList.getCourseByCRN(24336);
  s1.addClass(classToAdd);
  s1.addClass(masterCourseList.getCourseByCRN(43454));

  cout << s1.getInfo();

  Student s2("Sue", 3);
  s2.addClass(masterCourseList.getCourseByCRN(43444));
  s2.addClass(masterCourseList.getCourseByCRN(43687));
  s2.addClass(masterCourseList.getCourseByCRN(43454));

  cout << s2.getInfo();

  cout << "\nSwitching room for COM101..." << endl;
  Course* com101 = masterCourseList.getCourseByCRN(43454);
  com101->setRoom("6-666");

  cout << s1.getInfo();
  cout << s2.getInfo();

  return 0;
}
