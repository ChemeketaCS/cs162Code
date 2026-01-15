#include <iostream>

#include "Point.h"
using namespace std;

class Circle {
public:
    Circle(double radius, Point* p) {
        m_radius = radius;
        m_center = p;
    }

    double getX() const {
        return m_center->getX();
    }

    double getY() const {
        return m_center->getY();
    }

    double getRadius() const {
        return m_radius;
    }

private:
    double m_radius;
    Point* m_center;
};

int main() {
    Point p1(3.2, 2.0);

    // Create a Circle object with a radius of 5.0 and center at point p1
    Circle c1(5.0, &p1);

    // Create a Circle object with a radius of 3.0 and center at point p1
    Circle c2(3.0, &p1);

    cout << "Circle c1 at " << c1.getX() << "," << c1.getY() << endl;
    cout << "Circle c2 at " << c2.getX() << "," << c2.getY() << endl;

    p1.shift(2.0, 1.0); // Shift the point p1

    // After shifting, both circles should reflect the new center point
    cout << "Circle c1 at " << c1.getX() << "," << c1.getY() << endl;
    cout << "Circle c2 at " << c2.getX() << "," << c2.getY() << endl;
}
