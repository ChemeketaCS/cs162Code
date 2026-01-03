#include <cmath>
#include <iostream>

#include "Circle.h"

using namespace std;

// this version has a bug...
//  change c to be passed by reference to fix it
void scaleCircle(Circle c, double scaleFactor) {
  double newRadius = c.getRadius() * scaleFactor;
  c.setRadius(newRadius);
}

// This version is inefficient - should pass a const reference
void printArea(Circle c) {
  cout << "Area is " << c.getArea() << endl;
}

Circle makeCircleWithArea(double area) {
  double radius = sqrt(area / 3.14);
  Circle temp(radius); // make a circle with necessary radius
  return temp;         // return the circle we made
}

int main() {
  //----------------FUNCTION STUFF---------------------
  cout << "In main, calling makeCircleWithArea" << endl;
  Circle c0 = makeCircleWithArea(100);
  c0.print();

  cout << "\nIn main, making a circle with radius of 5" << endl;
  Circle c1(5);

  cout << "\nCalling scaleCircle..." << endl;
  scaleCircle(c1, 2.0);

  cout << "Calling printArea..." << endl;
  printArea(c1);

  //----------------ARRAY STUFF---------------------
  cout << "Making an array of 5 Circles" << endl;
  Circle circleList[5];
  circleList[0].setRadius(4); // change radius of first one

  // Fill array with anonymous circles
  circleList[0] = Circle(1);
  circleList[1] = Circle(2);
  circleList[2] = Circle(3);
  circleList[3] = Circle(4);
  circleList[4] = Circle(5);

  // Make an array and initialize with anonymous circles
  Circle circleList2[5] = {Circle(1), Circle(2), Circle(3), Circle(4),
                           Circle(5)};

  for (int i = 0; i < 5; i++) {
    // access the ith circle... then ask it to print itself
    circleList[i].print();
  }

  return 0;
}
