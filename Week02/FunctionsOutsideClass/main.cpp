#include <iostream>
#include <sstream>

using namespace std;

class Circle {
public:
  Circle() {
    m_radius = 1;
  }

  Circle(double radius) {
    m_radius = radius;
  }

  double getArea() {
    double area = m_radius * m_radius * numbers::pi;
    return area;
  }

private:
  double m_radius;
};

//Non object function declaration
int getNumber();

//Non object function definition
int getNumber() {
  return 42;
}

int main() {
  Circle c1(5);

  int x = getNumber();
}
