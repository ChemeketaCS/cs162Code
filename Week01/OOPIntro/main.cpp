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

};

int main()
{
    Circle c1;
    c1.radius = 5.5;

    cout << "C1 has radius: " << c1.radius
         << " and area: " << c1.getArea() << endl;

    Circle c2;
    c2.radius = 12;

    cout << "C2 has radius: " << c2.radius
         << " and area: " << c2.getArea() << endl;

    return 0;
}

