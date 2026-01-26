#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Create a queue of integers
  queue<int> intQueue;

  // Add some integers to the queue
  intQueue.push(10);
  intQueue.push(20);
  intQueue.push(30);

  // Display and remove the item at the front of the queue
  cout << "Item at front of queue: " << intQueue.front() << endl;
  cout << "Removing item from front of queue." << endl;
  intQueue.pop();
  cout << "New item at front of queue: " << intQueue.front() << endl;

  // Display the item at the back of the queue and add another item
  cout << "Item at back of queue: " << intQueue.back() << endl;
  cout << "Adding another item (40) to the queue." << endl;
  intQueue.push(40);

  // Process the queue
  while (!intQueue.empty()) {
    // Get the item at the front of the queue
    int frontItem = intQueue.front();
    cout << "Processing item: " << frontItem << endl;
    // Remove the item from the front of the queue
    intQueue.pop();
  }

  cout << "All items processed, queue is now empty." << endl;
}