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
  cout << r1 << " + " << r2 << " = " << sum << endl;
  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
  cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
  cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

  // Test unary +/-
  Rational temp1 = -r2;
  cout << temp1 << endl;
  Rational temp2 = +r2;
  cout << temp2 << endl;

  // Test relational operators
  cout << r1 << " > " << r2 << " is " << ((r1 > r2) ? "true" : "false") << endl;
  cout << r1 << " < " << r2 << " is " << ((r1 < r2) ? "true" : "false") << endl;
  cout << r1 << " == " << r2 << " is " << ((r1 == r2) ? "true" : "false")
       << endl;
  cout << r1 << " != " << r2 << " is " << ((r1 != r2) ? "true" : "false")
       << endl;

  // Test augmented assignment operators
  Rational r3(1, 2);
  r3 += r1;
  cout << "Started with 1/2, added " << r1 << " then " << r2 << " got " << r3
       << endl;

  // Test function operator []
  Rational r4(0, 0);
  r4[0] = 3;
  r4[1] = 4;
  cout << "r4 is " << r4 << endl;

  // Test function operators for prefix ++ and postfix --
  cout << "Doing r3 = r4++. r3 should be old value of r4:" << endl;
  r3 = r4++;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;

  cout << "Doing r3 = --r4. Both should have same value:" << endl;
  r3 = --r4;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;

  // Test >> operator and double conversion
  cout << "Enter a fraction in form 3/4: ";
  Rational inputRational;
  cin >> inputRational;
  cout << inputRational << " is " << static_cast<double>(inputRational) << endl;

  return 0;
}
