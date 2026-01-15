#include <iostream>
#include <string>

#include "GeometricObject.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

void checkObject(GeometricObject& g) {
    string data = g.toString();
    cout << data << endl;
    cout << "Area: " << g.getArea() << endl;
}

int main() {
    // // Cannot create a GeometricObject directly
    // GeometricObject g("black");
    
    Rectangle rect(3.0, 4.0, "red");
    Circle circ(5.0, "blue");

    checkObject(rect);
    checkObject(circ);
}