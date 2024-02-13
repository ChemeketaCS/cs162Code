#include "GeometricObject.h"

#include <sstream>

GeometricObject::GeometricObject() {
  color = "white";
  filled = false;
}

GeometricObject::GeometricObject(const string& color, bool filled) {
  this->color = color;
  this->filled = filled;
}

string GeometricObject::getColor() const {
  return color;
}

void GeometricObject::setColor(const string& color) {
  this->color = color;
}

bool GeometricObject::isFilled() const {
  return filled;
}

void GeometricObject::setFilled(bool filled) {
  this->filled = filled;
}

string GeometricObject::toString() const {
  stringstream descriptor;
  descriptor << "Geometric object" << endl
             << " -color: " << getColor() << endl
             << " -filled: " << (isFilled() ? "true" : "false");

  return descriptor.str();
}
