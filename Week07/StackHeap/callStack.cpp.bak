#include <iostream>
using namespace std;

void foo(int x) {
  cout << "Starting foo()" << endl;
  cout << "Ending foo()" << endl;
}

void bar(int y) {
  cout << "Starting bar()" << endl;
  foo(2 * y);
  cout << "Ending bar()" << endl;
}

int main() {
  cout << "Starting main()" << endl;
  bar(5);
  foo(7); //Directly call foo()
  bar(10);
  cout << "Ending main()" << endl;
}