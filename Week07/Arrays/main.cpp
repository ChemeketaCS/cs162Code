#include <iostream>
#include <string>

using namespace std;

int main() {
    int* data = new int[3];
    data[0] = 1; // set the first element to 1
    data[1] = 2; // set the second element to 2

    int location = 2;
    data[location] = 3; // set the third element to 3

    // print the first element
    cout << "data[0]: " << data[0] << endl;

    // Delete the array
    delete[] data;
}
