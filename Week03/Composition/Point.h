#ifndef POINT_H
#define POINT_H

#include <string>

/**
 * @brief Represents a point in a 2D Cartesian coordinate system.
 */
class Point {
public:
    double getX() const;
    /**
     * @brief Constructs a Point with the specified coordinates.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(double x, double y);

    /**
     * @brief Constructs a Point at the origin (0, 0).
     */
    Point();

    /**
     * @brief Gets the x-coordinate of the point.
     * @return The x-coordinate.
     */
    double getX() const;

    /**
     * @brief Gets the y-coordinate of the point.
     * @return The y-coordinate.
     */
    double getY() const;

    /**
     * @brief Sets the x-coordinate of the point.
     * @param x The new x-coordinate.
     */
    void setX(double x);

    /**
     * @brief Sets the y-coordinate of the point.
     * @param y The new y-coordinate.
     */
    void setY(double y);

    /**
     * @brief Shifts the point by the specified offsets.
     * @param dx The offset to add to the x-coordinate.
     * @param dy The offset to add to the y-coordinate.
     */
    void shift(double dx, double dy);

    /**
     * @brief Converts the point to a string representation.
     * @return A string representing the point in the format "(x, y)".
     */
    std::string toString() const;

    /**
     * @brief Calculates the distance to another point.
     * @param other The other point.
     * @return The Euclidean distance to the other point.
     */
    double distanceTo(const Point& other) const;

private:
    double m_x;
    double m_y;
};

#endif // POINT_H