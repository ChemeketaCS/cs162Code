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
     * @brief Constructs a Circle with a specified radius and a default center at (0, 0).
     * @param radius The radius of the circle.
     */
    Circle(double radius);

    /**
     * @brief Constructs a Circle with a specified radius and center point.
     * @param radius The radius of the circle.
     * @param p The center point of the circle.
     */
    Circle(double radius, const Point& p);

    /**
     * @brief Gets the radius of the circle.
     * @return The radius of the circle.
     */
    double getRadius() const;

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
     * @brief Gets the center point of the circle.
     * @return The center point of the circle as a Point object.
     */
    Point getCenter() const;

    /**
     * @brief Calculates the area of the circle.
     * @return The area of the circle.
     */
    double getArea() const;

    /**
     * @brief Calculates the circumference of the circle.
     * @return The circumference of the circle.
     */
    double getCircumference() const;

    /**
     * @brief Sets the radius of the circle.
     * @param radius The new radius of the circle.
     */
    void setRadius(double radius);

    /**
     * @brief Sets the x-coordinate of the circle's center.
     * @param x The new x-coordinate of the circle's center.
     */
    void setX(double x);

    /**
     * @brief Sets the y-coordinate of the circle's center.
     * @param y The new y-coordinate of the circle's center.
     */
    void setY(double y);

    /**
     * @brief Shifts the circle's center by the specified offsets.
     * @param dx The offset to add to the x-coordinate of the center.
     * @param dy The offset to add to the y-coordinate of the center.
     */
    void shift(double dx, double dy);

    /**
     * @brief Converts the circle's properties to a string representation.
     * @return A string representation of the circle.
     */
    std::string toString() const;

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