#include "ArrayList.h"
#include <iostream>

using namespace std;

int main() {
  ArrayList<char> letters;
  letters.insertEnd('U');
  letters.insertEnd('C');
  letters.insertEnd('L');
  letters.insertEnd('A');
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

  cout << "Copying the list..." << endl;
  ArrayList<char> letters2(letters);

  cout << "Original: " << letters.toString() << endl;
  cout << "Copy:     " << letters2.toString() << endl;

  cout << "Erasing the original list and then adding 'R' to it" << endl;
  letters.clear();
  letters.insertEnd('R');

  cout << "Original: " << letters.toString() << endl;
  cout << "Copy:     " << letters2.toString() << endl;

  return 0;
}
