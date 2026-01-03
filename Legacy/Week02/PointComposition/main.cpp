#include <cmath>
#include <iostream>

#include "Circle.h"
#include "Cylinder.h"
#include "Point.h"

using namespace std;

int main() {
  Point p1(0, 0);

  Circle c1(2, p1);   // make circle centered at p1 with radius 2
  Circle c2(5, 3, 1); // make circle centered at 3, 1

  // make circle centered at anonymous point 10, 12
  Circle c3(1, Point(10, 12));

  cout << "c1:" << endl;
  c1.print();
  cout << "c2:" << endl;
  c2.print();
  cout << "c3:" << endl;
  c3.print();

  cout << "------------------------------" << endl;

  if (c1.intersects(c2))
    cout << "c1 intersects c2" << endl;

  if (c1.intersects(c3))
    cout << "c1 intersects c3" << endl;

  //---------------------------------------------------
  // make a cylinder with c1 as its base:
  cout << "------------------------------" << endl;
  Cylinder myCyl(c1, 5);
  myCyl.print();
  cout << "  -Surface area is " << myCyl.getSurfaceArea() << endl;

  // Get x location of center of base of myCyl:
  double xLoc = myCyl.getBase().getCenter().getX();

  // Long way...
  // Get circle that is base
  Circle cylidersBase = myCyl.getBase();
  // Get point that is center of that circle
  Point circlesCenter = cylidersBase.getCenter();
  // Get y location of Point
  double yLoc = circlesCenter.getY();

  return 0;
}
