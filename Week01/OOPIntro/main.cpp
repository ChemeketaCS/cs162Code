#include <iostream>

using namespace std;

class Circle {
public:
    //STATE - variables
    double radius;

    //BEHAVIORS - functions
    double getArea() {
        return radius * radius * 3.14;
    }

    string toString() {
        double myArea = getArea();

        string output = "Circle with";
        output += " radius: " + to_string(radius);
        output += " area: " + to_string(myArea);
        return output;
    }
};

int main()
{
    Circle c1;
    c1.radius = 5.5;

    double area = c1.getArea();
    cout << "c1's area is " << area << endl;

    Circle c2;
    c2.radius = 12;
    cout << "c2: " << c2.toString() << endl;
}

