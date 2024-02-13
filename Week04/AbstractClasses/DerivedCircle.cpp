#include "DerivedCircle.h"

#include <iostream>
#include <sstream>

// Construct a default circle object
Circle::Circle(): GeometricObject("Red", false) {
  radius = 1;
}

// Construct a circle object with specified radius
Circle::Circle(double radius): GeometricObject("Red", false) {
  setRadius(radius);
}

// Construct a circle object with specified radius,
//   Use color and fill to init GeometricObject part of self
Circle::Circle(double theRadius, const string& color, bool filled):
    GeometricObject(color, filled), radius(theRadius) {
}

// Return the radius of this circle
double Circle::getRadius() const {
  return radius;
}

// Set a new radius
void Circle::setRadius(double radius) {
  this->radius = (radius >= 0) ? radius : 0;
}

// Return the area of this circle
double Circle::getArea() const {
  return radius * radius * 3.14159;
}

// Return the perimeter of this circle
double Circle::getPerimeter() const {
  return 2 * radius * 3.14159;
}

// Return the diameter of this circle
double Circle::getDiameter() const {
  return 2 * radius;
}

// Redefine the toString function
string Circle::toString() const {
  stringstream descriptor;
  descriptor << "Circle object" << endl
             << "   uses: " << GeometricObject::toString() << endl
             << " -radius: " << getRadius() << endl
             << " -area: " << getArea() << endl
             << " -perimeter: " << getPerimeter();

  return descriptor.str();
}
