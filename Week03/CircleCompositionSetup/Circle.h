#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

/**
 * @brief Represents a circle in a 2D Cartesian coordinate system.
 */
class Circle {
public:
  /**
   * @brief Constructs a Circle with a specified radius and center coordinates.
   * @param radius The radius of the circle.
   * @param x The x-coordinate of the circle's center.
   * @param y The y-coordinate of the circle's center.
   */
  Circle(double radius, double x, double y);

  /**
   * @brief Gets the x-coordinate of the circle's center.
   * @return The x-coordinate of the circle's center.
   */
  double getX() const;

  /**
   * @brief Gets the y-coordinate of the circle's center.
   * @return The y-coordinate of the circle's center.
   */
  double getY() const;

  /**
   * @brief Gets the radius of the circle.
   * @return The radius of the circle.
   */
  double getRadius() const;

  /**
   * @brief Checks if a point is inside or on the circle.
   * @param p The point to check.
   * @return true if the point is inside or on the circle, false otherwise.
   */
  bool contains(const Point& p) const;

private:
  double m_radius;
  Point m_center;
};

#endif