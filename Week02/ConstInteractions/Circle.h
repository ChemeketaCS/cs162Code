#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle {
public:
    Circle();
    Circle(double startRadius);
    Circle(double startRadius, double startX, double startY);

    double getX() const;
    double getY() const;
    double getArea() const;
    void print() const;
    double getRadius() const;
    void setRadius(double newRadius);

    /**
     * @brief Move circle to location described by Point p
     * @param p New location for center of circle
     */
    void moveTo(const Point& p);

    /**
     * @brief Returns true if circle contains given point. A Point
     *          on the circle's border counts as being contained.
     * @param p Point to test
     * @return True if point is on or inside the border
     */
    bool contains(const Point& p) const;

private:
    double radius;
    double x;
    double y;
};


#endif // CIRCLE_H


