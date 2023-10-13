#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
#include <iostream>
using namespace std;



void printObject(const GeometricObject& obj) {
    //All I know for sure is that this is a GeometricObject
    cout << obj.toString() << endl;
}


int main()
{
    GeometricObject shape;
    Circle c1;
    Rectangle r1;

    cout << shape.toString();
    cout << c1.toString();
    cout << r1.toString();

    printObject(shape);
    printObject(c1);
    printObject(r1);

    ////--------------------Casting & Pointers--------------------
//    Circle c2(5);
//    GeometricObject* mysteryObject = &c2;
//    cout << mysteryObject->toString() << endl;

//    Rectangle* myRectPtr = dynamic_cast<Rectangle*>(mysteryObject);
//    if( myRectPtr != nullptr ) {
//        cout << myRectPtr->getWidth() << endl;
//        cout << myRectPtr->getHeight() << endl;
//    } else {
//        cout << "You goof" << endl;
//    }

}

