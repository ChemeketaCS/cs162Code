#include "DerivedCylinder.h"

#include <iostream>

using namespace std;

DerivedCylinder::DerivedCylinder(double radius, double theHeight)
    : Circle(radius), height(theHeight)
{
    //initialized all variables in initialization statement
}

DerivedCylinder::DerivedCylinder(double radius, double theHeight, double x, double y)
    : Circle(radius, x, y), height(theHeight)
{
    //initialized all variables in initialization statement
}

DerivedCylinder::DerivedCylinder(const Circle& theBase, double theHeight)
    : Circle(theBase), height(theHeight)
{
    //initialized all variables in initialization statement
}

double DerivedCylinder::getSurfaceArea() const {
    //assumes right DerivedCylinder...
    double baseArea = getArea();
    double lateralArea = getCircumference();
    return 2 * baseArea + lateralArea;
}

Circle DerivedCylinder::getBase() const {
    return Circle(*this);
}

double DerivedCylinder::getVolume() const {
    double baseArea = getArea();
    return baseArea * height;
}

void DerivedCylinder::print() const {
    cout << "DerivedCylinder with radius: " << getRadius()
         << " and height: " << height << endl;
}
