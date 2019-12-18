#include "Location.h"

Location::Location()
    : x(0), y(0)
{

}

Location::Location(int xLoc, int yLoc)
    : x(xLoc), y(yLoc)
{

}


int Location::getX() const {
    return x;
}

int Location::getY() const {
    return y;
}
