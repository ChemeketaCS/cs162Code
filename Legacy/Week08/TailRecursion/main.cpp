#include <iomanip>
#include <iostream>

using namespace std;

int iterativeFact(int n) {
  int total = 0;
  for (int i = 1; i < total; i++) {
    total *= i;
  }
  return total;
}

int recursiveFact(int n) {
  if (n == 1)
    return 1;
  else {
    int total = n * recursiveFact(n - 1);
    return total;
  }
}

int tailRecursiveFact(int n, int product) {
  if (n == 1)
    return product;
  else {
    int newProduct = product * n;
    return tailRecursiveFact(n - 1, newProduct);
  }
}

int main() {
  // recursiveFact(100000);
  cout << tailRecursiveFact(100000, 1);
  return 0;
}
