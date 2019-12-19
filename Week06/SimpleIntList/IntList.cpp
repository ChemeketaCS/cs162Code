#include "IntList.h"

#include <iostream>
#include <exception>

using namespace std;

IntList::IntList() {
    capacity = 10;
    currentSize = 0;
    values = new int[capacity];
}


IntList::IntList(int n) {
    capacity = n;
    currentSize = 0;
    values = new int[capacity];
}


IntList::~IntList() {
    delete [] values;
}


IntList::IntList(const IntList& other) {
    capacity = other.capacity;
    currentSize = other.currentSize;

    //allocate our own storage
    values = new int[capacity];

    for(int i = 0; i < currentSize; i++) {
        values[i] = other.values[i];
    }
}


IntList& IntList::operator=(const IntList& other) {
    //avoid self assignment
    if(this != &other) {
        //clear old storage
        delete [] values;

        capacity = other.capacity;
        currentSize = other.currentSize;
        values = new int[capacity];


        for(int i = 0; i < currentSize; i++) {
            values[i] = other.values[i];
        }
    }

    return *this;
}


int IntList::getSize() const {
    return currentSize;
}


void IntList::add(int value) {
    if(capacity == currentSize)
        throw logic_error("Too many items in list!");

    //add to end of list
    values[currentSize] = value;
    currentSize++;
}


void IntList::removeAt(int index) {
    if(index < 0 || index >= currentSize)
        throw out_of_range("Bad index for removeAt: " + to_string(index));

    //scoot every element at index+1 and above down one to cover up hole
    for(int i = index + 1; i < currentSize; i++) {
        values[i - 1] = values[i];
    }
    //decrement size
    currentSize--;
}


int IntList::operator[](int index) const {
    if(index < 0 || index >= currentSize)
        throw out_of_range("Bad index for [ ]: " + to_string(index));

    return values[index];
}


int& IntList::operator[](int index) {
    if(index < 0 || index >= currentSize)
        throw out_of_range("Bad index for [ ]: " + to_string(index));

    return values[index];
}


IntList IntList::operator+(const IntList& other) const {
    //Make a new list that has space for all items in both lists
    // and space for 10 more things
    IntList temp(this->getSize() + other.getSize() + 10);

    //Tell temp to add each item from this list
    for(int i = 0; i < this->getSize(); i++) {
        temp.add(this->values[i]);
    }

    //And then each from other
    for(int i = 0; i < other.getSize(); i++) {
        temp.add(other.values[i]);
    }

    return temp;
}


int IntList::sumBetween(int start, int end) const {
    if( start < 0 || start >= currentSize
        || end < start || end >= currentSize ) {
        throw out_of_range("Bad index for [ ]: ");
    }

    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += values[i];
    }
    return sum;
}


bool IntList::operator==(const IntList& other) const {
    if(currentSize != other.currentSize)
        return false;  //can't be the same if we don't have same # items

    //Same size, walk through items looking for mismatch
    for(int i = 0; i < currentSize; i++) {
        if(values[i] != other.values[i])
            return false;
    }

    //Must be identical
    return true;
}

std::ostream& operator<<(std::ostream& stream, const IntList& theList) {
    stream << "(";
    for(int i = 0; i < theList.getSize(); i++) {
        stream << theList[i];
        if(i < theList.getSize() - 1)
            cout << ",";
    }
    stream << ")";

    return stream;
}

