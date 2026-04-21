#include <iostream>
#include <string>
using namespace std;

namespace graphics {
  struct Point {
    string color;
    double size;
  };
}

namespace math {
  struct Point {
    double m_x;
    double m_y;
  };
}

int main() {
  graphics::Point gPoint;
  gPoint.color = "red";
  gPoint.size = 5.0;

  math::Point mPoint;
  mPoint.m_x = 15.0;
  mPoint.m_y = 25.0;

  cout << "Graphics Point: color=" << gPoint.color
       << " size=" << gPoint.size << endl;
  cout << "Math Point: x=" << mPoint.m_x
       << " y=" << mPoint.m_y << endl;
}