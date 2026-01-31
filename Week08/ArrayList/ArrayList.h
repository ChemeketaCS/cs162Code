#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <stdexcept>
#include <string>

template<typename T>
class ArrayList {
public:
    // Construct an empty ArrayList
    ArrayList();

    // Rule of Three
    // Copy another ArrayList of type T
    ArrayList(const ArrayList<T>& otherList);
    // Assign from another ArrayList of type T
    ArrayList<T>& operator=(const ArrayList<T>& other);
    // Destructor to free memory
    ~ArrayList();

    // Insert item at end of list
    void insertEnd(const T& newItem);

    // Remove item from end of list
    void removeEnd();

    // Access item at given index
    T get(int index) const;

    // Replace item at given index
    void set(int location, const T& repItem);

    // Ask how many items are in the list
    int size() const;

    // Erase all items from the list
    void clear();

    // Insert item at specified index
    void insertAt(int location, const T& insertItem);

    // Remove item at specified index
    void removeAt(int location);

    // Return a string that has the contents of the list
    std::string toString() const;

    // Returns location of first matching item in array
    //   Returns -1 if not found
    int search(const T& searchItem) const;

private:
    // double storage capacity
    void grow();

    T* m_arr;       // pointer to the array of type T
    int m_capacity; // maximum number of elements
    int m_size;     // current number of elements
};

template<typename T>
ArrayList<T>::ArrayList() {
    m_size = 0;
    m_capacity = 5;  //default to space for 5 items
    m_arr = new T[m_capacity]; // Allocate storage on heap
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherList) {
    m_size = otherList.m_size;
    m_capacity = otherList.m_capacity;
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = otherList.m_arr[i];
    }
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    if (this != &other) {
        delete[] m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr = new T[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] m_arr;
}

template<typename T>
void ArrayList<T>::insertEnd(const T& newItem) {
    if (m_size == m_capacity) {
        grow();
    }
    m_arr[m_size] = newItem;
    m_size++;
}

template<typename T>
void ArrayList<T>::removeEnd() {
    if (m_size == 0) {
        throw std::out_of_range("ArrayList is empty");
    }
    // reduce size, return the item just past the new end
    --m_size;
    return m_arr[m_size];
}

template<typename T>
T ArrayList<T>::get(int location) const {
    if (location < 0 || location >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[location];
}

template<typename T>
void ArrayList<T>::set(int location, const T& newValue) {
    if (location < 0 || location >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    m_arr[location] = newValue;
}

// removeAt will be built as an exercise

template<typename T>
void ArrayList<T>::insertAt(int location, const T& insertItem) {
    if (location < 0 || location > m_size) {
        throw std::out_of_range("Index out of range");
    }
    if (m_size == m_capacity) {
        grow();
    }
    // Shift elements up to make room for the new item
    for (int i = m_size; i > location; --i) {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[location] = insertItem;
    ++m_size;
}

template<typename T>
int ArrayList<T>::size() const {
    return m_size;
}

template<typename T>
void ArrayList<T>::clear() {
    m_size = 0;
}

template<typename T>
std::string ArrayList<T>::toString() const {
    std::string result = "[";
    for (int i = 0; i < m_size; ++i) {
        if (i > 0)
            result += ", ";
        // count on T having an appropriate to_string conversion
        result += std::to_string(m_arr[i]);
    }
    result += "]";
    return result;
}

template<typename T>
int ArrayList<T>::search(const T& searchItem) const {
    for (int i = 0; i < m_size; ++i) {
        if (m_arr[i] == searchItem) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void ArrayList<T>::grow() {
    // double the capacity and allocate a new array of that size
    m_capacity *= 2;
    T* newArr = new T[m_capacity];
    // copy old items to new array
    for (int i = 0; i < m_size; ++i) {
        newArr[i] = m_arr[i];
    }
    // delete old array and update pointer
    delete[] m_arr;
    m_arr = newArr;
}

#endif // ARRAY_LIST_HPP
