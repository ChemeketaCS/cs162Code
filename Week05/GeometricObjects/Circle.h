#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeometricObject.h"
#include <string>

class Circle : public GeometricObject {
private:
    double m_radius;

public:
    Circle(double radius, std::string color);

    // same idea as Rectangle, but we will do different math
    double getArea() const;

    virtual std::string toString() const;
};

#endif