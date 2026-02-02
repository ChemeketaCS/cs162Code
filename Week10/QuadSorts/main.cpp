#include <iostream>
#include <vector>
using namespace std;

#include "vector-helpers.h"

template<typename T>
void selectionSort(vector<T>& vec) {
    size_t n = vec.size();
    // Loop to do n-1 passes
    for (size_t i = 0; i < n - 1; ++i) {
        // Find the index of the minimum element in the unsorted portion starting at i
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (vec.at(j) < vec.at(minIndex)) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        if (minIndex != i) {
            swap(vec.at(i), vec.at(minIndex));
        }
        // Debug output to show the array after each outer loop iteration
        cout << "After pass " << i + 1 << ": " << endl;
        cout << vectorToString(vec) << endl;
    }
}

int main() {
    vector<int> numbers = {8, 3, 7, 1, 9, 12, 6, 20, 11, 14};

    selectionSort(numbers);
    cout << "Sorted array: " << endl;
    cout << vectorToString(numbers) << endl;
}
