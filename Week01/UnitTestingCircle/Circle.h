#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    Circle();
    Circle(double startRadius);
    Circle(double startRadius, double startX, double startY);

    double getX();
    double getY();
    double getArea();
    void print();
    double getRadius();

    /**
     * @brief Sets radius to the absolute value of given
     *          newRadius - makes sure we never have a negative
     *          radius
     * @param Value from which to get magnitude of new radius
     */
    void setRadius(double newRadius);

private:
    double radius;
    double x;
    double y;
};


#endif // CIRCLE_H


