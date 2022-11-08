#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


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


//You can only test one version of binarySearch at a time
//Comment out one to test the other.
//(Select lines and "Ctrl /" to comment/uncomment a block of lines)

//---------------------------------------------------
//Recursive

///low and high represent the current boundaries of the search
///returns location of value or -1 if not present
///Recommendation: use int to represent indexes within this fuction
///  using size_t complicates the logic as subtracting 1 from 0 will wrap
///  back to the largest positive value
template <typename T>
int recursiveBinarySearchHelper(const T& value, const vector<T>& vec, int low, int high) {
    if(low > high)
        return -1; //TODO - fixme

    int mid = (low + high) / 2;
    if(vec.at(mid) == value)
        return static_cast<int>(mid);
    else if(vec.at(mid) > value)
        return recursiveBinarySearchHelper(value, vec, low, mid - 1);
    else
        return recursiveBinarySearchHelper(value, vec, mid + 1, high);
}

///Returns location of value or -1 if not present
///Recommendation: use int to represent indexes within this fuction
///  using size_t complicates the logic as subtracting 1 from 0 will wrap
///  back to the largest positive value
template <typename T>
int binarySearch(const T& value, const vector<T>& vec) {
    int size = static_cast<int>(vec.size());
    //pass off work to recursive helper function
    return recursiveBinarySearchHelper(value, vec, 0, size - 1);
}


//---------------------------------------------------
//Iterative

///Returns location of value or -1 if not present
///Recommendation: use int to represent indexes within this fuction
///  using size_t complicates the logic as subtracting 1 from 0 will wrap
///  back to the largest positive value
//template <typename T>
//int binarySearch(const T& value, const vector<T>& vec) {
//    int low = 0, high = static_cast<int>(vec.size());

//    while(low <= high) {
//        int mid = (low + high) / 2;
//        if(vec.at(mid) == value)
//            return static_cast<int>(mid);
//        else if(vec.at(mid) > value)
//            high = mid - 1;
//        else
//            low = mid + 1;
//    }

//    return -1; //TODO - fixme
//}

#endif // BINARYSEARCH_H
