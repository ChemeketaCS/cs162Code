#include <iostream>

using namespace std;

class SimpleList {
public:
  int* numbers;
  SimpleList() {
    cout << "Construct SimpleList..." << endl;
    numbers = new int[10];
  }
  virtual ~SimpleList() {
    cout << "Destruct SimpleList..." << endl;
    delete[] numbers;
  }
  SimpleList(const SimpleList& other) {
    cout << "COPY SimpleList..." << endl;
    numbers = new int[10]; // also would copy values over
  }
  SimpleList& operator=(const SimpleList& other) {
    cout << "ASSIGN SimpleList..." << endl;
    if (this != &other) {
      delete[] numbers;
      numbers = new int[10]; // also would copy values over
    }
    return *this;
  }
};

class LessSimpleList: public SimpleList {
public:
  // Store one extra char of memory on the heap
  char* oneChar;

  LessSimpleList() {
    cout << "Construct LessSimpleList..." << endl;
    oneChar = new char('x');
  }
  virtual ~LessSimpleList() {
    cout << "Destruct LessSimpleList..." << endl;
    delete oneChar;
  }
  LessSimpleList(const LessSimpleList& other): SimpleList(other) {
    cout << "COPY LessSimpleList..." << endl;
    oneChar = new char(*other.oneChar);
  }
  LessSimpleList& operator=(const LessSimpleList& other) {
    // Call the assignment operator my parent defined
    SimpleList::operator=(other);
    cout << "ASSIGN LessSimpleList..." << endl;
    if (this != &other) {
      delete oneChar;
      oneChar = new char(*other.oneChar);
    }
    return *this;
  }
};

int main() {
  LessSimpleList l1;

  //    //Try copy constructor
  //    LessSimpleList l2(l1);

  //    LessSimpleList l3;
  //    //Try assignment
  //    l3 = l1;

  return 0;
}
