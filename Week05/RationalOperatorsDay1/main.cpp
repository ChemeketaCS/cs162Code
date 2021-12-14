#include <iostream>
#include <string>
#include "RationalWithOperators.h"

using namespace std;

int main()
{

    // Create and initialize two rational numbers r1 and r2.
    Rational r1(2, 5);
    Rational r2(4, 3);

    // Test toString, add, subtract, multiply, and divide operators
    Rational sum = r1 + r2;
    Rational diff = r1 - r2;
    Rational product = r1 * r2;
    Rational quotient = r1 / r2;
    cout << r1.toString() << " + " << r2.toString() << " = " << sum.toString() << endl;
    cout << r1.toString() << " - " << r2.toString() << " = " << diff.toString() << endl;
    cout << r1.toString() << " * " << r2.toString() << " = " << product.toString() << endl;
    cout << r1.toString() << " / " << r2.toString() << " = " << quotient.toString() << endl;

    //Test unary +/-
    Rational temp1 = -r2;
    cout << temp1.toString() << endl;
    Rational temp2 = +r2;
    cout << temp2.toString() << endl;


    // Test relational operators
    cout << r1.toString() << " > " << r2.toString() << " is " <<
            ((r1 > r2) ? "true" : "false") << endl;
    cout << r1.toString() << " < " << r2.toString() << " is " <<
            ((r1 < r2) ? "true" : "false") << endl;
    cout << r1.toString() << " == " << r2.toString() << " is " <<
            ((r1 == r2) ? "true" : "false") << endl;
    cout << r1.toString() << " != " << r2.toString() << " is " <<
            ((r1 != r2) ? "true" : "false") << endl;

    // Test augmented assignment operators
    Rational r3(1, 2);
    r3 += r1;
    cout << "Started with 1/2, added " << r1.toString() << " then " << r2.toString()
         << " got " << r3.toString() << endl;

    Rational r4;
    // Test function operators for prefix ++ and postfix --
    cout << "Doing r3 = r4++. r3 should be old value of r4:" << endl;
    r3 = r4++;
    cout << "r3 is " << r3.toString() << endl;
    cout << "r4 is " << r4.toString() << endl;

    cout << "Doing r3 = --r4. Both should have same value:" << endl;
    r3 = --r4;
    cout << "r3 is " << r3.toString() << endl;
    cout << "r4 is " << r4.toString() << endl;


    return 0;
}
