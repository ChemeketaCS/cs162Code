#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

Circle::Circle() {
    //Assume you want a circle at 0,0 with radius=1
    radius = 1;
    x = 0;
    y = 0;
}

Circle::Circle(double theRadius) {
    //Make a circle at 0,0 with indicated radius
    // Radius should never be set to a negative value,
    // this has a bug!!!
    radius = theRadius;
    x = 0;
    y = 0;
}

Circle::Circle(double theRadius, double startX, double startY) {
    //Call our setRadius function to set the initial radius
    // it will make sure we don't use a negative radius
    setRadius(theRadius);
    //Directly set the initial x and y
    x = startX;
    y = startY;
}

double Circle::getX() {
    return x;
}

double Circle::getY() {
    return y;
}

double Circle::getArea() {
    return radius * radius * 3.14;
}

void Circle::print() {
    cout << "Circle with a radius of " << radius << endl
         << "    centered at " << x << ", " << y;
}

double Circle::getRadius() { return radius; }

void Circle::setRadius(double r) {
    radius = abs(r);
}

