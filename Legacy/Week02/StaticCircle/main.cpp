#include <iostream>

#include "Circle.h"

using namespace std;

int main() {
  cout << "Using " << Circle::PI << " for PI" << endl;

  cout << "Number of circle objects created: " << Circle::getNumberOfObjects()
       << endl;

  Circle circle1;
  cout << "The area of the circle of radius " << circle1.getRadius() << " is "
       << circle1.getArea() << endl;
  cout << "Number of circle objects created: " << Circle::getNumberOfObjects()
       << endl
       << endl;

  Circle circle2(5.0);
  cout << "The area of the circle of radius " << circle2.getRadius() << " is "
       << circle2.getArea() << endl;
  cout << "Number of circle objects created: " << Circle::getNumberOfObjects()
       << endl
       << endl;

  cout << "Making 4 more Circles..." << endl;
  for (int i = 0; i < 4; i++) {
    Circle(); // make an anonymous circle
  }

  cout << "circle1.getNumberOfObjects() returns "
       << circle1.getNumberOfObjects() << endl
       << endl;
  cout << "circle2.getNumberOfObjects() returns "
       << circle2.getNumberOfObjects() << endl
       << endl;

  return 0;
}
