#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {

    ArrayList<char> letters;
    letters.append('U');
    letters.append('C');
    letters.append('L');
    letters.append('A');
    cout << letters.toString() << endl;

    cout << "Adding a Q at index 1..." << endl;
    letters.insertAt(1, 'Q');
    cout << letters.toString() << endl;

    cout << "Setting item at index 1 to H..." << endl;
    letters.set(1, 'H');
    cout << letters.toString() << endl;

    cout << "Removing item at index 1..." << endl;
    letters.removeAt(1);
    cout << letters.toString() << endl;


    cout << "Looking for L..." << endl;
    int uLoc = letters.search('L');
    cout << "Found at " << uLoc << endl;

    cout << "Looking for X..." << endl;
    int xLoc = letters.search('X');
    cout << "Found at " << xLoc << endl;


    cout << "Copying and sorting copy..." << endl;
    ArrayList<char> letters2(letters);
    letters2.sort();
    cout << "Original: " << letters.toString() << endl;
    cout << "Copy:     " << letters2.toString() << endl;

    cout << "Erasing the list and then adding 'R'" << endl;
    letters.clear();
    letters.append('R');
    cout << letters.toString() << endl;

    return 0;
}


