#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> getNValuesRandomOrder(int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }
  shuffle(v.begin(), v.end(), default_random_engine(0));
  return v;
}

template<typename T>
int linearSearch(const vector<T>& vec, const T& value) {
  for (size_t i = 0; i < vec.size(); i++) {
    if (vec.at(i) == value)
      return static_cast<int>(i);
  }
  return -1;
}

int main() {
  vector<int> nums{12, 8, 19, 5, 15, 20, 2, 6, 13, 1};
  cout << "Found 12 at " << linearSearch(nums, 12) << endl;
  cout << "Found 20 at " << linearSearch(nums, 20) << endl;
  cout << "Found 7 at " << linearSearch(nums, 7) << endl;

  for (int size = 10000; size < 100000000; size *= 2) {
    // Make a large vector
    vector<int> v = getNValuesRandomOrder(size);

    cout << "Linear search in size: " << size << "..." << endl;

    clock_t start = clock(); // get elapsed clock ticks since program started

    int TIMING_REPETITIONS = 100000000 / size;
    for (int time = 0; time < TIMING_REPETITIONS; time++)
      linearSearch(v, time); // O(n)

    clock_t end = clock(); // get elapsed clock ticks since program started
    cout << fixed << "Took: "
         << static_cast<double>(end - start) / CLOCKS_PER_SEC
                / TIMING_REPETITIONS
         << " per search" << endl;
    cout << "---------------------" << endl;
  }
}
