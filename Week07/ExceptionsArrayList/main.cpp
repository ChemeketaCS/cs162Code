#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {

    ArrayList<char> letters;
    letters.append('H');
    letters.append('I');

    cout << letters << endl;

    bool success = false;
    do {
        cout << "What letter index do you want to change to X?";
        int changeLoc;
        cin >> changeLoc;
        try {
            letters[changeLoc] = 'X';
            success = true;
        } catch(out_of_range& e) {
            cout << e.what() << endl;
        }
    } while( !success );

    cout << letters << endl;

    return 0;
}


