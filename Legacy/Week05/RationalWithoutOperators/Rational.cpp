#include "Rational.h"
#include <sstream> // Used in toString to convert numbers to strings

#include <cmath>

Rational::Rational() {
  numerator = 0;
  denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
  // Simplify fraction
  int factor = gcd(numerator, denominator);
  // if denominator negative, make numerator negative
  this->numerator = ((denominator > 0) ? 1 : -1) * numerator / factor;
  // denominator always positive
  this->denominator = abs(denominator) / factor;
}

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

Rational Rational::add(const Rational& secondRational) const {
  int n = numerator * secondRational.getDenominator()
          + denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::subtract(const Rational& secondRational) const {
  int n = numerator * secondRational.getDenominator()
          - denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::multiply(const Rational& secondRational) const {
  int n = numerator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::divide(const Rational& secondRational) const {
  int n = numerator * secondRational.getDenominator();
  int d = denominator * secondRational.numerator;
  return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const {
  Rational temp = subtract(secondRational);
  if (temp.getNumerator() < 0)
    return -1;
  else if (temp.getNumerator() == 0)
    return 0;
  else
    return 1;
}

bool Rational::equals(const Rational& secondRational) const {
  if (compareTo(secondRational) == 0)
    return true;
  else
    return false;
}

int Rational::intValue() const {
  return getNumerator() / getDenominator();
}

double Rational::doubleValue() const {
  return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString() const {
  stringstream ss1, ss2;
  ss1 << numerator;
  ss2 << denominator;

  if (denominator == 1)
    return ss1.str() + "";
  else
    return ss1.str() + "/" + ss2.str();
}
