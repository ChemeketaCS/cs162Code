#include <iostream>
#include <string>

#include "Templates.h"

using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int xVal, int yVal)
        : x(xVal), y(yVal) {}
    bool operator>(const Point& other) const {
        return true;
    }
};

//------------------------------------------
//Return larger of two items of mystery type T
template <typename T>
T larger(const T& x, const T& y)
{
    if (x > y)
        return x;
    else
        return y;
}

////Overloaded larger... most specific wins
//char larger(const char &x, const char &y)
//{
//    if (toupper(x) >= toupper(y))
//        return x;
//    else
//        return y;
//}


//------------------------------------------
//Print array of mystery type
template<class T>
void arrayPrint(T theArray[], int length) {
    for(int i = 0; i < length; i++) {
        cout << theArray[i] << " ";
    }
    cout << endl;
}

//------------------------------------------
//Find largest element of array of mystery type
// assumes length >= 1
template<class T>
T arrayMax(T theArray[], int length) {
    T largest = theArray[0];
    for(int i = 0; i < length; i++) {
        if(theArray[i] >= largest) {
            largest = theArray[i];
        }
    }
    return largest;
}



int main()
{
    char c = larger('q', 'B');
    cout << c << endl ;

    double x = larger(4.0, 6.8);
    cout << x << endl ;

//-----------------------------------------
    int z = smaller(4, -2);
    int z2 = simpleSmaller(4, -2);
    cout << z << endl ;


//-----------------------------------------
    int nums[3] {10,30,20};
    arrayPrint(nums, 3);
    cout << arrayMax(nums, 3) << endl;


////-----------------------------------------
///   Compiler won't like asking for larger Point
///      larger() depends on > operator which is not
///      defined for Points
//    Point p1(4, -1);
//    Point p2(2, 3);
//    Point p3 = larger(p1, p2);
//    cout << p3.x << " " << p3.y << endl;


    return 0;
}


