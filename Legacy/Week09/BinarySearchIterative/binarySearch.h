#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// Easily turn vector into a string
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

//---------------------------------------------------
// Iterative

/// Returns location of value or -1 if not present
/// Recommendation: use int to represent indexes within this fuction
///   using size_t complicates the logic as subtracting 1 from 0 will wrap
///   back to the largest positive value
template<typename T>
int binarySearch(const T& value, const vector<T>& vec) {
  return -1; // TODO - fixme
}

#endif // BINARYSEARCH_H
