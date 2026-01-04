#include <iostream>
#include "Student.h"

using namespace std;

void printStudentInfo(const Student& student) {
  cout << "Student Name: " << student.name << endl;
  cout << "Exam Scores: ";
  for (double score : student.exams) {
    cout << score << " ";
  }
  cout << endl;
}