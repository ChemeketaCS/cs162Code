#include "GeometricObject.h"

#include <sstream>
#include <iostream>


GeometricObject::GeometricObject()
{
    cout << "Making a geometric object with no arguments..." << endl;
    color = "white";
    filled = false;
}

GeometricObject::GeometricObject(const string& color, bool filled)
{
    cout << "Making a geometric object with 2 arguments..." << endl;
    this->color = color;
    this->filled = filled;
}

GeometricObject::~GeometricObject()
{
    cout << "Destroying a geometric object..." << endl;
}

string GeometricObject::getColor() const
{
    return color;
}

void GeometricObject::setColor(const string& color)
{
    this->color = color;
}

bool GeometricObject::isFilled() const
{
    return filled;
}

//void GeometricObject::setFilled(bool filled)
//{
//    this->filled = filled;
//}

string GeometricObject::toString() const
{
    stringstream descriptor;
    descriptor << "Geometric object" << endl
               << " -color: " << getColor() << endl
               << " -filled: " << (isFilled() ? "true" : "false");

    return descriptor.str();
}
