#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

class Circle: public GeometricObject {
public:
  Circle();
  Circle(double);
  Circle(double radius, const string& color, bool filled);
  double getRadius() const;
  void setRadius(double);

  // These three are overriding GeometricObject functions
  virtual double getArea() const override;
  virtual double getPerimeter() const override;
  virtual string toString() const override;

private:
  double radius;
};

#endif
