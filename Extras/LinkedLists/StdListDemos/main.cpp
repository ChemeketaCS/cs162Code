//Program to demonstrate a reverse iterator.
#include <iostream>
#include <list>
using namespace std;


int main( )
{
    list<char> myList;
    myList.push_back('C');
    myList.push_back('D');
    myList.push_back('E');

    //Build at either end
    myList.push_front('B');
    myList.push_front('A');

//    //No random access! These are compiler errors
//    cout << myList[1] << endl;
//    cout << myList.at(1) << endl;


    //Use iterator to navigate:
    cout << "First thing:" << endl;
    list<char>::iterator iterator1 = myList.begin();
    cout << *iterator1 << endl;

    cout << "Next thing:" << endl;
    ++iterator1;
    cout << *iterator1 << endl;

    cout << "Back to first thing:" << endl;
    --iterator1;
    cout << *iterator1 << endl;

    cout << "Change first thing to Q" << endl;
    *iterator1 = 'Q';

    //Print forward
    for (list<char>::iterator myIt = myList.begin();
         myIt != myList.end();
         ++myIt)
    {
        cout << *myIt << " ";
    }
    cout << endl;


    cout << "Erasing item 2 places before end" << endl;
    auto iterator2 = myList.end();
    //must take one step at a time:
    iterator2--;
    iterator2--;
    myList.erase(iterator2);

    for (list<char>::iterator myIt = myList.begin();
         myIt != myList.end();
         ++myIt)
    {
        cout << *myIt << " ";
    }
    cout << endl;



    return 0;
}
