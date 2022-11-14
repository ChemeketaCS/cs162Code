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
 * @brief Finds the largest item in the vector at or after location index.
 *          Swap that item with the item at index.
 * @param vec vector to reorder. Elements must be comparable using <
 * @param index location to make sure has largest remaining item
 *
 * Example: given this vector: [40, 20, 15, 30, 5] and the index 1 (20)
 * we would find the 30 and swap it with the 20 resulting in
 * [40, 30, 15, 20, 5]
 */
template <typename T>
void placeLargestRemaining(vector<T>& vec, size_t index) {
    //TODO - FIXME
}


/**
 * @brief So a selection sort in descending order (largest value first)
 * @param vec vector to sort. Elements must be comparable using <
 *
 * Should use placeLargestRemaining as a helper
 */
template <typename T>
void selectionSort(vector<T>& vec) {
    //TODO - FIXME
}


#endif // SORTS_H
