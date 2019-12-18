#include "DerivedRectangle.h"

#include <sstream>
#include <iostream>

// Construct a default rectangle object
Rectangle::Rectangle()
    : GeometricObject("Blue", true)
{
    cout << "Making a rectangle..." << endl;
    width = 1;
    height = 1;
}

// Construct a rectangle object with specified width and height
Rectangle::Rectangle(double width, double height)
    : GeometricObject("Blue", true)
{
    cout << "Making a rectangle..." << endl;
    setWidth(width);
    setHeight(height);
}

Rectangle::Rectangle(double width, double height, const string& color, bool filled)
    : GeometricObject(color, filled)
{
    cout << "Making a rectangle..." << endl;
    setWidth(width);
    setHeight(height);
}

// Destruct a rectangle object
Rectangle::~Rectangle()
{
    cout << "Destroying a rectangle..." << endl;
}

// Return the width of this rectangle
double Rectangle::getWidth() const
{
    return width;
}

// Set a new radius
void Rectangle::setWidth(double width)
{
    this->width = (width >= 0) ? width : 0;
}

// Return the height of this rectangle
double Rectangle::getHeight() const
{
    return height;
}

// Set a new height
void Rectangle::setHeight(double height)
{
    this->height = (height >= 0) ? height : 0;
}

// Return the area of this rectangle
double Rectangle::getArea() const
{
    return width * height;
}

// Return the perimeter of this rectangle
double Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}

// Redefine the toString function, to be covered in Section 15.5
string Rectangle::toString() const
{
    stringstream descriptor;
    descriptor << "Rectangle object" << endl
               << "   uses: " << GeometricObject::toString() << endl
               << " -width: " << getWidth() << endl
               << " -height: " << getHeight() << endl
               << " -area: " << getArea() << endl
               << " -perimeter: " << getPerimeter();

    return descriptor.str();
}

