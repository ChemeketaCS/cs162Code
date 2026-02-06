#include <iostream>
#include <string>

#include "PlayerList.h"

using namespace std;

int main() {
  cout << "Start of main" << endl;

  PlayerList pList(3);
  pList.setPlayerName(0, "Alice");
  pList.setPlayerName(1, "Bob");
  pList.setPlayerName(2, "Carlos");

  PlayerList copy(pList); // use the copy constructor

  copy.setPlayerName(1, "Brian");
  cout << "copy after modifying: ";
  copy.print();
  cout << "pList after copying and modifying: ";
  pList.print();

  cout << "End of main" << endl;
}
