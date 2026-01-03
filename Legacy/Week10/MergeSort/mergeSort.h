#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// Easily turn a vector into a string
template<typename T>
string to_string(const vector<T>& vec) {
  string result = "[";
  // All but last
  for (size_t i = 0; i < vec.size() - 1; i++) {
    result += to_string(vec.at(i)) + ", ";
  }
  // Last, if exists
  if (vec.size() > 0)
    result += to_string(vec.at(vec.size() - 1));

  result += "]";
  return result;
}

/**
 * @brief merge Combine all values from two sorted vectors, in order,
 *          into one new vector
 * @param vec1 sorted list of values
 * @param vec2 sorted list of values
 * @return new sorted vector containing all items from both 1 and 2
 *
 * vec1 and vec2 will remain unmodified by this function
 * Given [1, 5, 6] and [2, 3, 7, 8], should return
 * A new vector with [1, 2, 3, 5, 6, 7, 8]
 */
template<typename T>
vector<T> merge(const vector<T>& vec1, const vector<T>& vec2) {
  vector<T> newVec;

  // TODO - FIXME

  return newVec;
}

/**
 * @brief slice Makes a new vector that is a copy of part of a given vector
 * @param vec Vector to copy. Will not be modified
 * @param startLoc Index of location copy should start (inclusive)
 * @param endLoc Index location copy should end (exclusive)
 * @return new vector with all items from [start-end)
 *
 * A slice done with startLoc = 1 and endLoc = 4 should copy indexes 1-3
 */
template<typename T>
vector<T> slice(const vector<T>& vec, size_t startLoc, size_t endLoc) {
  vector<T> newVec;
  // TODO - FIXME
  return newVec;
}

/**
 * @brief Merge sorts vector in ascending order (smallest value first)
 * @param vec Vector to sort - will be modified
 */
template<typename T>
void mergeSort(vector<T>& vec) {
  // TODO - FIXME
  // Make sure to modify vector, not return a new one
}

#endif // MERGESORT_H
