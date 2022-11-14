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
 * @brief Slides an item in the vector to its left until it reaches the
 *          start of the vector or is < the item to its left
 * @param vec vector to reorder. Elements must be comparable using <
 * @param index starting index of item to slide into position
 *
 * Example: given this vector: [10, 20, 40, 15, 30, 5] and the index 3 (15)
 * the 15 would slide past the 40 and 20 but then stop, giving
 * [10, 15, 20, 40, 30, 5]
 */
template <typename T>
void slideToPosition(vector<T>& vec, size_t index) {
    //TODO - FIXME
}


/**
 * @brief Do an insertion sort in ascending order (smallest value first)
 * @param vec vector to sort. Elements must be comparable using <
 *
 * Should use slideToPosition as helper
 */
template <typename T>
void insertionSort(vector<T>& vec) {
    //TODO - FIXME
}


#endif // SORTS_H
