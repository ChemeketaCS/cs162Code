#include <iostream>

using namespace std;

int* firstNEvenNumbers(int n) {
  // Create an array on the heap with n elements
  int* numList = new int[n];

  for (int i = 0; i < n; i++) {
    numList[i] = (i + 1) * 2;
  }

  // Return the pointer with start of array
  return numList;
}

int main() {
  cout << "How man numbers do you want? ";
  int size;
  cin >> size;

  // call function, get back address or array
  int* nums = firstNEvenNumbers(size);
  // use pointer as array
  for (int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }

  return 0;
}
