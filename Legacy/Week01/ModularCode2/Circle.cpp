/**
 * Implements Circle class member functions
 */

// Needs to know about libraries that will be used
//  and the Circle class defined in the header
//  <name> = standard library
//  "name" = your header
#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle() {
  radius = 2;
  x = 0;
  y = 0;
}

Circle::Circle(double theRadius) {
  radius = theRadius;
  x = 0;
  y = 0;
}

Circle::Circle(double theRadius, double startX, double startY) {
  radius = theRadius;
  x = startX;
  y = startY;
}

double Circle::getArea() {
  return radius * radius * 3.14;
}

string Circle::toString() {
  double myArea = getArea();

  string output = "Circle with";
  output += " radius: " + to_string(radius);
  output += " area: " + to_string(myArea);
  return output;
}

double Circle::getRadius() {
  return radius;
}

void Circle::setRadius(double r) {
  radius = abs(r);
}
