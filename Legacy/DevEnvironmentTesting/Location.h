#ifndef LOCATION_H
#define LOCATION_H

// Minimal class for point in 2-D Cartesian grid
class Location {
private:
  int x;
  int y;

public:
  int getX() const;
  int getY() const;
  Location();
  Location(int xLoc, int yLoc);
};

#endif // LOCATION_H
