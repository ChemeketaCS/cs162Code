
#include "IntList.h"

#include <iostream>

using namespace std;

int main()
{
    IntList myArray;
    myArray.add(1);
    myArray.add(2);
    myArray.add(3);
    myArray.add(4);
    cout << "Initial list:" << endl;
    cout << myArray << endl << endl;

    IntList myArray2 = myArray; //Use copy ctor
    myArray[1] = 999;
    cout << "Made copy, modified original: " << endl;
    cout << "Original: " << myArray << endl ;
    cout << "Copy: " << myArray2<< endl << endl;

    myArray.removeAt(1);
    cout << "Remove number at [1]:" << endl;
    cout << myArray << endl << endl;

    myArray.removeAt(1);
    cout << "Remove number at [1]:" << endl;
    cout << myArray << endl << endl;


    //Operator + demo
    IntList myArray3;
    myArray3.add(1);
    myArray3.add(2);
    myArray3.add(3);
    myArray3.add(4);
    myArray3.add(5);
    myArray3.add(6);
    IntList myArray4 = myArray + myArray3;
    cout << "Combining two lists with +:" << endl;
    cout << "Part 1:  " << myArray << endl;
    cout << "Part 2:  " << myArray3 << endl;
    cout << "Combined:" << myArray4 << endl;

    return 0;
}

