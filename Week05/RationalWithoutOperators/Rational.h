#ifndef RATIONL_H
#define RATIONL_H
#include <string>
using namespace std;

class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);
    int getNumerator() const;
    int getDenominator() const;
    Rational add(const Rational &secondRational) const;
    Rational subtract(const Rational &secondRational) const;
    Rational multiply(const Rational &secondRational) const;
    Rational divide(const Rational &secondRational) const;
    int compareTo(const Rational &secondRational) const;
    bool equals(const Rational &secondRational) const;
    int intValue() const;
    double doubleValue() const;
    string toString() const;

private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

#endif

