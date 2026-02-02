#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

// int factorial(int n) {
//     if (n == 0) {
//         cout << "Returning 1 for factorial(0)" << endl;
//         return 1;
//     } else {
//         int nMinusOneAnswer = factorial(n - 1);
//         int result = n * nMinusOneAnswer;
//         cout << "Returning " << result 
//              << " for factorial(" << n << ")" << endl;
//         return result;
//     }
// }

int main() {
    int fact = factorial(5);
    cout << "Factorial of 5 is: " << fact << endl;
}
