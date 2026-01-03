#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(): x(0), y(0) {
}

Location::Location(int xLoc, int yLoc): x(xLoc), y(yLoc) {
}

int Location::getX() const {
  cout << "x =" << x << endl;
  return x;
}

int Location::getY() const {
  return y;
}
