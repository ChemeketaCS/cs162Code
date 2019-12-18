/**
  * Consumer of Circle class - uses it to do work
  */

//Needs to know about standard io library
// <name> = standard library
#include <iostream>

//Needs to know Circle class exists
// "name" = your header file
#include "Circle.h"

using namespace std;


int main()
{
    Circle c1;
    c1.setRadius(12);

    cout << "Area of circle with radius 12: " << c1.getArea() << endl;
    return 0;
}




