#include <iostream>
using namespace std;

int binaryPatterns(int n) {
    if (n == 0) {
        return 1; // Base case: one pattern of length 0 (the empty pattern)
    } else {
        // Recursive case: for each pattern of length n-1, we can add '0' or '1'
        return binaryPatterns(n - 1) + binaryPatterns(n - 1);
    }
}

int main() {
    int count = binaryPatterns(3);
    cout << "Number of binary patterns of length 3: " << count << endl;
}
