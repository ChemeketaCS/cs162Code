#ifndef RATIONLWITHOPERATORS_H
#define RATIONLWITHOPERATORS_H

#include <string>

class Rational {
public:
    Rational(int numerator, int denominator);

    int getNumerator() const;
    int getDenominator() const;
    double doubleValue() const;
    std::string toString() const;

    // Make a new Rational object that is the simplified version of this one
    Rational simplify() const;

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

private:
    int m_numerator;
    int m_denominator;
};

#endif
