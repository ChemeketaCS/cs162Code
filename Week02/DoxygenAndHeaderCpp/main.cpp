/**
 * @author Andrew Scholer
 * @brief Sample project featuring documentation
 */

#include <cmath>
#include <iostream>

#include "Circle.h"

using namespace std;

int main() {
  Circle c1;
  c1.setRadius(12);

  cout << c1.getRadius();
}
