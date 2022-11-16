//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Tell clang analyzer to ignore doctest.h
#ifndef __clang_analyzer__
#include "doctest.h"
#endif

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include "sorts.h"

TEST_CASE( "slideToPosition" ) {
    vector<int> v {20, 10, 15, 30, 5};

    slideToPosition(v, 1);
    CHECK( to_string(v) == "[10, 20, 15, 30, 5]" );

    slideToPosition(v, 2);
    CHECK( to_string(v) == "[10, 15, 20, 30, 5]" );

    slideToPosition(v, 3);
    CHECK( to_string(v) == "[10, 15, 20, 30, 5]" );

    slideToPosition(v, 4);
    CHECK( to_string(v) == "[5, 10, 15, 20, 30]" );

    v.push_back(12);
    slideToPosition(v, 5);
    CHECK( to_string(v) == "[5, 10, 12, 15, 20, 30]" );
}


TEST_CASE( "insertionSort" ) {
    vector<int> v {20, 10, 15, 30, 5, 25, 35};

    insertionSort(v);
    CHECK( to_string(v) == "[5, 10, 15, 20, 25, 30, 35]" );
}