// Program to demonstrate a reverse iterator.
#include <iostream>
#include <vector>
using namespace std;

template<class T>
void print(const vector<T>& v) {
  for (auto myIt = v.begin(); myIt != v.end(); ++myIt) {
    cout << *myIt << " ";
  }
  cout << endl;
}

int main() {
  vector<char> container;

  container.push_back('A');
  container.push_back('B');
  container.push_back('C');
  container.push_back('D');
  container.push_back('E');

  cout << "First thing:" << endl;
  vector<char>::iterator iterator1 = container.begin();
  cout << *iterator1 << endl;

  cout << "Next thing:" << endl;
  ++iterator1;
  cout << *iterator1 << endl;

  cout << "Back to first thing:" << endl;
  --iterator1;
  cout << *iterator1 << endl;

  cout << "Forward:" << endl;
  // Print forward
  for (vector<char>::iterator myIt = container.begin(); myIt != container.end();
       ++myIt) {
    cout << *myIt << " ";
  }
  cout << endl;

  cout << "Reverse:" << endl;
  // Print in reverse
  for (vector<char>::reverse_iterator myRevIt = container.rbegin();
       myRevIt != container.rend(); ++myRevIt) {
    cout << *myRevIt << " ";
  }
  cout << endl;

  cout << "Inserting Q at index 2" << endl;
  vector<char>::iterator inLoc = container.begin() + 2;
  container.insert(inLoc, 'Q');
  print(container);

  cout << "Erasing item 2 places before end" << endl;
  auto iterator2 = container.end() - 2;
  container.erase(iterator2);
  print(container);

  cout << "Iterator used for erasing points to next item: ";
  cout << *iterator2 << endl;

  return 0;
}
