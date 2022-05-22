#include <iostream>
#include <sstream>

using namespace std;

class Circle {
public:
    //STATE/PROPERTIES
    double radius;
    double x;
    double y;

    //CONSTRUCTORS
    Circle() {
        radius = 2;
        x = 0;
        y = 0;
    }

    Circle(double theRadius) {
        radius = theRadius;
        x = 0;
        y = 0;
    }

    Circle(double theRadius, double xLoc, double yLoc) {
        radius = theRadius;
        x = xLoc;
        y = yLoc;
    }

    //BEHAVIORS
    double getArea() {
        return radius * radius * 3.14;
    }

    string toString() {
        stringstream outStream;
        outStream << "Circle with ";
        outStream << "  radius: " << radius;
        outStream << "  area: " << getArea();
        outStream << "  centered at " << x << "," << y;
        return outStream.str();
    }

};

int main()
{
    Circle c1;
    cout << c1.toString() << endl;

    //can directly change public members:
    c1.radius = 10;
    cout << c1.toString() << endl;

    Circle c2(4, 12, 3);
    cout << c2.toString() << endl;
}

