#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
  Circle();
  Circle(double radius);
  Circle(double radius, double xLocation, double yLocation);

  double getX();
  double getY();
  double getArea();
  void print();
  double getRadius();

  /**
   * @brief Sets radius to the absolute value of given
   *          newRadius - makes sure we never have a negative
   *          radius
   * @param Value from which to get magnitude of new radius
   */
  void setRadius(double newRadius);

private:
  double m_radius;
  double m_x;
  double m_y;
};

#endif // CIRCLE_H
