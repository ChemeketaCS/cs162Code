#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeometricObject.h"

class Rectangle: public GeometricObject {
public:
  Rectangle();
  Rectangle(double width, double height);
  Rectangle(double width, double height, const string& color, bool filled);
  double getWidth() const;
  void setWidth(double);
  double getHeight() const;
  void setHeight(double);

  // These three are overriding GeometricObject functions
  virtual double getArea() const override;
  virtual double getPerimeter() const override;
  virtual string toString() const override;

private:
  double width;
  double height;
};

#endif
