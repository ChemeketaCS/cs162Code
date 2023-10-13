#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
    //Don't need virtual here... but nice
    virtual string toString() const override;

    Circle();
    Circle(double);
    Circle(double radius, const string& color, bool filled);

    //Destructor - called automatically when destroyed
    //Don't actually need this, just used to illustrate
    // when parts of object are destroyed
    ~Circle();

    double getRadius() const;
    void setRadius(double);
    double getArea() const;
    double getPerimeter() const;
    double getDiameter() const;

private:
    double radius;
};

#endif
