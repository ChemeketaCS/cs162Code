#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
    //Don't need virtual here... but nice
    virtual string toString() const;

    Circle();
    Circle(double);
    Circle(double radius, const string& color, bool filled);
    double getRadius() const;
    void setRadius(double);
    double getArea() const;
    double getPerimeter() const;
    double getDiameter() const;

private:
    double radius;
};

#endif
