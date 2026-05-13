#include <format>
#include "Circle.h"

using namespace std;


Circle::Circle(double radius, double x, double y): m_center(x, y) {
    m_radius = radius;
}

Circle::Circle(double radius): m_center(0, 0) {
    m_radius = radius;
}

Circle::Circle(double radius, const Point& p): m_center(p) {
    m_radius = radius;
}

double Circle::getRadius() const {
    return m_radius;
}

double Circle::getX() const {
    return m_center.getX();
}

double Circle::getY() const {
    return m_center.getY();
}

Point Circle::getCenter() const {
    return m_center;
}

double Circle::getArea() const {
    return std::numbers::pi * m_radius * m_radius;
}

double Circle::getCircumference() const {
    return 2 * std::numbers::pi * m_radius;
}

void Circle::setRadius(double radius) {
    m_radius = radius;
}

void Circle::setX(double x) {
    m_center.setX(x);
}

void Circle::setY(double y) {
    m_center.setY(y);
}

void Circle::shift(double dx, double dy) {
    m_center.shift(dx, dy);
}

std::string Circle::toString() const {
    return std::format("Circle(radius: {}, center: {})", m_radius,
                       m_center.toString());
}

bool Circle::contains(const Point& p) const {
    double distance = m_center.distanceTo(p);
    if (distance <= m_radius) {
        return true; // Point is inside or on the circle
    } else {
        return false; // Point is outside the circle
    }
}