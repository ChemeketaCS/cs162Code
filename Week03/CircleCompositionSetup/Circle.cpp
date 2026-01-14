#include "Circle.h"

double Circle::getX() const {
  return m_center.getX();
}

double Circle::getY() const {
  return m_center.getY();
}

Circle::Circle(double radius, double x, double y) {
  m_radius = radius;
  m_center = Point(x, y);
}

double Circle::getRadius() const {
  return m_radius;
}

bool Circle::contains(const Point& p) const {
  double distance = m_center.distanceTo(p);
  if (distance <= m_radius) {
    return true; // Point is inside or on the circle
  } else {
    return false; // Point is outside the circle
  }
}
