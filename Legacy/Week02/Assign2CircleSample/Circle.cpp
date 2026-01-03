/**
 * @author Andrew Scholer
 */

#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle() {
  // center will aleady default to being a point
  //  made by a default constructor... we don't need the next
  //  line.
  // center = Point();

  radius = 1; // Default will be radius of 1
}

Circle::Circle(double startRadius) {
  // Use our setRadius function to avoid having to duplicate its code
  setRadius(startRadius);
  // Instead, we could do directly as:
  // radius = abs(startRadius);

  // center will aleady default to being a point
  //  made by a default constructor... we don't need the next
  //  line.
  // center = Point(); //Relying on Point default being 0, 0
}

Circle::Circle(double startRadius, const Point& centerPoint) {
  setRadius(startRadius);

  // set our center to be a copy of the given point
  center = centerPoint;
}

Circle::Circle(double startRadius, double startX, double startY) {
  setRadius(startRadius);

  // Make an anonymous point using given values, copy that into our center
  center = Point(startX, startY);
  // Instead, we could just move the default point we start with to the
  //  correct location:
  // center.setX(startX);
  // center.setY(startY);
}

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
