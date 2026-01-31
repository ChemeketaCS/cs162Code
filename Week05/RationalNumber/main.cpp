#include "Rational.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(2, 5);
  Rational r2(4, 3);

  // Test toString, add, subtract, multiply, and divide operators
  Rational sum = r1 + r2;
  cout << r1.toString() << " + " << r2.toString() << " = " << sum.toString()
       << endl;

  // Long syntax version of add
  Rational sum2 = r1.operator+(r2);

  // Test relational operators
  cout << r1.toString() << " == " << r2.toString() << " is "
       << ((r1 == r2) ? "true" : "false") << endl;
  cout << r1.toString() << " != " << r2.toString() << " is "
       << ((r1 != r2) ? "true" : "false") << endl;

  // Test operators for prefix ++ and postfix --
  Rational r4(1, 2);
  cout << "Doing r3 = r4++. r3 should be old value of r4:" << endl;
  Rational r3 = r4++;
  cout << "r3 is " << r3.toString() << endl;
  cout << "r4 is " << r4.toString() << endl;

  cout << "Doing r3 = ++r4. Both should have same value:" << endl;
  r3 = ++r4;
  cout << "r3 is " << r3.toString() << endl;
  cout << "r4 is " << r4.toString() << endl;
}
