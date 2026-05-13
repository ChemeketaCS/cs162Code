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


TEST_CASE("Circle/1-arg constructor test") {
  Circle c1(3.3);
  CHECK(c1.getCenter().getX() == Approx(0));
  CHECK(c1.getCenter().getY() == Approx(0));
  CHECK(c1.getRadius() == Approx(3.3));
}

TEST_CASE("Circle/3-arg constructor test") {
  Circle c1(3.0, 4.1, -5.2);
  CHECK(c1.getCenter().getX() == Approx(4.1));
  CHECK(c1.getCenter().getY() == Approx(-5.2));
  CHECK(c1.getRadius() == Approx(3));
}

TEST_CASE("Circle/radius, point constructor test") {
  Point p1(3, 2.5);
  Circle c1(3.0, p1);
  CHECK(c1.getCenter().getX() == Approx(3));
  CHECK(c1.getCenter().getY() == Approx(2.5));
  CHECK(c1.getRadius() == Approx(3.0));
}

TEST_CASE("Circle/getArea") {
  Circle c1(5, 0, 0);
  double area = c1.getArea();
  CHECK(area == Approx(78.5));
}

TEST_CASE("Circle/getCircumference") {
  Circle c1(1);
  c1.setRadius(5);
  CHECK(c1.getCircumference() == Approx(31.4));
}

TEST_CASE("Circle/setRadius") {
  Circle c1(1);
  c1.setRadius(4);
  CHECK(c1.getRadius() == Approx(4));
}

TEST_CASE("Circle/setRadius with negative") {
  Circle c1(1);
  c1.setRadius(-2); // should be converted to +2
  CHECK(c1.getRadius() == Approx(2));
}

TEST_CASE("Circle/moveTo") {
  Circle c1(1);
  Point p1(-3, 2);
  c1.shift(4, 2);
  CHECK(c1.getCenter().getX() == Approx(1));
  CHECK(c1.getCenter().getY() == Approx(4));
}

TEST_CASE("Circle/contains") {
  Circle c1(5, 0, 0); // radius 5 at 0,0
  Point p1(3, 2); // distance from center is < 5
  CHECK(c1.contains(p1) == true);
}

TEST_CASE("Circle/contains on edge") {
  Circle c1(5, 1, 2); // radius 5 at 1, 2
  Point p1(5, 5); // distance from center is = 5, so directly on edge
  CHECK(c1.contains(p1) == true);
}

TEST_CASE("Circle/contains outside") {
  Circle c1(3, 0, 0); // radius 3 at 0,0
  Point p1(5, 0); // distance from center is > 3
  CHECK(c1.contains(p1) == false);
}
