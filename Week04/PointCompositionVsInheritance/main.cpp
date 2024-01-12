#include <cmath>
#include <iostream>

#include "Circle.h"
#include "Cylinder.h"
#include "DerivedCylinder.h"
#include "Point.h"

using namespace std;

void printCircle(Circle cPtr) {
  cout << cPtr.getArea() << endl;
}

int main() {
  Point p1(0, 0);

  Circle c1(2, p1);

  Cylinder cyl1(c1, 3);
  cyl1.print();

  DerivedCylinder cyl2(c1, 3);
  cyl2.print();

  // Print a cylinder as a circle!?!?!
  printCircle(cyl2);

  return 0;
}
