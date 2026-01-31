#include <format>
#include <stdexcept>
#include <numeric>
#include "Rational.h"

using namespace std;

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    m_numerator = numerator;
    m_denominator = denominator;
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
  // Create a copy of the object before incrementing
  Rational temp = *this;
  // Increment the current object
  m_numerator += m_denominator;
  // Return the copy of the object that has the old value
  return temp;
}