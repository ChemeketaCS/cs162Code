#include <iostream>

#include "Node.h"

using namespace std;

int main() {
  Node<int>* head = new Node<int>(10);
  Node<int>* tail = head;

  Node<int>* temp; // pointer to track new nodes

  // New node at head:
  temp = new Node<int>(8);
  temp->next = head;
  head = temp;

  // New node at tail:
  temp = new Node<int>(12);
  tail->next = temp;
  tail = temp;

  // Make a pointer to track our position
  Node<int>* current = head;
  // When we hit null, we've gotten to end
  while (current != nullptr) {
    cout << current->element << " "; // work
    // advance in the list
    current = current->next;
  }
  cout << endl;
}
