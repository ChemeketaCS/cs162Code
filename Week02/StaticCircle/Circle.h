#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    double radius;

    //how many circles have been made
    static int numberOfObjects;

public:
    //value of PI
    const static double PI;

    Circle();
    Circle(double);
    double getArea();
    double getRadius();
    void setRadius(double);
    static int getNumberOfObjects();
};


#endif // CIRCLE_H
