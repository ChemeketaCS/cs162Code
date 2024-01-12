//-------------------------------------------
// People who use this
//-------------------------------------------

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  Person* spouse;
  string name;
  int age;

public:
  Person(string name, int age) {
    // this->age is member varaiable,
    //       age local param
    this->age = age;
    this->name = name;
    spouse = nullptr;
  }

  void print() const {
    cout << name << " who is " << age << endl;
    if (spouse != nullptr)
      cout << "      married to " << spouse->name << endl;
  }

  void marry(Person* other) {
    // I point to other
    spouse = other;
    // Tell other to point to me
    other->spouse = this;
  }
};

int main() {
  Person p1("Joe", 42);
  Person p2("Mary", 38);

  p1.marry(&p2);

  p1.print();
  p2.print();
}
