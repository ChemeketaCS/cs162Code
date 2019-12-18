#include <iostream>
#include <cmath>

#include "Circle.h"
#include "Point.h"

using namespace std;


int main()
{
    //Any random code you want to test out...
    //Don't need anything specific here...
    Point p1(0, 0);
    Circle c1(2, p1);    //make circle centered at p1 with radius 2

    c1.print();
    cout << endl;

    return 0;
}




