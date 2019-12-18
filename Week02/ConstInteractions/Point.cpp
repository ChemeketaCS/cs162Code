#include <iostream>
#include <cmath>
using namespace std;

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double startX, double startY) {
    x = startX;
    y = startY;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double newX) {
    x = newX;
}

void Point::setY(double newY) {
    y = newY;
}

double Point::distanceTo(const Point& other) const {
    //Can directly access privates of other objects
    // only when they are the same class
    double xDiff = x - other.x;
    double yDiff = y - other.y;
    return sqrt( pow(xDiff, 2) + pow(yDiff, 2) );
}

bool Point::isSameAs(const Point& other) const {
    ///dangerous version:
    //if(x == other.x && y == other.y)
    ///compare floating points safely
    const double EPSILON = 0.0000001;
    if( (abs(x - other.x) < EPSILON) &&
        (abs(y - other.y) < EPSILON) )
        return true;
    else
        return false;
}

void Point::print() const {
    cout << "Point at (" << x << "," << y << ")" << endl;
}
