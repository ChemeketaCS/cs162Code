#include <iostream>

using namespace std;



int main()
{
    int i = 100;
    int* p = &i;

    cout << p << " : " << *p << endl;

    return 0;
}
