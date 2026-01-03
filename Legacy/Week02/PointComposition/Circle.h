#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle {
private:
  double radius;
  Point center;

public:
  Circle();
  Circle(double startRadius);
  Circle(double startRadius, double startX, double startY);
  // Construct using radius and a Point:
  Circle(double startRadius, const Point& centerPoint);

  double getX() const;
  double getY() const;
  Point getCenter() const;
  double getRadius() const;
  void setRadius(double newRadius);

  double getArea() const;
  double getCircumference() const;

  void moveTo(const Point& p);
  bool intersects(const Circle& other) const;
  void print() const;
};

#endif // CIRCLE_H
