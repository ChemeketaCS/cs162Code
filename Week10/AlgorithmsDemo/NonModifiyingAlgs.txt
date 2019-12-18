#include <iostream>
#include <algorithm>
#include <vector>


bool isOdd(int num) {
    return num % 2 == 1;
}


using namespace std;

int main()
{
    cout << boolalpha;

    vector<int> vec {12, 3, 42, 6, 6, 18, 6};

    cout << "Starting contents: ";
    for(auto val : vec)
        cout << val << " ";
    cout << endl;

    int num6s = count(vec.begin(), vec.end(), 6);
    cout << "Count 6's: " << num6s << endl;

    //Find smallest item
    auto minItr = min_element(vec.begin(), vec.end());
    cout << "Minimum: " << *minItr << endl;
    cout << "Minimum is at: " << (minItr - vec.begin()) << endl;

    //Check to see if two vectors are the same
    vector<int> vec2 {12, 3, 42, 6, 6, 18, 6};
    bool areEqual = equal(vec.begin(), vec.end(), vec2.begin());
    cout << "Are v1 and v2 equal? " <<  areEqual << endl;

    //Count number of odd items
    int oddCount = count_if(vec.begin(), vec.end(), isOdd);
    cout << "Count odd's: " << oddCount << endl;

    return 0;
}
