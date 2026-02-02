#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int linearSearch(const vector<T>& vec, T key) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "Checking index " << i << ": value " << vec.at(i) << endl;
        if (vec.at(i) == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50};
    int key;
    cout << "Enter the value to search for: ";
    cin >> key;
    cout << key << endl;

    int result = linearSearch(numbers, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the vector." << endl;
    }
}
