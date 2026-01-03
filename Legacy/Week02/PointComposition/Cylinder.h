#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"

class Cylinder {
public:
  Cylinder(double radius, double theHeight);
  Cylinder(double radius, double theHeight, double x, double y);
  Cylinder(const Circle& theBase, double theHeight);

  double getSurfaceArea() const;
  double getVolume() const;

  Circle getBase() const;

  void print() const;

private:
  Circle base;
  double height;
};

#endif // CYLINDER_H
