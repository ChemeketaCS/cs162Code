#include <format>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double width, double height, string color)
  : GeometricObject(color) {
    m_width = width;
    m_height = height;
}

double Rectangle::getArea() const {
    return m_width * m_height;
}

string Rectangle::toString() const {
    return format("A {} rectangle with dimensions of {} by {}.", 
                  getColor(),
                  m_width,
                  m_height);
}