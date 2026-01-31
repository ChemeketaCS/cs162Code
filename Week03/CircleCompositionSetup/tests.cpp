// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------

// Include your .h files
#include "Circle.h"

#include <cmath>
using namespace std;

TEST_CASE("Circle constructor") {
  Circle c1(5.0, 2, 1);
  CHECK(c1.getRadius() == Approx(5.0));
  CHECK(c1.getX() == Approx(2.0));
  CHECK(c1.getY() == Approx(1.0));
}

TEST_CASE("Circle contains") {
  Circle c1(5.0, 2, 1);
  Point p1(3.2, 2.0);
  CHECK(c1.contains(p1) == true);                 // Point is inside the circle
  CHECK(c1.contains(Point(7, 1)) == true);        // Point is on the circle
  CHECK(c1.contains(Point(12.0, 12.0)) == false); // Point is outside the circle
}