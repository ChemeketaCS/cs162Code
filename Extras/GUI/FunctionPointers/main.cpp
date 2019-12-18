#include <iostream>

using namespace std;

void printNum(int x) {
    cout << x << endl;
}

void printDoubleNum(int x) {
    cout << 2 * x << endl;
}

int main()
{
    cout << "Enter 1 or 2:";
    int choice;
    cin >> choice;

    //mysteryPtr is a pointer to a void function that takes an int
    void (*mysteryPtr) (int);

    if(choice == 1)
        mysteryPtr = printNum;         //point to printNum function
    else
        mysteryPtr = printDoubleNum;   //point to printDoubleNum function

    mysteryPtr(1000);                  //call pointed to function, pass 1000

    return 0;
}
