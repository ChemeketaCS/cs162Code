#include <iostream>

#include "Location.h"

using namespace std;

// Returns the memory address of a heap based array of Locations
Location* makeLocationList(int size) {
    Location* temp = new Location[size];
    return temp;
}

int main()
{
    //Get an array of 5 locations
    Location* locationList = makeLocationList(5);
    cout << locationList[4].getX();

    delete [] locationList;

}

