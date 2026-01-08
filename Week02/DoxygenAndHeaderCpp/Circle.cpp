/**
 * @file Circle.cpp
 * @author Andrew Scholer
 *
 */

#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle() {
  m_radius = 2;
  m_x = 0;
  m_y = 0;
}

Circle::Circle(double radius) {
  m_radius = radius;
  m_x = 0;
  m_y = 0;
}

Circle::Circle(double radius, double xLocation, double yLocation) {
  m_radius = radius;
  m_x = xLocation;
  m_y = yLocation;
}

double Circle::getArea() {
  double area = m_radius * m_radius * numbers::pi;
  return area;
}

string Circle::toString() {
  double myArea = getArea();

  string output = "Circle with";
  output += " radius: " + to_string(m_radius);
  output += " area: " + to_string(myArea);
  return output;
}

double Circle::getRadius() {
  return m_radius;
}

void Circle::setRadius(double newRadius) {
  m_radius = abs(newRadius);
}
