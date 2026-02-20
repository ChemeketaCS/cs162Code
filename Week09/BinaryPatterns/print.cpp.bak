#include <iostream>
using namespace std;

void printBinaryStrings(const string& current, int remainingBits) {
    if (remainingBits == 0) {
        cout << current << endl;
        return;
    }
    printBinaryStrings(current + "0", remainingBits - 1);
    printBinaryStrings(current + "1", remainingBits - 1);
}

// non-recursive wrapper
void printBinaryStrings(int n) {
    printBinaryStrings("", n);
}

int main() {
    printBinaryStrings(3);
}
