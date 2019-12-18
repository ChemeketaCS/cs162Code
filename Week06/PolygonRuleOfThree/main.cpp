#include <iostream>

#include "Point.h"

#include "Polygon.h"

using namespace std;



void foo() {
    Polygon myTriangle(3);
    myTriangle.setVertex(0, Point(0, 0));
    myTriangle.setVertex(1, Point(3, 3));
    myTriangle.setVertex(2, Point(6, 0));

    Polygon tri2(myTriangle);
    tri2.setVertex(0, Point(3,2));

}

int main()
{
    foo();

    //Make a rectangle and set up vertices
    Polygon myRect(4);
    myRect.setVertex(0, Point(0, 0));
    myRect.setVertex(1, Point(5, 0));
    myRect.setVertex(2, Point(5, 2));
    myRect.setVertex(3, Point(0, 2));

    return 0;
}

