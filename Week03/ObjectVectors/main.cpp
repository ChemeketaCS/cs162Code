#include <iostream>
#include <vector>
using namespace std;

class SimplePoint1 {
public:
    SimplePoint1(double x, double y) {
        m_x = x;
        m_y = y;
        cout << "SimplePoint1 created at (" << m_x << ", " << m_y << ")\n";
    }

    double getX() const {
        return m_x;
    }
private:
    double m_x, m_y;
};

class SimplePoint2 {
public:
    SimplePoint2() {
        m_x = 0;
        m_y = 0;
        cout << "SimplePoint2 created at (" << m_x << ", " << m_y << ")\n";
    }
    SimplePoint2(double x, double y) {
        m_x = x;
        m_y = y;
        cout << "SimplePoint2 created at (" << m_x << ", " << m_y << ")\n";
    }

    double getX() const {
        return m_x;
    }
private:
    double m_x, m_y;
};


int main()
{
    // This does NOT work because SimplePoint1 has no default constructor
    vector<SimplePoint1> badPoints(5);

    // This works because SimplePoint2 has a default constructor
    vector<SimplePoint2> points1(5);

    // Make a vector of SimplePoint1 objects with explicit construction
    vector<SimplePoint1> points2(5, SimplePoint1(5.0, 5.0));

    // Make a vector of SimplePoint1 objects from a list
    vector<SimplePoint1> points3 = {
      SimplePoint1(0.0, 0.0), 
      SimplePoint1(1.0, 2.0),
      SimplePoint1(2.0, 3.0)
    };

    // Now use some points
    // Access the first element from points1's x
    cout << points1.at(0).getX() << endl; 
    cout << points2.at(2).getX() << endl; // Access the third element from points2's x

    SimplePoint2 oops = points1.at(1); // Makes a COPY!

    // Loop through points3 and print their x values
    cout << "Printing x values from a vector with a loop: ";
    for (const SimplePoint1& point : points3) {
        cout << point.getX() << " ";
    }
}
