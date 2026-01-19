#include <format>
#include "GeometricObject.h"

using namespace std;

GeometricObject::GeometricObject(std::string color)
{
    this->m_color = color;
}

// getArea is abstract... nothing to list!

// note we do not use virtual outside the class
std::string GeometricObject::getColor() const
{
    return m_color;
}

std::string GeometricObject::toString() const
{
    return format("A {} object.", m_color);
}
