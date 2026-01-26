#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DescendingComparer {
    bool operator()(int a, int b) const {
        return a > b; // a comes first if it is greater than b
    }
};

int main() {
    // Create a vector of integers
    vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // Sort the vector in ascending order
    sort(numbers.begin(), numbers.end());

    cout << "Sorted numbers: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the vector in descending order using the custom comparer
    sort(numbers.begin(), numbers.end(), DescendingComparer());
    cout << "Sorted numbers (descending): ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}
