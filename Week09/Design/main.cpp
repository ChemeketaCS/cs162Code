#include <iostream>
using namespace std;

int addDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int lastDigit = n % 10; // Get the last digit
        sum += lastDigit;
        n /= 10; // Remove the last digit
    }
    return sum;
}

// int addDigits(int n) {
//   if (n < 10) {
//       return n; // base case: single digit
//   } else {
//       int lastDigit = n % 10; // get the last digit
//       int remainingDigits = n / 10; // remove the last digit
//       int nextSum = addDigits(remainingDigits); // recursive call
//       int sum = nextSum + lastDigit; // add last digit to the response
//       return sum;
//   }
// }

// int addDigits(int n) {
//   if (n < 10) {
//       return n;
//   } else {
//       return addDigits(n / 10) + (n % 10);
//   }
// }

int main() {
    int number = 532;
    int digitSum = addDigits(number);
    cout << "The sum of digits in " << number << " is: " << digitSum << endl;
}
