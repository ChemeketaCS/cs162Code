#include <iostream>
#include <string>

#include "PlayerList.h"

using namespace std;

int main() {
    PlayerList pList(3); // Create a PlayerList with space for 3 players
    pList.setPlayerName(0, "Alice");
    pList.setPlayerName(1, "Bob");
    pList.setPlayerName(2, "Carlos");
    pList.print();
    cout << "End of main, pList will be destroyed." << endl;
}
