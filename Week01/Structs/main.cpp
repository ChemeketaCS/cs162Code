#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point pointA = { 0.0, 0.0 };
    Point pointB = { 3.0, 4.0 };
    double dist = distance(pointA, pointB);
    cout << "The distance from Point A to Point B is: "
         << dist << endl;
}
