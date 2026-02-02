#include <iostream>
#include <vector>
using namespace std;

#include "vector-helpers.h"

// Assumes start/end consists of two sorted halves:
//   [start..mid] and [mid+1..end]
// Temp should be same size as vec. It is a parameter so that later we
//   can reuse the same temp vector across multiple calls to merge
template<typename T>
void merge(vector<T>& vec, int start, int end, vector<T>& temp) {
    int mid = (start + end) / 2;
    int nextLeft = start;
    int nextRight = mid + 1;
    int mergeIndex = start;

    int totalItems = end - start + 1;
    for(int i = 0; i < totalItems; ++i) {
        // determine if taking from left or right
        bool takeLeft;
        bool leftEmpty = (nextLeft > mid);
        bool rightEmpty = (nextRight > end);
        if (rightEmpty) {
            takeLeft = true;
        } else if (leftEmpty) {
            takeLeft = false;
        } else if (vec.at(nextLeft) <= vec.at(nextRight)) {
            // items in both, left is smaller
            takeLeft = true;
        } else {
            // items in both, right is smaller
            takeLeft = false;
        }

        // take from the chosen side
        if (takeLeft) {
            cout << "Merging left item (" << vec.at(nextLeft) << ")" << endl;
            temp.at(mergeIndex) = vec.at(nextLeft);
            nextLeft++;
        } else {
            cout << "Merging right item (" << vec.at(nextRight) << ")" << endl;
            temp.at(mergeIndex) = vec.at(nextRight);
            nextRight++;
        }
        mergeIndex++;

        // Debug output to show the array after each outer loop iteration
        cout << "Temp: " << vectorToString(temp) << endl;
    }

    // Copy the merged elements back into the original vector
    for (int i = start; i <= end; ++i) {
        vec.at(i) = temp.at(i);
    }
}

int main() {
    vector<int> numbers = {0, 0, 1, 4, 5, 2, 6, 7, 0, 0};
    vector<int> temp(numbers.size());
    // We will merge the portion from index 2 to index 7
    // which has two sorted halves: 1,4,5 and 2,6,7
    int start = 2;
    int end = 7;
    merge(numbers, start, end, temp);
    cout << "Merged array: " << endl;
    cout << vectorToString(numbers) << endl;
}
