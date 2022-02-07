/**
  * Class that represents a list of ints with a fixed max capacity.
  *
  */

#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

class IntList
{
private:
    int* values;    //pointer to array of ints
    int capacity;
    int currentSize;

public:
    //Max capacity of 10
    IntList();

    //Max capacity of n
    IntList(int n);

    //Rule of three:
    ~IntList();  //destructor
    IntList(const IntList& other); //copy constructor
    IntList& operator=(const IntList& other); //assignment operator


    //Get number of ints actually in the list
    int getSize() const;

    //Add an int to end of list
    void add(int value);

    //Remove the value at the given index - all numbers after it shift to left
    void removeAt(int index);

    //const version of [] returns a copy of value at index
    //  can use to read in situations where we need to preserve const-ness
    int at(int index) const;

    //non-const version of [] returns a reference to the value at index
    //  can use in situations where we want to modify value
    int& at(int index);

    //Make a new int list that has the contents of this list followed by
    //  the contents of the other list
    //  Resulting list will have space for 10 new items after existing ones
    IntList operator+(const IntList& other) const;

    //Check if two lists are identical
    bool operator==(const IntList& other) const;

    //Get the sum of all elements between indexes start and end inclusive
    //  Throws an exception if indexes are bad
    int sumBetween(int start, int end) const;

    //Returns a string representation of the list
    std::string toString() const;

    //Providing an external << is an alternative to a toString() function
    //It would allow for "cout << list;" instead of "cout << list.toString();"
    //Declare non-member << function as friend so it can access member variables
    friend std::ostream& operator<<(std::ostream& stream, const IntList& theList);
};

//Print IntList to a stream
std::ostream& operator<<(std::ostream& stream, const IntList& theList);

#endif // INTLIST_H
