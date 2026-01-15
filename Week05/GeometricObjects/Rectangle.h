#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometricObject.h"
#include <string>

class Rectangle : public GeometricObject {
private:
    double m_width;
    double m_height;

public:
    Rectangle(double width, double height, std::string color);

    // provide an implementation of the getArea function
    //  it is no longer abstract
    virtual double getArea() const;

    // override the toString function
    virtual std::string toString() const;
};

#endif