#include <iostream>
using namespace std;

template<typename T>
struct Pair {
    T first;
    T second;
};

// Two pairs, both of type T, are equal if their first and second elements are equal
template<typename T>
bool areEqual(const Pair<T>& p1, const Pair<T>& p2) {
    return (p1.first == p2.first) && (p1.second == p2.second);
}

int main() {
    // Sample uses:
    Pair<int> intPair;
    intPair.first = 3;
    intPair.second = 4;
    cout << "intPair: " << intPair.first << ", " << intPair.second << endl;

    Pair<double> doublePair {2.5, 3.7};
    cout << "doublePair: " << doublePair.first << ", " << doublePair.second << endl;

    Pair<int> anotherIntPair {3, 4};
    cout << "intPair and anotherIntPair are equal: "
         << areEqual(intPair, anotherIntPair) << endl;
}
