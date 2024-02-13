#include <iostream>
#include <string>

#include "Association.h"
#include "Pair.h"
using namespace std;

int main() {
  Pair<int> p1(3, 4);
  cout << p1.getLeft() << " " << p1.getRight() << endl;

  Pair<double> p2(1.5, -2.4);
  p2.setRight(7.5);
  cout << p2.getLeft() << " " << p2.getRight() << endl;

  Pair<int> p3(1, 2);

  // Make a pair of pairs of integers using p1 and p3
  Pair<Pair<int>> pairOfPairs(p1, p3);
  // Ask for the left hand part of the right half (p3's left value)
  cout << pairOfPairs.getRight().getLeft() << endl;

  Association<char, string> a1('a', "apple");

  cout << a1.getLeft() << " is for " << a1.getRight() << endl;

  return 0;
}
