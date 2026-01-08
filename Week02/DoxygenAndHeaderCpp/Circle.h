/**
 * @file Circle.h
 * @author your name
 * @brief Header file for Circle class
 *
 */

#ifndef CIRCLE_H
#define CIRCLE_H

// Must include string so that the compiler knows what string is in this file
#include <string>
// Do not want to use namespace std in header files
// so we will use std::string when needed

/**
 * @brief The Circle class represents a circle on the Cartesian plane
 */
class Circle {
public:
  /**
   * @brief Creates a circle with radius 2 centered at origin
   */
  Circle();

  /**
   * @brief Creates a circle centered at origin with given radius
   * @param radius radius for the circle
   */
  Circle(double radius);

  /**
   * @brief Creates a circle with indicated radius and center
   * @param radius radius for the circle
   * @param xLocation x location of center of circle
   * @param yLocation y location of center of circle
   */
  Circle(double radius, double xLocation, double yLocation);

  /**
   * @brief Calculates and returns area of the circle
   * @return area
   */
  double getArea();

  /**
   * @brief Creates a string representation of the Circle
   * @return String formatted like: "Circle with radius: 1 area: 3.14159"
   *
   */
  std::string toString();

  /**
   * @brief Returns radius of circle
   * @return radius in cm
   */
  double getRadius();

  /**
   * @brief Changes radius of the circle
   * @param newRadius New value (in cm) to set as radius
   */
  void setRadius(double newRadius);

private:
  double m_radius; /// radius of circle in cm
  double m_x;      /// x location of center
  double m_y;      /// y location of center
};

#endif // CIRCLE_H
