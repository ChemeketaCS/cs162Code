#include <iostream>
#include <sstream>

using namespace std;

class Circle
{
public:
  double getX()
  {
    return m_x;
  }

  double getY()
  {
    return m_y;
  }

  double getRadius()
  {
    return m_radius;
  }

  void setRadius(double newRadius)
  {
    // Ensure radius is never negative
    m_radius = abs(newRadius);
  }

  void setX(double newX)
  {
    m_x = newX;
  }

  void setY(double newY)
  {
    m_y = newY;
  }

  string toString()
  {
    stringstream outStream;
    outStream << "Circle with ";
    outStream << "  radius: " << m_radius;
    outStream << "  centered at " << m_x << "," << m_y;
    return outStream.str();
  }

private:
  double m_radius;
  double m_x;
  double m_y;
};

int main() {
  Circle c1;
  // c1.setRadius(5.0);
  // c1.setX(2.0);
  // c1.setY(3.0);
  cout << c1.toString() << endl;
}