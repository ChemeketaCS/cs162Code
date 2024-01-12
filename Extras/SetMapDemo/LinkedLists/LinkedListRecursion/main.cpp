#include <iostream>

#include "Node.h"

using namespace std;

/**
 * @brief printFrom Recursively prints out the list starting from a given node
 * @param current Place to print from
 */
template<class T>
void printFrom(Node<T>* current) {
  if (current == nullptr) {
    cout << endl; // end of list - end the process
    return;
  }
  cout << current->element << " "; // print self
  printFrom(current->next);        // ask next Node to repeat
}

/**
 * @brief lengthFrom Recursively find the length of list
 * @param current Staring node
 * @return length of list from current on
 */
template<class T>
int lengthFrom(Node<T>* current) {
  if (current == nullptr) {
    return 0; // nothing past here
  }
  int allTheRest = lengthFrom(current->next); // ask next node for how many
  return 1 + allTheRest;                      // current's answer is 1 more
}

/**
 * @brief getLast Recursively find the last item in the list
 * @param current Staring node
 * @return last element in list
 *
 * @pre List must have at least one element
 */
template<class T>
T getLast(Node<T>* current) {
  if (current->next == nullptr) {
    // this must be last node
    return current->element;
  }
  return getLast(current->next);
}

int main() {
  Node<char>* head = new Node<char>('B');
  head->next = new Node<char>('C');
  head->next->next = new Node<char>('D');
  head->next->next->next = new Node<char>('E');

  printFrom(head);
  cout << "Length: " << lengthFrom(head) << endl;
  cout << "Last: " << getLast(head) << endl;
}
