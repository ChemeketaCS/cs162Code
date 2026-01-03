#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"

class Polygon {
public:
  Polygon(int numSides);

  // Copy constructor that does deep copy
  Polygon(const Polygon& other);

  // Assignment operator that does deep copy
  Polygon& operator=(const Polygon& other);

  // Destructor
  ~Polygon();

  void setVertex(int index, const Point& newPoint);

private:
  int sides;
  Point* vertices; // Pointer to array containing vertices
};

#endif // POLYGON_H
