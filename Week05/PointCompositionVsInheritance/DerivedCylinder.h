#ifndef DERIVEDCYLINDER_H
#define DERIVEDCYLINDER_H

#include "Circle.h"

class DerivedCylinder: public Circle {
public:
  DerivedCylinder(double radius, double theHeight);
  DerivedCylinder(double radius, double theHeight, double x, double y);
  DerivedCylinder(const Circle& theBase, double theHeight);

  double getSurfaceArea() const;
  double getVolume() const;

  Circle getBase() const;

  void print() const;

private:
  double height;
};

#endif // DERIVEDCYLINDER_H
