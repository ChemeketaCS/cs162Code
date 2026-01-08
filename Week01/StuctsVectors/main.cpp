#include <iostream>
#include <vector>

using namespace std;

struct Student {
  string name;
  vector<double> exams;
};

int main() {
  Student student1 = {"Beth Jones", {84.2, 94.3, 96.7}};

  // Print the first exam score
  cout << student1.exams.at(0) << endl;
  // Print the number of exams
  cout << student1.exams.size() << endl;
  // Add a new score
  student1.exams.push_back(100.0);
}
