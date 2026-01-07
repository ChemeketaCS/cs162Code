#include <iostream>
#include <sstream>

using namespace std;

class Circle
{
public:
  //CONSTRUCTORS
  Circle()
  {
    m_radius = 1;
    m_x = 0;
    m_y = 0;
  }

  // ACCESSORS
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

  // MUTATORS
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

  void scale(double scaleFactor)
  {
    m_radius = m_radius * scaleFactor;
  }

  void translate(double deltaX, double deltaY)
  {
    m_x += deltaX;
    m_y += deltaY;
  }

  // OTHER METHODS
  double getArea()
  {
    double area = m_radius * m_radius * numbers::pi;
    return area;
  }

  double getCircumference()
  {
    double circumference = 2 * m_radius * numbers::pi;
    return circumference;
  }

  string toString()
  {
    stringstream outStream;
    outStream << "Circle with ";
    outStream << "  radius: " << m_radius;
    outStream << "  area: " << getArea();
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
  cout << c1.toString() << endl;

  cout << "Changing radius to 10 and translating by (2, 4)..." << endl;
  c1.setRadius(10);
  c1.translate(2, 4);
  cout << c1.toString() << endl;

  cout << "Get the circumference: " << c1.getCircumference() << endl;

  cout << "Scaling by a factor of 0.5..." << endl;
  c1.scale(0.5);
  cout << c1.toString() << endl;
}