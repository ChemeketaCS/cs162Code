#include "Rational.h"
#include <iostream>
using namespace std;

int main() {
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 2);
  Rational r2(2, 3);

  // Test toString, add, subtract, multiply, and divide
  // Add makes a new rational with answer
  Rational r3 = r1.add(r2);

  cout << r1.toString() << " + " << r2.toString() << " = " << r3.toString()
       << endl;

  // Subtract creates anonymous object, ask it to make a string, then forget
  // about it
  cout << r1.toString() << " - " << r2.toString() << " = "
       << r1.subtract(r2).toString() << endl;
  cout << r1.toString() << " * " << r2.toString() << " = "
       << r1.multiply(r2).toString() << endl;
  cout << r1.toString() << " / " << r2.toString() << " = "
       << r1.divide(r2).toString() << endl;

  // Test intValue and double
  cout << "r2.intValue()"
       << " is " << r2.intValue() << endl;
  cout << "r2.doubleValue()"
       << " is " << r2.doubleValue() << endl;

  // Test compareTo and equal
  cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;
  cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
  cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
  cout << "r1.equals(r1) is " << (r1.equals(r1) ? "true" : "false") << endl;
  cout << "r1.equals(r2) is " << (r1.equals(r2) ? "true" : "false") << endl;

  return 0;
}
