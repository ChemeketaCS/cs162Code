#include <iostream>
#include <string>
using namespace std;

namespace graphics {
  struct Point {
    string color;
    double size;
  };

  struct Circle {
    string color;
    double size;
    Point center;
  };
}

// Tell compiler to bring in just Point from graphics namespace
using graphics::Point;

int main() {
  // Assumed to be graphics::Point because of using directive above
  Point gPoint;
  gPoint.color = "red";
  gPoint.size = 5.0;
  // Still need to qualify Circle since we didn't bring in all names
  graphics::Circle c;
  c.color = "blue";
  c.size = 10.0;
}