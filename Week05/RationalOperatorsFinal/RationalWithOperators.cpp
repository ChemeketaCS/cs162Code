#include "RationalWithOperators.h"
#include <sstream>

#include <cmath>

//--------------------Constructors------------------------------
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

// Suitable for type conversion
Rational::Rational(int theNumerator)
{
    cout << "Making a rational out of a whole..." << endl;
    this->numerator = theNumerator;
    this->denominator = 1;
}


Rational::Rational(int theNumerator, int theDenominator)
{
    //Simplify fraction
    int factor = gcd(theNumerator, theDenominator);
    //if denominator negative, make numerator negative
    this->numerator = ((theDenominator > 0) ? 1 : -1) * theNumerator / factor;
    //denominator always positive
    this->denominator = abs(theDenominator) / factor;
}


//--------------------General Member Functions------------------------------
int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

// Find GCD of two numbers 
int Rational::gcd(int n, int d)
{
    int n1 = abs(n);
    int n2 = abs(d);
    int gcd = 1;

    for (int k = 1; k <= n1 && k <= n2; k++)
    {
        if (n1 % k == 0 && n2 % k == 0)
            gcd = k;
    }

    return gcd;
}



//--------------------Member Operators------------------------------

// Define function operators for shorthand operators
Rational& Rational::operator+=(const Rational& secondRational)
{
    //Calculate new value using self and other Rational
    int n = numerator * secondRational.getDenominator() +
            denominator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();

    //Change this object
    numerator = n;
    denominator = d;

    //Return this object... but done as reference
    return *this;
}

Rational& Rational::operator-=(const Rational& secondRational)
{
    int n = numerator * secondRational.getDenominator()
            - denominator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();

    numerator = n;
    denominator = d;

    return *this;
}

Rational& Rational::operator*=(const Rational& secondRational)
{
    int n = numerator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();

    numerator = n;
    denominator = d;

    return *this;
}

Rational& Rational::operator/=(const Rational& secondRational)
{
    int n = numerator * secondRational.getDenominator();
    int d = denominator * secondRational.numerator;

    numerator = n;
    denominator = d;

    return *this;
}

// Define function operator []
int& Rational::operator[](int index)
{
    if (index == 0)
        return numerator;
    else if (index == 1)
        return denominator;
    else
    {
        cout << "No can do..." << endl;
        exit(0);
    }
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++()
{
    numerator += denominator;
    return *this;
}

Rational& Rational::operator--()
{
    numerator -= denominator;
    return *this;
}

// Define function operators for postfix ++ and --
Rational Rational::operator++(int)
{
    Rational temp(numerator, denominator);
    numerator += denominator;
    return temp;
}

Rational Rational::operator--(int)
{
    Rational temp(numerator, denominator);
    numerator -= denominator;
    return temp;
}

// Define function operators for unary + and -
Rational Rational::operator+() const
{
    //Just return a copy of ourselves
    return *this;
}

Rational Rational::operator-() const
{
    //Make a new fraction that is this one negated
    return Rational(-numerator, denominator);
}


// Define conversions to int and double
Rational::operator int() const
{
    cout << "Converting to an int..." << endl;
    //return whole value, no rounding up
    return numerator / denominator;
}

Rational::operator double() const
{
    cout << "Converting to a double..." << endl;
    //force decimal math
    return static_cast<double>(numerator) / denominator;
}



//--------------------NonMember Operators------------------------------


// Define the output and input operator
ostream& operator<<(ostream& stream, const Rational& output)
{
    //output whole number as such, other in 1/2 form
    if (output.denominator == 1)
        stream << output.numerator;
    else
        stream << output.numerator << "/" << output.denominator;

    //return the stream by reference so something else can use it
    return stream;
}

istream& operator>>(istream& stream, Rational& input)
{
    //read in an integer
    stream >> input.numerator;
    //read in one char, hopefully the /
    char c;
    stream >> c;
    //read in another integer
    stream >> input.denominator;

    //if we didn't see the / or the stream failed (reading the integers), die
    if(c != '/' || !stream) {
        cout << "Input Failure" << endl;
        exit(0);
    }

    //return stream for reuse
    return stream;
}


// Define function operators for relational operators

bool operator==(const Rational& r1, const Rational& r2)
{
    // a/b == c/d iff a*d == c*b
    int val1 = r1.getNumerator() * r2.getDenominator();
    int val2 = r2.getNumerator() * r1.getDenominator();
    return (val1 == val2);
}

bool operator!=(const Rational& r1, const Rational& r2)
{
    int val1 = r1.getNumerator() * r2.getDenominator();
    int val2 = r2.getNumerator() * r1.getDenominator();
    return (val1 != val2);
}

bool operator<(const Rational& r1, const Rational& r2)
{
    // a/b < c/d iff a*d < c*b
    int val1 = r1.getNumerator() * r2.getDenominator();
    int val2 = r2.getNumerator() * r1.getDenominator();
    return (val1 < val2);
}

bool operator<=(const Rational& r1, const Rational& r2)
{
    int val1 = r1.getNumerator() * r2.getDenominator();
    int val2 = r2.getNumerator() * r1.getDenominator();
    return (val1 <= val2);
}

bool operator>(const Rational& r1, const Rational& r2)
{
    int val1 = r1.getNumerator() * r2.getDenominator();
    int val2 = r2.getNumerator() * r1.getDenominator();
    return (val1 > val2);
}

bool operator>=(const Rational& r1, const Rational& r2)
{
    int val1 = r1.getNumerator() * r2.getDenominator();
    int val2 = r2.getNumerator() * r1.getDenominator();
    return (val1 >= val2);
}


// Define non-member function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2)
{
    //Implemented as a friend, so it has private access
    int n = r1.numerator * r2.denominator +
            r1.denominator * r2.numerator;
    int d = r1.denominator * r2.denominator;
    return Rational(n, d);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    //Non-friend - no private access
    int n = r1.getNumerator() * r2.getDenominator() -
            r1.getDenominator() * r2.getNumerator();
    int d = r1.getDenominator() * r2.getDenominator();
    return Rational(n, d);
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    //Non-friend - no private access
    int n = r1.getNumerator() * r2.getNumerator();
    int d = r1.getDenominator() * r2.getDenominator();
    return Rational(n, d);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    //Non-friend - no private access
    int n = r1.getNumerator() * r2.getDenominator();
    int d = r1.getDenominator() * r2.getDenominator();
    return Rational(n, d);
}
