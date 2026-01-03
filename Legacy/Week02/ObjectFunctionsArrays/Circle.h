#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
  Circle();
  Circle(double startRadius);
  Circle(double startRadius, double startX, double startY);

  // Copy Constructor - don't worry about for now
  Circle(const Circle& other);

  double getArea() const;
  void print();
  double getRadius();
  void setRadius(double newRadius);

private:
  double radius;
  double x;
  double y;
};

#endif // CIRCLE_H
