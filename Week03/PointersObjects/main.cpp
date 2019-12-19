#include <iostream>

using namespace std;


class Point {
public:
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(int xCoordinate, int yCoordinate) {
        x = xCoordinate;
        y = yCoordinate;
    }

    int getX() { return x; }
    int getY() { return y; }
};


int main()
{

    Point p1(5, 2);                 //Make a point
    Point* pp2 = &p1;               //Get pointer to it
    cout << pp2->getX() << endl;    //Same as(*pp2).getX()

}

