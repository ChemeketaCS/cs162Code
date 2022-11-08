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
 * @brief placeLargestRemaining
 * @param vec vector to reorder. Elements must be comparable using <
 * @param index location to make sure has largest remaining item
 *
 * Find the largest item in the vector at or after location index.
 * Swap that item with the item at index.
 */
template <typename T>
void placeLargestRemaining(vector<T>& vec, size_t index) {
    //TODO - FIXME
}


/**
 * @brief selectionSort
 * @param vec vector to sort. Elements must be comparable using <
 */
template <typename T>
void selectionSort(vector<T>& vec) {
    //TODO - FIXME
}


#endif // SORTS_H
