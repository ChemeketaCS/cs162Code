#include "Cylinder.h"
#include <iostream>

using namespace std;

Cylinder::Cylinder(double radius, double theHeight):
    base(radius), height(theHeight) {
  // initialized all variables in initialization statement
}

Cylinder::Cylinder(double radius, double theHeight, double x, double y):
    base(radius, x, y), height(theHeight) {
  // initialized all variables in initialization statement
}

Cylinder::Cylinder(const Circle& theBase, double theHeight):
    base(theBase), height(theHeight) {
  // initialized all variables in initialization statement
}

double Cylinder::getSurfaceArea() const {
  // assumes right cylinder...
  double baseArea = base.getArea();
  double lateralArea = base.getCircumference();
  return 2 * baseArea + lateralArea;
}

Circle Cylinder::getBase() const {
  return base;
}

double Cylinder::getVolume() const {
  double baseArea = base.getArea();
  return baseArea * height;
}

void Cylinder::print() const {
  cout << "Cylinder with radius: " << base.getRadius()
       << " and height: " << height << endl;
}
