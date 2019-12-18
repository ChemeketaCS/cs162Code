#include <iostream>
using namespace std;

//Make and return pointer on the heap
int* getGoodPointerToTen() {
    int* px = new int;
    *px = 10;
    return px;
}

void foo() {
    int z = 5;
}

int main() {
    int* pTen = getGoodPointerToTen();

    cout << *pTen << endl;
    foo();
    cout << *pTen << endl;

    return 0;
}
