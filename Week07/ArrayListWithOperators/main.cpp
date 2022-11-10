#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {

    ArrayList<char> letters;
    letters.insertEnd('U');
    letters.insertEnd('C');
    letters.insertEnd('L');
    letters.insertEnd('A');
    cout << letters << endl;

    cout << "Attempting to copy" << endl;
    ArrayList<char> letters2;
    letters2 = letters;

    cout << " Letters: " << letters << endl;
    cout << "Letters2: " << letters2 << endl;

    cout << "Changing Letters2..." << endl;
    letters2[1] = 'G';

    cout << " Letters: " << letters << endl;
    cout << "Letters2: " << letters2 << endl;


    return 0;
}


