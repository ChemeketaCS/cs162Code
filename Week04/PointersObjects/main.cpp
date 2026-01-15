#include <iostream>
using namespace std;

#include <iostream>

#include "Point.h"

using namespace std;

int main() {
    Point p1(3.0, 4.0);
    Point* myPointer = &p1;

    cout << *myPointer.getX() << endl;  //problem...
    
    cout << myPointer->getX() << endl;    //correct
    cout << (*myPointer).getX() << endl;  //also correct

    //Access other members:
    double yLocation = myPointer->getY();
    cout << yLocation << endl;

    cout << "myPointer points at the Point: " << myPointer->toString() << endl;
}