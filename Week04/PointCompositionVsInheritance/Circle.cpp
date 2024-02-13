#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

////-------------------Inefficient Constuctors-------------------
////Depend on availability of default constructor for Point
// Circle::Circle() {
//     radius = 2;
//     //Approach 1: modify center to desired value
//     center.setX(0);
//     center.setY(0);
// }

// Circle::Circle(double theRadius) {
//     radius = theRadius;
//     //Approach 2: Replace center with an anonymous Point
//     center = Point(0,0);
// }

// Circle::Circle(double theRadius, double startX, double startY)
//{
//     radius = theRadius;
//     //Make anonymous point using desired location
//     center = Point(startX, startY);
// }

// Circle::Circle(double startRadius, const Point& centerPoint)
//{
//     radius = startRadius;
//     //Copy given point into our center Point
//     center = centerPoint;
// }
////----------------------------------------------------------------

////-------------------Efficient Constuctors---------------------
////Do not depend on availability of default constructor for Point
Circle::Circle(): radius(2), center(0, 0) {
  // initialized all variables in initialization statement
}

Circle::Circle(double startRadius): radius(startRadius), center(0, 0) {
  // initialized all variables in initialization statement
}

Circle::Circle(double startRadius, const Point& centerPoint):
    radius(startRadius), center(centerPoint) {
  // initialized all variables in initialization statement
}

Circle::Circle(double startRadius, double startX, double startY):
    radius(startRadius), center(startX, startY) {
  // initialized all variables in initialization statement
}
////----------------------------------------------------------------

double Circle::getX() const {
  return center.getX();
}

double Circle::getY() const {
  return center.getY();
}

Point Circle::getCenter() const {
  return center;
}

double Circle::getArea() const {
  return radius * radius * 3.14;
}

double Circle::getCircumference() const {
  return 2 * radius * 3.14;
}

void Circle::print() const {
  cout << "Circle with a radius of " << radius << endl
       << "    centered at " << getX() << ", " << getY() << endl;
}

double Circle::getRadius() const {
  return radius;
}

void Circle::setRadius(double r) {
  radius = abs(r);
}

void Circle::moveTo(const Point& p) {
  // Copy other point's information to my center
  center = p;
}

bool Circle::intersects(const Circle& other) {
  // Ask center point to calculate distance to other center
  double distance = center.distanceTo(other.center);
  // Intersect if distance between the centers <= sum of radii
  if (distance <= (radius + other.radius))
    return true;
  else
    return false;
}
