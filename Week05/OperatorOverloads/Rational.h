#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>

using namespace std;

class Rational {
private:
    int m_numerator;
    int m_denominator;

public:
    Rational(int numerator, int denominator);

    // Declare an assignment operator
    // Rational& operator=(const Rational& other);

    int getNumerator() const;
    int getDenominator() const;
    double doubleValue() const;
    string toString() const;

    // Make a new Rational object that is the simplified version of this one
    Rational simplify() const;

    // Some functions we will build later...
    // Non-operator functions
    Rational add(const Rational& other) const;
    bool equals(const Rational& other) const;

    // Operators versions of those functions
    Rational operator+(const Rational& other) const;
    bool operator==(const Rational& other) const;

    // Other operators
    Rational& operator++();   // Prefix increment
    Rational operator++(int); // Postfix increment
    Rational& operator--();   // Prefix decrement
    Rational operator--(int); // Postfix decrement
};

#endif