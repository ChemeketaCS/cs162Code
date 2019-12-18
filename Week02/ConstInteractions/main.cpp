#include <iostream>
#include <cmath>

#include "Circle.h"

using namespace std;

//Only works if everything done to c is const...
void printArea(const Circle& c) {
    cout << "Area is " << c.getArea() << endl;
}

int main()
{
    Circle c1;
    c1.print();

    cout << "--------Moving-------" << endl;
    Point p1(5, -2);
    c1.moveTo(p1);
    c1.print();

    Point origin(0,0);
    if(c1.contains(origin)) {
        cout << "origin is inside c1" << endl;
    } else {
        cout << "origin is NOT inside c1" << endl;
    }

    cout << "---------------------" << endl;

    Point p2(1, 1);
    Point p3(4, 5);
    double dist = p2.distanceTo(p3);

    cout << "Point p2 is " << dist
         << " away from p3" << endl;


    cout << "---------------------" << endl;

    Point p4(2, 3);
    Point p5(2, 3);
    Point p6(3, 2);

    if( p4.isSameAs(p5) )
        cout << "p4 isSameAs p5" << endl;

    if( p4.isSameAs(p6) )
        cout << "p4 isSameAs p6" << endl;



    return 0;
}




