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

TEST_CASE("Circle/No-arg constructor test") {
  Circle c1;
  CHECK(c1.getCenter().getX() == Approx(0));
  CHECK(c1.getCenter().getY() == Approx(0));
  CHECK(c1.getRadius() == Approx(1));
}

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
  Circle c1;
  c1.setRadius(5);
  CHECK(c1.getCircumference() == Approx(31.4));
}

TEST_CASE("Circle/setRadius") {
  Circle c1;
  c1.setRadius(4);
  CHECK(c1.getRadius() == Approx(4));
}

TEST_CASE("Circle/setRadius with negative") {
  Circle c1;
  c1.setRadius(-2); // should be converted to +2
  CHECK(c1.getRadius() == Approx(2));
}

TEST_CASE("Circle/moveTo") {
  Circle c1;
  Point p1(-3, 2);
  c1.moveTo(p1);
  CHECK(c1.getCenter().getX() == Approx(-3));
  CHECK(c1.getCenter().getY() == Approx(2));
}

TEST_CASE("Circle/intersect") {
  Circle c1(5, 0, 0); // radius 5 at 0,0
  Circle c2(3, 4, 0); // radius 3 at 4,0
  CHECK(c1.intersects(c2) == true);
}

TEST_CASE("Circle/intersect just touching") {
  Circle c1(3, 0, 0); // radius 3 at 0,0
  Circle c2(2, 5, 0); // radius 2 at 5,0
  CHECK(c1.intersects(c2) == true);
}

TEST_CASE("Circle/intersect non-touching") {
  Circle c1(3, 0, 0); // radius 3 at 0,0
  Circle c2(2, 6, 0); // radius 2 at 6,0
  CHECK(c1.intersects(c2) == false);
}
