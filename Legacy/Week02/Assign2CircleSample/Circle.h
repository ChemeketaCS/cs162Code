/**
 * @author Andrew Scholer
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle {
private:
  double radius;
  Point center;

public:
  /**
   * @brief Circle Make a circle with radius 2, at 0,0
   */
  Circle();

  /**
   * @brief Circle Make a circle with given radius, at 0,0
   * @param startRadius Initial radius of circle - negative values
   *          will be converted to positive
   */
  Circle(double startRadius);

  /**
   * @brief Circle Make a circle with given radius and starting coordinates
   * @param startRadius Initial radius of circle - negative values
   *          will be converted to positive
   * @param startX Initial x location of center
   * @param startY Initial y location of center
   */
  Circle(double startRadius, double startX, double startY);

  /**
   * @brief Circle Make a circle with given radius centered at the given point
   * @param startRadius Initial radius of circle - negative values
   *          will be converted to positive
   * @param centerPoint Point to use as center of circle
   */
  Circle(double startRadius, const Point& centerPoint);

  /**
   * @brief getX Return x coordinate of center
   * @return x location of center
   */
  double getX() const;

  /**
   * @brief getY Return y coordinate of center
   * @return y location of center
   */
  double getY() const;

  /**
   * @brief getCenter Return Point representing center of circle
   * @return Point with coordinates of center
   */
  Point getCenter() const;

  /**
   * @brief getRadius Return radius of circle
   * @return radius
   */
  double getRadius() const;

  /**
   * @brief setRadius Modifies radius of circle to indicated value
   * @param newRadius New value for radius - negative values will be made
   * positive
   */
  void setRadius(double newRadius);

  /**
   * @brief getArea Returns area of the circle
   * @return area
   */
  double getArea() const;

  /**
   * @brief getCircumference Returns circumference of the circle
   * @return circumference
   */
  double getCircumference() const;

  /**
   * @brief moveTo Shifts center of circle to indicated location
   * @param p Point to move circle to
   */
  void moveTo(const Point& p);

  /**
   * @brief intersects Determines if a circle intersects another circle
   *                   Touching is considered intersecting
   * @param other Circle to check
   * @return True if circles intersect, otherwise false
   */
  bool intersects(const Circle& other);

  /**
   * @brief print Dumps info to cout
   */
  void print() const;
};

#endif // CIRCLE_H
