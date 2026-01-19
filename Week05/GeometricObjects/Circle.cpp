#include <format>
#include "Circle.h"

using namespace std;

Circle::Circle(double radius, string color)
    : GeometricObject(color) {
    m_radius = radius;
}

double Circle::getArea() const {
    return std::numbers::pi * m_radius * m_radius;
}

string Circle::toString() const {
    return format("A {} circle with a radius of {}.", m_color, m_radius);
}