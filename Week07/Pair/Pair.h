#ifndef PAIR_H
#define PAIR_H


/**
 * @brief Pair stores two items of the same type that can be referred to as
 *          the left and right
 */
template<typename T>
class Pair {
public:
    Pair(const T& firstVal, const T& secondVal);

    T getLeft() const;
    T getRight() const;

    void setLeft(const T& value);
    void setRight(const T& value);

private:
    //Stores two items of type T, whatever that is
    T thing1;
    T thing2;
};

//Function implementations
template<class T>
Pair<T>::Pair(const T& firstVal, const T& secondVal)
    : thing1(firstVal), thing2(secondVal)
{
    //everything done in initializer list
}

template<class T>
T Pair<T>::getLeft() const {
    return thing1;
}

template<class T>
T Pair<T>::getRight() const {
    return thing2;
}

template<class T>
void Pair<T>::setLeft(const T& value) {
    thing1 = value;
}

template<class T>
void Pair<T>::setRight(const T& value) {
    thing2 = value;
}


#endif // PAIR_H
