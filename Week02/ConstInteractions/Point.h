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

    double distanceTo(const Point& other) const;

    bool isSameAs(const Point& other) const;

    void print() const;

private:
    double x;
    double y;
};

#endif // POINT_H
