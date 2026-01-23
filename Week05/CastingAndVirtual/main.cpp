#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
  string m_name;
  int m_age;

public:
  Person(string name, int age) {
    m_name = name;
    m_age = age;
  }

  string getName() const {
    return m_name;
  }

  virtual void introduce() const {
    cout << "Hi, my name is " << m_name << " and I am " << m_age
         << " years old." << endl;
  }
};

class Student: public Person {
private:
  string m_major;

public:
  Student(string name, int age, string major): Person(name, age) {
    m_major = major;
  }

  virtual void introduce() const {
    cout << "Hi, my name is " << m_name << " and I am " << m_age
         << " years old." << endl;
    cout << "My major is " << m_major << "." << endl;
  }
};

void makeIntroduction(const Person& person) {
  cout << "Let's meet: " << person.getName() << endl;
  person.introduce();
}

class Circle {};

int main() {
  Student s("Alex", 20, "Computer Science");

  // Point to a Person that happens to be a Student
  Person* somePersonPtr = &s;

  Student* someStudent = dynamic_cast<Student*>(somePersonPtr);

  //   cout << "---------------------------" << endl;
  //   p.introduce();
  cout << "---------------------------" << endl;
  s.introduce();
  cout << "---------------------------" << endl;
  makeIntroduction(s);
}
