#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class ArrayList {
public:
    ArrayList();
    ArrayList(const ArrayList<T>& otherList);
	ArrayList<T>& operator=(const ArrayList<T>& other);
    ~ArrayList();

    ////--------------------------------------------------------------
    ///     New Features... Subscript and stream insertion
    ///     Implementations at bottom of file
    ////--------------------------------------------------------------
    //Member subscript operator
    T& operator[](int index);

    //Have to declare this friend functions as a templated function
    //  It is a seperate templated thing... needs to be specified with new template _____
    //  can't use <class T> as it is already in use
    template <class R>
    friend ostream& operator<<(ostream& theStream, ArrayList<R>& theList);

    int size() const;

    void append(const T& newItem);

    T get(int location) const;

    void set(int location, const T& repItem);

    void insertAt(int location, const T& insertItem);

    void removeAt(int location);

    string toString() const;

    //Returns location of first matching item in array
    //  Returns -1 if not found
    int search(const T& searchItem) const;

    //Puts array into ascending order
    void sort();

private:
    //double storage capacity
    void grow();

    T *list;            //array to hold the list elements
    int currentSize;    //logical length of the list
    int capacity;       //current available storage
};



//------------------------IMPLEMENTATIONS-------------------------------


template <class T>
ArrayList<T>::ArrayList()
{
    cout << "Making empty arraylist..." << endl;
    //Default to 10 items
    currentSize = 0;
    capacity = 10;
    //Allocate storage on heap
    list = new T[capacity];
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] list;
}

template <class T>
ArrayList<T>::ArrayList (const ArrayList<T>& otherList)
{
    //Copy basic information
    currentSize = otherList.currentSize;
    capacity = otherList.capacity;
    //Allocate new storage for the copy and copy data
    list = new T[capacity];
    for(int i = 0; i < capacity; i++)
        list[i] = otherList.list[i];
}


template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    //check if other guy's address is same as ours...
    if(&other == this) {
        //if so, do NOT want to copy, just return ourselves
        return *this;
    }

    //copy other's basic info
    capacity = other.capacity;
    currentSize = other.currentSize;

    //delete our current memory
    delete [] list;

    //allocate new array to match size of other
    list = new T[other.capacity];

    //copy contents of other list
    for(int i = 0; i < currentSize; i++) {
        list[i] = other.list[i];
    }

    //Return ourselves so chained assignment can work
    return *this;
}

template <class T>
int ArrayList<T>::size() const
{
    return currentSize;
}

template <class T>
void ArrayList<T>::grow()
{
    //Calculate new size and allocate storage
    int newSize = capacity * 2;
    T* tempList = new T[newSize];

    //Copy items from old list to new list
    for(int i = 0; i < capacity; i++)
        tempList[i] = list[i];

    //Update capacity
    capacity = newSize;

    //Delete our old array
    delete [] list;
    //Point to new one
    list = tempList;
}


template <class T>
void ArrayList<T>::append(const T& insertItem)
{
    if(currentSize == capacity)
        grow();

    list[currentSize] = insertItem;
    currentSize++;
}

template <class T>
T ArrayList<T>::get(int location) const
{
    if(location < 0 || location >= currentSize) {
        cout << "Bad index " << location << ", quiting..." << endl;
        exit(0);
    }

    return list[location];
}

template <class T>
void ArrayList<T>::set(int location, const T& repItem)
{
    if(location < 0 || location >= currentSize) {
        cout << "Bad index " << location << ", quiting..." << endl;
        exit(0);
    }

    list[location] = repItem;
}

template<typename T>
string ArrayList<T>::toString() const
{
    stringstream output;
    output << "[";
    //All but last element
    for(int i = 0; i < currentSize - 1; i++) {
        output << list[i] << ", ";
    }
    //last item, if any
    if(currentSize > 0)
        output << list[currentSize - 1];

    output << "]";

    return output.str();
}

template <class T>
void ArrayList<T>::removeAt(int location)
{
    if(location < 0 || location >= currentSize) {
        cout << "Bad index " << location << ", quiting..." << endl;
        exit(0);
    }

    //Shift everyone after location to left "remove" the item
    //  make sure to stop one early since we are copying from right
    for(int i = location; i < currentSize - 1; i++)
        list[i] = list[i+1];

    //Decrease logical size
    currentSize--;
}

template <class T>
void ArrayList<T>::insertAt(int location, const T& insertItem)
{
    if(location < 0 || location > currentSize) {
        cout << "Bad index " << location << ", quiting..." << endl;
        exit(0);
    }

    //Check to see if need more room...
    if(currentSize == capacity)
        grow();

    //Start from 1 past end of current array, work backwards to
    // moving elements 1 spot to right until we reach insert loc
    for(int i = currentSize; i > location; i--)
        list[i] = list[i - 1];

    //Place desired value
    list[location] = insertItem;

    //Increase logical size
    currentSize++;
}


template <class T>
int ArrayList<T>::search(const T& searchItem) const
{
    for(int i = 0; i < currentSize; i++) {
        if(list[i] == searchItem)
            return i;
    }
    return -1; //not found
}


template <class T>
void ArrayList<T>::sort() {
    //Selection sort - only sort the elements being used
    for(int i = 0; i < currentSize - 1; i++) {
        //Assume first unsorted element is smallest
        T currentMin = list[i];
        int currentMinIndex = i;

        //Look through rest of used array for smaller item
        for(int j = i + 1; j < currentSize; j++) {
            if(currentMin > list[j]) {
                currentMin = list[j];
                currentMinIndex = j;
            }
        }

        //Swap smallest item with curent unsorted item
        list[currentMinIndex] = list[i];
        list[i] = currentMin;
    }
}

//------------------------MEMBER OPERATORS------------------


//Member subscript operator
template <class T>
T& ArrayList<T>::operator[](int index)
{
    if(index < 0 || index >= currentSize) {
        cout << "Bad index " << index << " in list of size " << currentSize << endl;
        exit(0);
    }

    return list[index];
}

//------------------------RELATED NON-MEMBER FUNCTIONS------------------

//Could use <class T> here, but using R to make it clear this
// templated function is distinct from the templated class
template<class R>
ostream& operator<<(ostream& stream, ArrayList<R>& theList) {
    stream << "(";
    //print all but last
    for(int i = 0; i < theList.size() - 1; i++) {
        stream << theList.list[i] << ", ";
    }
    //print last if any
    if(theList.size() > 0)
        stream << theList[theList.size() - 1];
    stream << ")";
    return stream;
}

#endif // ARRAYLIST_H
