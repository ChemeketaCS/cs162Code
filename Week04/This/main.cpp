#include <iostream>
using namespace std;

class Point {
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }
    
    double getX() {
        cout << "  In getX this is:" << this << endl;
        return m_x;
    }

    void setX(double x) {
        this->m_x = x;          // correct, explicit use of this-> to access member
        m_x = x;                // also correct, m_x is implicitly this->m_x
        // this->m_x = this->x;    // incorrect, x is not a member of Point
    }

    Point* getAddress() {
        return this;  // this is the memory address of the current object
    }

    Point& getReference() {
        return *this;  // return "the thing that this points at"
    }

private:
    double m_x;
    double m_y;
};

int main() {
    Point p1(0, 0);
    Point* p1Address = p1.getAddress();
    cout << "p1 address: " << &p1 << endl;
    cout << "p1Address : " << p1Address << endl;

    Point& p1Ref = p1.getReference();
    p1Ref.setX(42);
    cout << "p1.getX() after modifying via reference: " << p1.getX() << endl;
};
