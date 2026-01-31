#include <iostream>
using namespace std;

#include "TemplateLibrary.h"
#include "PlainLibrary.h"

int main() {
    // Use templated function
    cout << myMax(3, 7) << endl;
    
    // Use non-templated function
    cout << areSame(5, 5) << endl;
}