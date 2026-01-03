#include <iostream>

#include "Location.h"

using namespace std;

// Returns the memory address of a heap based array of Locations
Location* makeLocationList() {
    Location* temp = new Location[5] {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    return temp;
}

Location* makeLocationList2() {
    Location* temp = new Location[3] {{10, 10}, {20, 20}, {30, 30}};
    return temp;
}

void printLocation(Location& l) {
    cout << "Location at " << l.getX() 
         << "," << l.getY() << endl;
}

void printLocations(Location list[], int size) {
    for(int i = 0; i <= size; i++) {
        printLocation(list[i]);
    }
}


int main()
{
    //Get an array of 5 locations
    Location* locationList = makeLocationList();
    printLocations(locationList, 5);

    //Now get a new list of locations
    locationList = makeLocationList2();
    printLocations(locationList, 3);
}

