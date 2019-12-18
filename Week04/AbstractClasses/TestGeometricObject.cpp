#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
#include <iostream>
using namespace std;


bool largerThan(const GeometricObject& obj1,
                const GeometricObject& obj2)
{
    return obj1.getArea() > obj2.getArea();
}

void printObject(const GeometricObject& obj) {
    //All I know for sure is that this is a GeometricObject
    cout << obj.toString() << endl;
}

//Check if the pointer is a circle, if so, print its radius
void circleCheck(GeometricObject* objPtr) {
    Circle* cPtr = dynamic_cast<Circle*>(objPtr);
    if(cPtr != nullptr) {
        cout << " it is a circle with radius " << cPtr->getRadius();
    }
}


int main()
{

    ////--------------------Basics--------------------
    Circle c1(5);
    Rectangle r1(8, 10);

    printObject(c1);
    printObject(r1);

    if( largerThan(c1, r1) )
        cout << "The circle is larger..." << endl;
    else
        cout << "The rectangle is larger..." << endl;


    ////--------------------Collection--------------------
    //Make some objects on heap and store pointers to them...
//    GeometricObject* objects[4] = {nullptr};
//    objects[0] = new Circle(5, "Red", true);
//    objects[1] = new Rectangle(5, 2, "Blue", true);
//    objects[2] = new Rectangle(3, 4, "Purple", false);
//    objects[3] = new Circle(8, "Orange", false);

//    for(int i = 0; i < 4; i++) {
//        cout << "Checking for circles... " << i << "...";

//        circleCheck(objects[i]);

//        cout << endl;
//    }


//    //Don't really need to clean up since we are exiting, but should do:
//    for(int i = 0; i < 4; i++)
//        delete objects[i];
}

