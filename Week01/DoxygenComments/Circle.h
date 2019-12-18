/**
  * @author Andrew Scholer
  */

#ifndef CIRCLE_H
#define CIRCLE_H

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
     * @param startRadius radius for the circle
     */
    Circle(double startRadius);

    /**
     * @brief Creates a circle with indicated radius and center
     * @param startRadius radius for the circle
     * @param startX x location of center of circle
     * @param startY y location of center of circle
     */
    Circle(double startRadius, double startX, double startY);


    /**
     * @brief Calculates and returns area of the circle
     * @return area
     */
    double getArea();


    /**
     * @brief Dumps info to console
     *
     */
    void print();


    /**
     * @brief Returns radius of circle
     * @return radius
     */
    double getRadius();


    /**
     * @brief Changes radius of the circle
     * @param newRadius New value to set as radius
     */
    void setRadius(double newRadius);

private:
    double radius;  ///radius of circle
    double x;       ///x loctation of center
    double y;       ///y location of cetner
};


#endif // CIRCLE_H


