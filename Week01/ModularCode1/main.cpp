/**
  * Circle example with function implementations
  * separated from declarations
  **/


#include <iostream>
#include <cmath>

using namespace std;

class Circle {
public:
    //DECLARATION
    Circle();
    Circle(double startRadius);
    Circle(double startRadius, double startX, double startY);

    double getArea();
    void print();
    double getRadius();
    void setRadius(double newRadius);

private:
    double radius;
    double x;
    double y;
};


int main()
{
    Circle c1;
    c1.setRadius(12);

    cout << c1.getRadius();
    return 0;
}




//IMPLEMENTATION
Circle::Circle() {
    radius = 2;
    x = 0;
    y = 0;
}

Circle::Circle(double theRadius) {
    radius = theRadius;
    x = 0;
    y = 0;
}

Circle::Circle(double theRadius, double startX, double startY) {
    radius = theRadius;
    x = startX;
    y = startY;
}

double Circle::getArea() {
    return radius * radius * 3.14;
}

void Circle::print() {
    cout << "Circle with a radius of " << radius << endl
         << "    centered at " << x << ", " << y;
}

double Circle::getRadius() { return radius; }

void Circle::setRadius(double r) {
    radius = abs(r);
}


