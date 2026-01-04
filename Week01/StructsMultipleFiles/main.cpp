#include <iostream>
#include "Student.h"

using namespace std;

int main() {
  Student student1 = {"Beth Jones", {84.2, 94.3, 96.7}};
  printStudentInfo(student1);
}
