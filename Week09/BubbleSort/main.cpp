#include <iostream>
#include <cstdlib>

#include "sorts.h"

using namespace std;

int main() {
    //Basic test
    vector<int> v {20, 35, 15, 30, 5, 25, 10};
    cout << "Sorting:" << endl;
    cout << to_string(v) << endl << endl;
    bubbleSort(v);
    cout << to_string(v) << endl;

//    //Speed test
//    for(int size = 100; size < 100000; size *= 2) {
//        cout << "Sorting vector of size " << size << "..." << endl;
//        vector<int> v2(size);
//        for(int& i : v2) { i = rand() * 10000 + rand(); } //fill with random values

//        clock_t start = clock();
//        bubbleSort(v2);
//        clock_t end = clock();
//        cout << fixed << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << endl;
//    }
}
