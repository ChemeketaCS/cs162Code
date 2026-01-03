#include <iostream>

#include <memory>

using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person(string n, int a): name(n), age(a) {
  }
  ~Person() {
    // Let us know a person was destroyed
    cout << "  --" << name << " was destroyed" << endl;
  }
  void print() {
    cout << name << " who is " << age << endl;
  }
  void setName(string n) {
    name = n;
  }
};

// Simple class that can reference other Foo's with a shared_ptr
class Foo {
public:
  string name;
  shared_ptr<Foo> partner;
  Foo(string n): name(n) {
  }
  ~Foo() {
    cout << "  --" << name << " was destroyed" << endl;
  }
};

// Simple class that can reference other Bar's with a weak_ptr
class Bar {
public:
  string name;
  weak_ptr<Bar> partner;
  Bar(string n): name(n) {
  }
  ~Bar() {
    cout << "  --" << name << " was destroyed" << endl;
  }
};

/// Demonstrates how shared pointers automatically delete what they point
///   to when it is no longer accessible
shared_ptr<Person> sharedPointerOne() {
  // Make person on heap and reference with smart pointer
  shared_ptr<Person> sp1(new Person("Bob", 25));

  // Use like a normal pointer * / -> to access what it points to
  sp1->print();

  cout << "  Reference count = " << sp1.use_count() << endl;

  if (true) {
    cout << "Copying pointer, changing name of copy..." << endl;
    shared_ptr<Person> sp2 = sp1;
    sp2->setName("Bobby");

    cout << "  Reference count = " << sp1.use_count() << endl;
    sp1->print();
  }

  cout << "Out of block where sp2 was..." << endl;
  cout << "  Reference count = " << sp1.use_count() << endl;
  sp1->print();

  cout << "Returning the shared pointer... won't get deleted until end of main"
       << endl;
  return sp1;
}

/// Demonstrates a cycle of shared_ptrs will not get freed
void sharedPointerTwo() {
  // Make a cycle of shared ptrs
  shared_ptr<Foo> fooA(new Foo("fooA"));
  shared_ptr<Foo> fooB(new Foo("fooB"));
  fooA->partner = fooB;
  fooB->partner = fooA;

  ////Can follow shared pointer to partner's name
  // cout << fooA->partner->name << endl;

  // But have a leak as we leave function!
}

/// Demonstrates a cycle of weak_ptrs will get freed
void weakPointerOne() {
  // Make a cycle of weak ptrs
  shared_ptr<Bar> barA(new Bar("barA"));
  shared_ptr<Bar> barB(new Bar("barB"));
  barA->partner = barB;
  barB->partner = barA;

  ////Can't follow weak pointer to partner's name
  ////Have to TRY to get a shared pointer using lock() function
  // shared_ptr<Bar> AsPartner = barA->partner.lock();
  ////May not work if we lost all shared pointers to it...
  // if(AsPartner != nullptr)
  //     cout << AsPartner->name << endl;

  // But no leak when we leave...
}

int main() {
  //-------------------------------
  cout << "Demonstrating shared pointers used with people objects..." << endl;
  shared_ptr<Person> sp3 = sharedPointerOne();
  cout << "  Reference count = " << sp3.use_count() << endl;
  sp3->print();

  //-------------------------------
  cout << "Making a cycle of Foo objects using shared_ptr's. Notice no "
          "deletions..."
       << endl;
  sharedPointerTwo();

  //-------------------------------
  cout << "Making a cycle of Bar objects using weak_ptr's. They get cleaned "
          "up..."
       << endl;
  weakPointerOne();

  return 0;
}
