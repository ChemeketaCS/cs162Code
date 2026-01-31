#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(3, 7) << endl;        // T is int
    cout << myMax(3.5, 2.1) << endl;    // T is double
    cout << myMax('a', 'z') << endl;    // T is char
    
    // cout << myMax(3, 4.2) << endl;  // Error: ambiguous type
    // Specify T as int. The 4.2 will be converted to 4
    cout << myMax<int>(3, 4.2) << endl;

    // Specify T as double. The 3 will be converted to 3.0
    cout << myMax<double>(3, 4.2) << endl;
}