#include <iostream>

using namespace std;

////Plain
// int fact(int n) {
//     if(n == 0) {
//         return 1;
//     } else {
//         return n * fact(n-1);
//     }
// }

// Two steps to make tracing easier
// int fact(int n) {
//     if(n == 0) {
//         return 1;
//     } else {
//         int value = n * fact(n-1);
//         return value;
//     }
// }

////Print lots of info as functions runs
int fact(int n) {
  if (n == 0) {
    cout << "Working on fact(0)... Answer is 1" << endl;
    return 1;
  } else {
    cout << "Working on fact(" << n << ")..." << endl;

    int value = n * fact(n - 1);

    cout << "Done with fact(" << n << ")...  answer is " << value << endl;
    return value;
  }
}

int main() {
  cout << fact(4) << endl;

  return 0;
}
