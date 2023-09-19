//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------

#include "sorts.h"


TEST_CASE( "placeLargestRemaining" ) {
    vector<int> v {20, 10, 15, 5, 30};

    placeLargestRemaining(v, 0);
    CHECK( to_string(v) == "[30, 10, 15, 5, 20]" );

    placeLargestRemaining(v, 1);
    CHECK( to_string(v) == "[30, 20, 15, 5, 10]" );

    placeLargestRemaining(v, 2);
    CHECK( to_string(v) == "[30, 20, 15, 5, 10]" );

    placeLargestRemaining(v, 3);
    CHECK( to_string(v) == "[30, 20, 15, 10, 5]" );
}


TEST_CASE( "selectionSort" ) {
    vector<int> v {20, 10, 15, 30, 5, 25, 35};

    selectionSort(v);
    CHECK( to_string(v) == "[35, 30, 25, 20, 15, 10, 5]" );
}

