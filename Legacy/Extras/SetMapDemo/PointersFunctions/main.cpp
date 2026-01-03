#include <iostream>

using namespace std;

// Swaps values pointers point to
// Take two memory adderesses as parameters - can change what is at those
// addresses
void swap3(int* p1, int* p2) {
  // Get value p1 points to
  int temp = *p1;
  // Copy value p2 points to into location p1 points to
  *p1 = *p2;
  // Copy value p1 used to point to into location p2 points to
  *p2 = temp;
}

// Swaps the locations the pointers point to
// Take references to two memory addresses - we can change the addresses
// themselves
void swap4(int*& p1, int*& p2) {
  // Get the address p1 stores
  int* temp = p1;
  // Copy address p2 stores over to p1
  p1 = p2;
  // Copy address p1 used to have over to p2
  p2 = temp;
}

// x is on the stack, memory will be reclaimed as we leave
//  the function... the pointer we return will point
//  to memory that gets used for something else!
int* badIdea() {
  int x = 10;
  int* pt = &x;
  return pt;
}

// p is a pointer to an int on the heap. p will disappear when
//  function ends, but the int out on the heap will stay there
//  until we delete it. So caller can use that pointer safely
//  but will be responsible for deleting it
int* goodIdea() {
  int* p = new int(20);
  return p;
}

int main() {
  // Ask function to get us the memory address of an int
  int* pointer1 = badIdea();
  // That memory probably still has the value 10 in it
  cout << "pointer1 right after badIdea() " << *pointer1 << endl;
  // The value pointer1 points to has almost certainly changed while doing last
  // cout
  cout << "pointer1 a little later " << *pointer1 << endl;

  int* pointer2 = goodIdea();
  cout << "pointer2 right after goodIdea() " << *pointer2 << endl;
  // Memory still should be fine... it was not on stack
  cout << "pointer1 a little later " << *pointer2 << endl;

  int num1 = 1;
  int num2 = 2;

  int* p1 = &num1;
  int* p2 = &num2;
  cout << "p1 and p2 start as " << p1 << "(value there is " << *p1 << ") " << p2
       << "(value there is " << *p2 << ")" << endl;

  cout << "Swaping the contents of memory they point to:" << endl;
  swap3(p1, p2);
  cout << "After swap3        " << p1 << "(value there is " << *p1 << ") " << p2
       << "(value there is " << *p2 << ")" << endl;

  cout << "Swaping the addresses they point to:" << endl;
  swap4(p1, p2);
  cout << "After swap4        " << p1 << "(value there is " << *p1 << ") " << p2
       << "(value there is " << *p2 << ")" << endl;
}
