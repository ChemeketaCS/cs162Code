#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle() {
  // Assume you want a circle at 0,0 with radius=1
  m_radius = 1;
  m_x = 0;
  m_y = 0;
}

Circle::Circle(double radius) {
  // Call our setRadius function to set the initial radius
  //  it will make sure we don't use a negative radius
  setRadius(radius);
  m_x = 0;
  m_y = 0;
}

Circle::Circle(double radius, double xLocation, double yLocation) {
  // Call our setRadius function to set the initial radius
  //  it will make sure we don't use a negative radius
  setRadius(radius);
  // Directly set the initial x and y
  m_x = xLocation;
  m_y = yLocation;
}

double Circle::getX() {
  return m_x;
}

double Circle::getY() {
  return m_y;
}

double Circle::getArea() {
  double area = m_radius * m_radius * numbers::pi;
    return area;
}

void Circle::print() {
  cout << "Circle with a radius of " << m_radius << endl
       << "    centered at " << m_x << ", " << m_y;
}

double Circle::getRadius() {
  return m_radius;
}

void Circle::setRadius(double newRadius) {
  m_radius = abs(newRadius);
}
