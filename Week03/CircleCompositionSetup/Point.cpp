// Includes needed for logic inside functions
#include <cmath> // for sqrt
#include <format>

// Point.h will include string already
#include "Point.h"

using namespace std;

Point::Point(double x, double y) {
  m_x = x;
  m_y = y;
}

Point::Point() {
  m_x = 0;
  m_y = 0;
}

double Point::getX() const {
  return m_x;
}

double Point::getY() const {
  return m_y;
}

void Point::setX(double x) {
  m_x = x;
}

void Point::setY(double y) {
  m_y = y;
}

void Point::shift(double dx, double dy) {
  setX(getX() + dx);
  setY(getY() + dy);
}

string Point::toString() const {
  return format("({}, {})", getX(), getY());
}

double Point::distanceTo(const Point& other) const {
  double xdiff = other.m_x - m_x;
  double ydiff = other.m_y - m_y;
  double distance = sqrt(xdiff * xdiff + ydiff * ydiff);
  return distance;
}