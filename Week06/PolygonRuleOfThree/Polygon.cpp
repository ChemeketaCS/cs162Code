#include "Polygon.h"

Polygon::Polygon(int numSides) {
  sides = numSides;
  // allocate storage for right number of Points
  vertices = new Point[numSides];
}

Polygon::Polygon(const Polygon& other) {
  // Copy regular variables
  sides = other.sides;
  // Allocate own storage for dynamic array
  vertices = new Point[sides];
  // Copy values over from original to our memory
  for (int i = 0; i < sides; i++) {
    vertices[i] = other.vertices[i];
  }
}

Polygon& Polygon::operator=(const Polygon& other) {
  // Avoid self assignment
  if (this != &other) {
    // Clear old storage
    delete[] vertices;

    // Copy regular variables
    sides = other.sides;
    // Allocate own storage for dynamic array
    vertices = new Point[sides];
    // Copy values over from original to our memory
    for (int i = 0; i < sides; i++) {
      vertices[i] = other.vertices[i];
    }
  }
  return *this;
}

Polygon::~Polygon() {
  // delete storage used for Points
  delete[] vertices;
}

void Polygon::setVertex(int index, const Point& newPoint) {
  vertices[index] = newPoint;
}
