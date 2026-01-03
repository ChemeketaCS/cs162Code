#include <cmath>
#include <iostream>

#include "Circle.h"

using namespace std;

int main() {
  cout << "Enter the radius of a circle: ";
  int r;
  cin >> r;

  Circle c1(r);
  cout << "Area is: " << c1.getArea() << endl;

  return 0;
}
