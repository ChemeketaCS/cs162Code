#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

Circle::Circle() {
    radius = 2;
    x = 0;
    y = 0;
    cout << "\t-Making a circle using no-arg constructor" << endl;
}

//Copy Constructor - don't worry about for now
Circle::Circle(const Circle& other) {
    radius = other.radius;
    x = other.x;
    y = other.y;
    cout << "\t----Making a new circle that is a copy of existing circle" << endl;
}

Circle::Circle(double theRadius) {
    radius = theRadius;
    x = 0;
    y = 0;
    cout << "\t-Making a circle using 1-arg constructor" << endl;
}

Circle::Circle(double theRadius, double startX, double startY) {
    radius = theRadius;
    x = startX;
    y = startY;
    cout << "\t-Making a circle using 3-arg constructor" << endl;
}

double Circle::getArea() const {
    return radius * radius * 3.14;
}

void Circle::print() {
    cout << "Circle with a radius of " << radius << endl
         << "    centered at " << x << ", " << y << endl;
}

double Circle::getRadius() { return radius; }

void Circle::setRadius(double r) {
    radius = abs(r);
}

