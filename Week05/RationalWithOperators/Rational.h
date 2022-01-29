#ifndef RATIONLWITHOPERATORS_H
#define RATIONLWITHOPERATORS_H
#include <string>
#include <iostream>
using namespace std;


class Rational
{
public:
    Rational();
    Rational(int numerator); // Suitable for type conversion
    Rational(int numerator, int denominator);

    int getNumerator() const;
    int getDenominator() const;

    int intValue() const;
    double doubleValue() const;

    string toString();

    //Define arithmetic operators as members
    Rational operator+(const Rational& secondRational) const;
    Rational operator-(const Rational& secondRational) const;
    Rational operator*(const Rational& secondRational) const;
    Rational operator/(const Rational& secondRational) const;

    // Define member function operators for relational operators
    bool operator<(const Rational& secondRational) const;
    bool operator<=(const Rational& secondRational) const;
    bool operator>(const Rational& secondRational) const;
    bool operator>=(const Rational& secondRational) const;
    bool operator==(const Rational& secondRational) const;
    bool operator!=(const Rational& secondRational) const;

    // Define function operators for prefix ++ and --
    Rational& operator++();
    Rational& operator--();

    // Define function operators for postfix ++ and --
    Rational operator++(int dummy);
    Rational operator--(int dummy);

private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};


#endif
