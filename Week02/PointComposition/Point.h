#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(double startX, double startY);

    double getX() const;
    double getY() const;
    void setX(double newX);
    void setY(double newY);
    void translate(double xShift, double yShift);
    bool isSameAs(const Point& other) const;
    double distanceTo(const Point& other) const;

    void print() const;

private:
    double x;
    double y;
};

#endif // POINT_H
