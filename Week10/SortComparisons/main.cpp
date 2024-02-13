#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void insertionSort(vector<T>& vec) {
  // There is no standard insertion sort, but we can implement it using std
  // functions:
  for (auto it = vec.begin(); it != vec.end(); it++) {
    // Search for the location of the first value >= than the current value
    auto insertion_point = std::upper_bound(vec.begin(), it, *it);
    // Shifts the current value to that location and everything else to the
    // right
    std::rotate(insertion_point, it, it + 1);
  }
}

template<typename T>
void mergeSort(vector<T>& vec) {
  // stable_sort is the standard version of mergesort
  std::stable_sort(vec.begin(), vec.end());
}

int main() {
  // Speed test mergesort vs a quadratic sort
  for (int size = 1000; size < 100000000; size *= 2) {
    cout << "Sorting vector of size " << size << "..." << endl;
    vector<int> v(size);
    for (int& i : v) {
      i = rand() * 10000 + rand();
    } // fill with random values

    clock_t start = clock();
    // Pick ONE algorithm to test - comment out the other
    mergeSort(v);
    // insertionSort(v);
    clock_t end = clock();
    cout << fixed
         << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
         << endl;
  }
}
