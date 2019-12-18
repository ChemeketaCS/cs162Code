#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {

    ArrayList<char> letters;
    letters.append('U');
    letters.append('C');
    letters.append('L');
    letters.append('A');
    cout << letters << endl;

    cout << "Attempting to copy" << endl;
    ArrayList<char> letters2;
    letters2 = letters;

    cout << " Letters: " << letters << endl;
    cout << "Letters2: " << letters2 << endl;

    cout << "Changing Letters2..." << endl;
    letters[-1] = 'G';
    letters[3] = 'Y';

    cout << " Letters: " << letters << endl;
    cout << "Letters2: " << letters2 << endl;


    return 0;
}


