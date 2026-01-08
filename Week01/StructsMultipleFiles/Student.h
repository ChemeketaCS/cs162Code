#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

/**
 * @brief Represents a student with a name and a list of exam scores.
 *
 */
struct Student {
  std::string name;
  std::vector<double> exams;
};

/**
 * @brief Prints the information of a student.
 *
 * @param student The student whose information is to be printed.
 */
void printStudentInfo(const Student& student);

#endif