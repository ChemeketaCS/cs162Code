#include <iostream>
using namespace std;

// Increment takes p, which is the address of an int
void increment(int* p) {
    cout << "Value of p is " << p << endl;
    int temp = *p + 1; // get value p points at, add 1 to it
    *p = temp;         // store result back in the same place
    // or *p = *p + 1;
}

int main() {
    int x = 10;
    int y = 10;

    cout << "Address of x is " << &x << endl;
    cout << "Address of y is " << &y << endl;
    cout << "Value of x is " << x << endl;
    cout << "Value of y is " << y << endl;

    increment(&x); // pass address of x to increment function
    cout << "Value of x is " << x << endl;

    increment(&y); // pass address of y to increment function
    cout << "Value of y is " << y << endl;
}