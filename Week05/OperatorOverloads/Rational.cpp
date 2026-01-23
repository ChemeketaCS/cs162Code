#include <format>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>

#include "Rational.h"

using namespace std;

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    m_numerator = numerator;
    m_denominator = denominator;
}

int Rational::getNumerator() const {
    return m_numerator;
}

int Rational::getDenominator() const {
    return m_denominator;
}

double Rational::doubleValue() const {
    return static_cast<double>(m_numerator) / m_denominator;
}

string Rational::toString() const {
    string stringRep = format("{}/{}", m_numerator, m_denominator);
    return stringRep;
}

Rational Rational::simplify() const {
    int divisor = std::gcd(abs(m_numerator), abs(m_denominator));
    int newNumerator = m_numerator / divisor;
    int newDenominator = m_denominator / divisor;
    // - sign should only be in the numerator
    if (newDenominator < 0) {
        newNumerator = -newNumerator;
        newDenominator = -newDenominator;
    }
    return Rational(newNumerator, newDenominator);
}

Rational Rational::add(const Rational& other) const {
    int newNumerator = m_numerator * other.m_denominator 
                       + other.m_numerator * m_denominator;
    int newDenominator = m_denominator * other.m_denominator;
    Rational result(newNumerator, newDenominator);
    return result.simplify();
}

bool Rational::equals(const Rational& other) const {
    return m_numerator * other.m_denominator 
           == other.m_numerator * m_denominator;
}

Rational Rational::operator+(const Rational& other) const {
    int newNumerator =
        m_numerator * other.m_denominator + other.m_numerator * m_denominator;
    int newDenominator = m_denominator * other.m_denominator;
    Rational result(newNumerator, newDenominator);
    return result.simplify();
}

bool Rational::operator==(const Rational& other) const {
    return m_numerator * other.m_denominator
           == other.m_numerator * m_denominator;
}

Rational& Rational::operator++() {
  m_numerator += m_denominator; // Increment by 1
  return *this; // Return this object
}

Rational Rational::operator++(int) {
  Rational temp = *this; // Make a copy for the old value
  m_numerator += m_denominator; // Increment by 1
  return temp; // Return the old value
}

// Rational& Rational::operator=(const Rational& other) {
//   // copy the values from other into this
//   m_numerator = other.m_numerator;
//   m_denominator = other.m_denominator;
//   return *this; // return a reference to the updated object
// }