#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//------------------------------------
//Definition
//------------------------------------
template<typename T>
class Stack
{
public:
    Stack();

    Stack(const Stack&);
    Stack<T>& operator=(const Stack&);
    ~Stack();

    bool empty() const;
    T peek() const;
    void push(const T& value);
    T pop();
    int getSize() const;

    //return string representing the stack
    string toString() const;

    //returns new stack containing top half of the stack
    // this stack will retain bottom half
    Stack<T> split();

    //empty the stack
    void clear();

private:
    T* elements;
    int size;
    int capacity;
    void ensureCapacity();
};


//------------------------------------
//Implementation
//------------------------------------
template<typename T>
Stack<T>::Stack()
    : size(0), capacity(10)
{
    //size/capacity set up in initialization list
    //allocate new array
    elements = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    //copy normal variables
    size = other.size;
    capacity = other.capacity;
    //make own array and copy elements from other
    elements = new T[other.capacity];
    for (int i = 0; i < size; i++)
    {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    //avoid self assignment
    if(this != &other) {
        //free old storage
        delete [] elements;
        //copy normal variables
        size = other.size;
        capacity = other.capacity;
        //make own array and copy elements from other
        elements = new T[other.capacity];
        for (int i = 0; i < size; i++)
        {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack()
{
    delete [] elements;
}


template<typename T>
Stack<T> Stack<T>::split()
{
    //Make new stack
    Stack<T> topHalf;

    //Figure out where to split
    int myNewSize = size / 2;

    //Index of first item to move to other Stack
    // will be the new size of the bottom half
    for(int i = myNewSize; i < size; i++) {
        //Get that item from the array
        T currentItem = elements[i];
        //Tell the other stack to add it
        topHalf.push(currentItem);
    }

    //Change our size to ignore the top half that we moved
    size = myNewSize;

    //Return the new Stack that contains the top half
    return topHalf;
}

template<typename T>
string Stack<T>::toString() const
{
    stringstream output;
    output << "[";
    //All but last element
    for(int i = 0; i < size - 1; i++) {
        output << elements[i] << ", ";
    }
    //last item, if any
    if(size > 0)
        output << elements[size - 1];

    output << "]";

    return output.str();
}


template<typename T>
bool Stack<T>::empty() const
{
    return (size == 0);
}

template<typename T>
T Stack<T>::peek() const
{
    if(size == 0) {
        cout << "Peeking empty stack... quitting." << endl;
        exit(0);
    }

    //top of stack is at size - 1
    return elements[size - 1];
}

template<typename T>
void Stack<T>::push(const T& value)
{
    ensureCapacity();
    elements[size++] = value;
    //postincrement - happens AFTER array access - short for:
    //elements[size] = value;
    //size = size + 1;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
    if (size >= capacity)
    {
        cout << "Ooops, have to grow..." << endl;

        //Temp pointer to old array
        T* old = elements;

        //Increase capacity and make new array to point to
        capacity = 2 * size;
        elements = new T[size * 2];

        //Copy from old array to new array
        for (int i = 0; i < size; i++)
            elements[i] = old[i];

        //Delete the old array from the heap
        delete [] old;
    }
}

template<typename T>
T Stack<T>::pop()
{
    if(size == 0) {
        cout << "Popping empty stack... quitting." << endl;
        exit(0);
    }

    //return the top element and decrease size
    return elements[--size];
    //predecrement - happens BEFORE array access - same as
    //size = size - 1;
    //return elements[size];
}

template<typename T>
int Stack<T>::getSize() const
{
    return size;
}


template<typename T>
void Stack<T>::clear()
{
    //change size to 0, pretend nothing is there
    size = 0;
}

#endif

