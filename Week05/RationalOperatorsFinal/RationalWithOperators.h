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

    // Declare non-member math operators as friends so can access private data
    friend Rational operator+(const Rational& r1, const Rational& r2);
    friend Rational operator-(const Rational& r1, const Rational& r2);
    friend Rational operator*(const Rational& r1, const Rational& r2);
    friend Rational operator/(const Rational& r1, const Rational& r2);

    // Declare augmented assignment operators as members
    Rational& operator+=(const Rational& secondRational);
    Rational& operator-=(const Rational& secondRational);
    Rational& operator*=(const Rational& secondRational);
    Rational& operator/=(const Rational& secondRational);

    // Define function operator []
    int& operator[](int index);

    // Function operators for prefix ++ and --
    Rational& operator++();
    Rational& operator--();

    // Function operators for postfix ++ and --
    Rational operator++(int dummy);
    Rational operator--(int dummy);

    // Function operators for unary + and -
    Rational operator+() const;
    Rational operator-() const;

    // Conversions to int and double
    operator int() const;
    operator double() const;

    // Declare the << and >> operators as friends with private access
    friend ostream& operator<<(ostream& stream, const Rational& output);
    friend istream& operator>>(istream& stream, Rational& input);

private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

// Define non-member function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

// Define non-member function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

#endif
