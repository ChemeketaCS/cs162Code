#include "Circle.h"

// Initialize static variables:
int Circle::numberOfObjects = 0;
const double Circle::PI = 3.14159;

Circle::Circle() {
  radius = 1;
  numberOfObjects++;
}

Circle::Circle(double startRadius) {
  radius = startRadius;
  numberOfObjects++;
}

double Circle::getArea() {
  return radius * radius * PI;
}

double Circle::getRadius() {
  return radius;
}

void Circle::setRadius(double newRadius) {
  radius = (newRadius >= 0) ? newRadius : 0;
}

int Circle::getNumberOfObjects() {
  return numberOfObjects;
}
