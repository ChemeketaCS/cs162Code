#include <cmath>
#include <format>
#include <iostream>
#include <string>
using namespace std;

// A point class with const used in the member function
class Point {
public:
  // Construct a point
  Point(double x, double y) {
    m_x = x;
    m_y = y;
    cout << "Point created at (" << m_x << ", " << m_y << ")\n";
  }

  // Copy constructor
  Point(const Point& other) {
    m_x = other.m_x;
    m_y = other.m_y;
    cout << "Point copied at (" << m_x << ", " << m_y << ")\n";
  }

  double getX() {
    return m_x;
  }

  double getY() {
    return m_y;
  }

  void setX(double x) {
    m_x = x;
  }

  void setY(double y) {
    m_y = y;
  }

  void shift(double dx, double dy) {
    setX(getX() + dx);
    setY(getY() + dy);
  }

  string toString() {
    return format("({}, {})", getX(), getY());
  }

private:
  double m_x, m_y;
};

double distanceBetween(const Point& a, const Point& b) {
  double xdiff = b.getX() - a.getX();
  double ydiff = b.getY() - a.getY();
  double distance = sqrt(xdiff * xdiff + ydiff * ydiff);
  return distance;
}

int main() {
  Point p1(0.0, 0.0);
  Point p2(6.0, 8.0);
  double distance = distanceBetween(p1, p2);
  cout << format("Distance between {} and {} is {}\n", p1.toString(),
                 p2.toString(), distance);
}