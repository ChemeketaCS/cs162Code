#include <cmath>
#include <iostream>
#include <string>
#include <format>
using namespace std;

class Point {
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }

    double getX() const {
        return m_x;
    }

    double getY() const {
        return m_y;
    }

    double distanceTo(const Point& other) const {
        double xdiff = other.m_x - m_x;
        double ydiff = other.m_y - m_y;
        double distance = sqrt(xdiff * xdiff + ydiff * ydiff);
        return distance;
    }

    bool isSameAs(const Point& other) const {
        return (m_x == other.m_x) && (m_y == other.m_y);
    }
    
private:
    double m_x, m_y;
};

int main() {
    Point p1(0.0, 0.0);
    Point p2(6.0, 8.0);
    double distance = p1.distanceTo(p2);
    cout << format("Distance between points is {}\n", distance);

    double distance2 = p2.distanceTo(p1);
    cout << format("Distance between points is {}\n", distance2);
}