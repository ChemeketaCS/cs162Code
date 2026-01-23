#include <iostream>
#include <string>
using namespace std;

class Person {
public:
  string m_name;
  int m_age;

  void introduce() const {
    cout << "Hi, my name is " << m_name << " and I am " << m_age
         << " years old." << endl;
  }
};

class Student: public Person {
public:
  string m_major;

  void study() const {
    cout << m_name << " is busy studying " << m_major << "." << endl;
  }
};

int main() {
  Student s;
  s.m_name = "Alex";
  s.m_age = 20;
  s.m_major = "Computer Science";

  s.introduce(); // inherited from Person
  s.study();     // defined in Student
}
