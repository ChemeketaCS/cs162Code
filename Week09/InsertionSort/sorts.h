#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


///Easily turn a vector into a string
template <typename T>
string to_string(const vector<T>& vec) {
    string result = "[";
    //All but last
    for(size_t i = 0; i < vec.size() - 1; i++) {
        result += to_string(vec.at(i)) + ", ";
    }
    //Last, if exists
    if(vec.size() > 0)
        result += to_string(vec.at(vec.size() - 1));

    result += "]";
    return result;
}


/**
 * @brief slideToPosition
 * @param vec vector to reorder. Elements must be comparable using <
 * @param index starting index of item to slide into position
 *
 * The item at the indicated index should swap its way to the left until
 * it reaches the start of the vector or the item to its left is less than it
 */
template <typename T>
void slideToPosition(vector<T>& vec, size_t index) {
    //TODO - FIXME
}


/**
 * @brief insertionSort
 * @param vec vector to sort. Elements must be comparable using <
 */
template <typename T>
void insertionSort(vector<T>& vec) {
    //TODO - FIXME
}


#endif // SORTS_H
