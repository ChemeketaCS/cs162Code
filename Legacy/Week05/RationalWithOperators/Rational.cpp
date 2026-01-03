#include "Rational.h"
#include <sstream>

#include <cmath>

//--------------------Constructors------------------------------
Rational::Rational() {
  numerator = 0;
  denominator = 1;
}

// Suitable for type conversion
Rational::Rational(int theNumerator) {
  cout << "Making a rational out of a whole..." << endl;
  this->numerator = theNumerator;
  this->denominator = 1;
}

Rational::Rational(int theNumerator, int theDenominator) {
  // Simplify fraction
  int factor = gcd(theNumerator, theDenominator);
  // if denominator negative, make numerator negative
  this->numerator = ((theDenominator > 0) ? 1 : -1) * theNumerator / factor;
  // denominator always positive
  this->denominator = abs(theDenominator) / factor;
}

string Rational::toString() {
  return to_string(numerator) + "/" + to_string(denominator);
}

//--------------------General Member Functions------------------------------
int Rational::getNumerator() const {
  return numerator;
}

int Rational::getDenominator() const {
  return denominator;
}

// Find GCD of two numbers
int Rational::gcd(int n, int d) {
  int n1 = abs(n);
  int n2 = abs(d);
  int gcd = 1;

  for (int k = 1; k <= n1 && k <= n2; k++) {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
  }

  return gcd;
}

int Rational::intValue() const {
  return getNumerator() / getDenominator();
}

double Rational::doubleValue() const {
  return 1.0 * getNumerator() / getDenominator();
}

//--------------------Member Operators------------------------------

// Define functions for arithmetic member operators
Rational Rational::operator+(const Rational& secondRational) const {
  // Calculate with a/b + c/d = (ad + cb)/bd
  int n = numerator * secondRational.denominator
          + denominator * secondRational.numerator;
  int d = denominator * secondRational.denominator;

  // Return new rational object with the correct value
  return Rational(n, d);
}

Rational Rational::operator-(const Rational& secondRational) const {
  // Calculate with a/b - c/d = (ad - cb)/bd
  int n = numerator * secondRational.denominator
          - denominator * secondRational.numerator;
  int d = denominator * secondRational.denominator;

  // Return new rational object with the correct value
  return Rational(n, d);
}

Rational Rational::operator*(const Rational& secondRational) const {
  int n = numerator * secondRational.numerator;
  int d = denominator * secondRational.denominator;

  return Rational(n, d);
}

Rational Rational::operator/(const Rational& secondRational) const {
  // Calculate with (a/b) / (c/d) = (ad) / (bc)
  int n = numerator * secondRational.denominator;
  int d = denominator * secondRational.numerator;

  return Rational(n, d);
}

bool Rational::operator==(const Rational& secondRational) const {
  // a/b == c/d iff a*d == c*b
  int val1 = numerator * secondRational.denominator;
  int val2 = secondRational.numerator * denominator;
  return (val1 == val2);
}

bool Rational::operator!=(const Rational& secondRational) const {
  int val1 = numerator * secondRational.denominator;
  int val2 = secondRational.numerator * denominator;
  return (val1 != val2);
}

bool Rational::operator<(const Rational& secondRational) const {
  // a/b < c/d iff a*d < c*b
  int val1 = numerator * secondRational.denominator;
  int val2 = secondRational.numerator * denominator;
  return (val1 < val2);
}

bool Rational::operator<=(const Rational& secondRational) const {
  int val1 = numerator * secondRational.denominator;
  int val2 = secondRational.numerator * denominator;
  return (val1 <= val2);
}

bool Rational::operator>(const Rational& secondRational) const {
  int val1 = numerator * secondRational.denominator;
  int val2 = secondRational.numerator * denominator;
  return (val1 > val2);
}

bool Rational::operator>=(const Rational& secondRational) const {
  int val1 = numerator * secondRational.denominator;
  int val2 = secondRational.numerator * denominator;
  return (val1 >= val2);
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++() {
  numerator += denominator;
  return *this;
}

Rational& Rational::operator--() {
  numerator -= denominator;
  return *this;
}

// Define function operators for postfix ++ and --
Rational Rational::operator++(int) // don't need a name for dummy param
{
  Rational temp(numerator, denominator);
  numerator += denominator;
  return temp;
}

Rational Rational::operator--(int) // don't need a name for dummy param
{
  Rational temp(numerator, denominator);
  numerator -= denominator;
  return temp;
}
