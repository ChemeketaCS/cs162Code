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


///// Verbose, basic bubleSort
//template <typename T>
//void bubbleSort(vector<T>& vec) {
//    for(size_t i = 0; i < vec.size(); i++) {
//        cout << to_string(vec) << endl;
//        for(size_t j = 0; j < vec.size() - 1; j++) {
//            cout << "Checking " << vec.at(j) << " and " << vec.at(j + 1) << endl;
//            if(vec.at(j) > vec.at(j + 1)) {
//                cout << " -Swapping " << vec.at(j) << " and " << vec.at(j + 1) << endl;
//                swap(vec.at(j), vec.at(j + 1));
//                cout << to_string(vec) << endl;
//            }
//        }
//        cout << "---------------------------------" << endl;
//    }
//}

///// Verbose, efficient bubleSort
//template <typename T>
//void bubbleSort(vector<T>& vec) {
//    for(size_t i = 1; i < vec.size(); i++) {
//        cout << to_string(vec) << endl;
//        for(size_t j = 0; j < vec.size() - i; j++) {
//            cout << "Checking " << vec.at(j) << " and " << vec.at(j + 1) << endl;
//            if(vec.at(j) > vec.at(j + 1)) {
//                cout << " -Swapping " << vec.at(j) << " and " << vec.at(j + 1) << endl;
//                swap(vec.at(j), vec.at(j + 1));
//                cout << to_string(vec) << endl;
//            }
//        }
//        cout << "---------------------------------" << endl;
//    }
//}

/// Basic bubleSort
//template <typename T>
//void bubbleSort(vector<T>& vec) {
//    for(size_t i = 0; i < vec.size(); i++) {
//        for(size_t j = 0; j < vec.size() - 1; j++) {
//            if(vec.at(j) > vec.at(j + 1)) {
//                swap(vec.at(j), vec.at(j + 1));
//            }
//        }
//    }
//}

///// Efficient bubleSort
//template <typename T>
//void bubbleSort(vector<T>& vec) {
//    for(size_t i = 1; i < vec.size(); i++) {
//        //i indicates how many items at end are sorted. Do not need to visit those
//        for(size_t j = 0; j < vec.size() - i; j++) {
//            if(vec.at(j) > vec.at(j + 1)) {
//                swap(vec.at(j), vec.at(j + 1));
//            }
//        }
//    }
//}

/// Adaptive bubleSort
template <typename T>
void bubbleSort(vector<T>& vec) {
    for(size_t i = 1; i < vec.size(); i++) {
        bool madeSwap = false;
        for(size_t j = 0; j < vec.size() - i; j++) {
            if(vec.at(j) > vec.at(j + 1)) {
                swap(vec.at(j), vec.at(j + 1));
                madeSwap = true;
            }
        }
        if(!madeSwap)
            break;
    }
}



#endif // SORTS_H
