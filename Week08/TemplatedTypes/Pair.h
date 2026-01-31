#ifndef PAIR_H
#define PAIR_H

template<typename T>
class Pair {
private:
    T first;
    T second;
public:
    // Full formal declaration
    // Pair<T>(T a, T b);
    // Short form, <T> is implied from class
    Pair(T a, T b);

    // Full formal declaration
    // bool operator==(const Pair<T>& other) const;
    // Short form, <T> is implied from class
    bool operator==(const Pair& other) const;

    T getFirst() const;
    T getSecond() const;
};


template<typename T>
Pair<T>::Pair(T a, T b) {
    first = a;
    second = b;
}

template<typename T>
bool Pair<T>::operator==(const Pair& other) const {
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