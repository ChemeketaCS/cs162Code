/**
  * Defines circle class, does not implement
  */

//Header guard avoid multiple copies of code being included
// in any one .cpp file
#ifndef CIRCLE_H
#define CIRCLE_H

//Must include string so that the compiler knows what string is in this file
#include <string>

////Utilizing "using" in a .h is considered poor practice as it forces all
////files that include the .h to be use the namespace
//using namespace std;

class Circle {
public:
    Circle();
    Circle(double startRadius);
    Circle(double startRadius, double startX, double startY);

    double getArea();
    //Use std::string here since we are not using the entire std namespace
    std::string toString();
    double getRadius();
    void setRadius(double newRadius);

private:
    double radius;
    double x;
    double y;
};


#endif // CIRCLE_H


