#ifndef PAIR_H
#define PAIR_H

template<typename T>
class Pair {
private:
    T first;
    T second;
public:
    // Constructors are still just called "Pair"
    Pair();
    Pair(T a, T b);

    // Parameter is another Pair of the same type
    bool operator==(const Pair<T>& other) const;

    T getFirst() const;
    T getSecond() const;
};

// Each member function must be defined as a template
// and the class name must be qualified with <T>
template<typename T>
Pair<T>::Pair() {
    first = T{};  // Default value for type T
    second = T{}; // Default value for type T
}

template<typename T>
Pair<T>::Pair(T a, T b) {
    first = a;
    second = b;
}

template<typename T>
bool Pair<T>::operator==(const Pair<T>& other) const {
    return (first == other.first) && (second == other.second);
}

template<typename T>
T Pair<T>::getFirst() const {
    return first;
}

template<typename T>
T Pair<T>::getSecond() const {
    return second;
}

#endif