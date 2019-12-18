/**
  * Defines circle class, does not implement
  */

//Header guard avoid multiple copies of code being included
// in any one .cpp file
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    Circle();
    Circle(double startRadius);
    Circle(double startRadius, double startX, double startY);

    double getArea();
    void print();
    double getRadius();
    void setRadius(double newRadius);

private:
    double radius;
    double x;
    double y;
};


#endif // CIRCLE_H


