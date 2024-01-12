#ifndef ASSOCIATION_H
#define ASSOCIATION_H

/**
 * @brief Association stores two items of unrelated types
 */
template<class T1, class T2>
class Association {
public:
  Association(const T1& firstVal, const T2& secondVal);

  T1 getLeft() const;
  T2 getRight() const;

  void setLeft(const T1& value);
  void setRight(const T2& value);

private:
  T1 thing1;
  T2 thing2;
};

// Function implementations
template<class T1, class T2>
Association<T1, T2>::Association(const T1& firstVal, const T2& secondVal):
    thing1(firstVal), thing2(secondVal) {
  // everything done in initializer list
}

template<class T1, class T2>
T1 Association<T1, T2>::getLeft() const {
  return thing1;
}

template<class T1, class T2>
T2 Association<T1, T2>::getRight() const {
  return thing2;
}

template<class T1, class T2>
void Association<T1, T2>::setLeft(const T1& value) {
  thing1 = value;
}

template<class T1, class T2>
void Association<T1, T2>::setRight(const T2& value) {
  thing2 = value;
}

#endif // ASSOCIATION_H
