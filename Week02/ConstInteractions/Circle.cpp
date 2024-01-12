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

double Circle::getX() const {
  return x;
}

double Circle::getY() const {
  return y;
}

double Circle::getArea() const {
  return radius * radius * 3.14;
}

void Circle::print() const {
  cout << "Circle with a radius of " << radius << endl
       << "    centered at " << x << ", " << y << endl;
}

double Circle::getRadius() const {
  return radius;
}

void Circle::setRadius(double r) {
  radius = abs(r);
}

void Circle::moveTo(const Point& p) {
  // Set my x and y to the values I get from p
  // Can't access private members directly - use get functions
  x = p.getX();
  y = p.getY();
}

bool Circle::contains(const Point& p) const {
  // Point already has a method to find distance, use that...
  // Make a point reprsenting our center
  Point myCenter(x, y);
  // If that point is closer or same distance to p than our radius, p is in
  // circle
  return myCenter.distanceTo(p) <= radius;
}
