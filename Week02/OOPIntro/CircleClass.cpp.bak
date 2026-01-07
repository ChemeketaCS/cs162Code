#include <iostream>

using namespace std;

class Circle {
public:
  // BEHAVIORS - member functions
  double getArea() {
    double area = m_radius * m_radius * numbers::pi;
    return area;
  }

  void setRadius(double newRadius) {
    m_radius = newRadius;
  }

  double getRadius() {
    return m_radius;
  }

private:
  // STATE - variables
  double m_radius;
};

int main() {
  Circle c1;
  c1.setRadius(10);
  cout << "c1's radius is " << c1.getRadius() << endl;

  Circle c2;
  c2.setRadius(5);
  cout << "c2's radius is " << c2.getRadius() << endl;
  double area = c2.getArea();
  cout << "c2's area is " << area << endl;
}
