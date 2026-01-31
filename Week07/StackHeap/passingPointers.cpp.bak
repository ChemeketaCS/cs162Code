#include <iostream>
#include <string>

using namespace std;

int* makeMemory() {
    int* p1 = new int(5);
    cout << "p1: " << p1 << endl;
    cout << "p1 points to: " << *p1 << endl;
    // Do NOT delete the memory p1 points at...
    // we will return that address and keep using it
    return p1;
}

void borrowMemory(int* memoryAddress) {
    cout << "borrowedMemory: " << memoryAddress << endl;
    cout << "Changing borrowedMemory to point to 10" << endl;
    *memoryAddress = 10; // Change the value at the memory address
    cout << "borrowedMemory points to: " << *memoryAddress << endl;
    // Do NOT delete the memory memoryAddress points at...
    // it is just a copy of the memory address main "owns"
}

int main() {
    // Call a function that allocates memory and returns a pointer
    int* returnedPointer = makeMemory();

    cout << "returnedMemory: " << returnedPointer << endl;
    cout << "returnedMemory points to: " << *returnedPointer << endl;

    // Pass the memory address to another function
    // that will use the memory but not "own" it
    borrowMemory(returnedPointer);

    cout << "returnedMemory is still: " << returnedPointer << endl;
    cout << "returnedMemory points to: " << *returnedPointer << endl;

    // We are now done with the memory
    delete returnedPointer;
}