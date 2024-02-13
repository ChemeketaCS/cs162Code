#include "DerivedCircle.h"
#include "DerivedRectangle.h"
#include "GeometricObject.h"
#include <iostream>
using namespace std;

// Paint any object black
void paintBlack(GeometricObject& obj) {
  obj.setColor("None more black");
}

int main() {
  GeometricObject shape;
  shape.setColor("red");
  shape.setFilled(true);
  cout << shape.toString() << endl;

  Circle circle(5);
  circle.setColor("black");
  circle.setFilled(false);
  circle.setRadius(10);
  cout << circle.toString() << endl;

  Rectangle rectangle(2, 3);
  rectangle.setColor("orange");
  rectangle.setFilled(true);
  cout << rectangle.toString() << endl;

  // Circle and Rectangle qualify as GeometricObjects:
  paintBlack(shape);
  paintBlack(circle);
  paintBlack(rectangle);
  cout << "Shape    : " << shape.getColor() << endl;
  cout << "Circle   : " << circle.getColor() << endl;
  cout << "Rectangle: " << rectangle.getColor() << endl;

  return 0;
}
