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

#include "mergeSort.h"


TEST_CASE( "Merge/EqualHalves" ) {
    vector<int> data1 {1, 3, 4};
    vector<int> data2 {2, 5, 6};

    vector<int> result = merge(data1, data2);
    INFO(to_string(result));

    bool isSorted = std::is_sorted(result.begin(), result.end());
    REQUIRE( isSorted == true );

    vector<int> expected {1, 2, 3, 4, 5, 6};
    REQUIRE( result == expected );
}

TEST_CASE( "Merge/EqualHalvesReversed" ) {
    vector<int> data1 {2, 5, 6};
    vector<int> data2 {1, 3, 4};

    vector<int> result = merge(data1, data2);
    INFO(to_string(result));

    bool isSorted = std::is_sorted(result.begin(), result.end());
    REQUIRE( isSorted == true );

    vector<int> expected {1, 2, 3, 4, 5, 6};
    REQUIRE( result == expected );
}

TEST_CASE( "Merge/FirstLonger" ) {
    vector<int> data1 {1, 3, 4, 7, 8};
    vector<int> data2 {2, 5, 6};

    vector<int> result = merge(data1, data2);
    INFO(to_string(result));

    bool isSorted = std::is_sorted(result.begin(), result.end());
    REQUIRE( isSorted == true );

    vector<int> expected {1, 2, 3, 4, 5, 6, 7, 8};
    REQUIRE( result == expected );
}

TEST_CASE( "Merge/SecondLonger" ) {
    vector<int> data1 {1, 3, 4};
    vector<int> data2 {2, 5, 6, 7, 8};

    vector<int> result = merge(data1, data2);
    INFO(to_string(result));

    bool isSorted = std::is_sorted(result.begin(), result.end());
    REQUIRE( isSorted == true );

    vector<int> expected {1, 2, 3, 4, 5, 6, 7, 8};
    REQUIRE( result == expected );
}


TEST_CASE( "Slice1" ) {
    vector<int> source {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> result1 = slice(source, 0, 3);
    INFO(to_string(result1));
    REQUIRE( result1 == vector<int> {1, 2, 3} );
}

TEST_CASE( "Slice2" ) {
    vector<int> source {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> result2 = slice(source, 1, 5);
    INFO(to_string(result2));
    REQUIRE( result2 == vector<int> {2, 3, 4, 5} );
}

TEST_CASE( "Slice3" ) {
    vector<int> source {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> result3 = slice(source, 7, 8);
    INFO(to_string(result3));
    REQUIRE( result3 == vector<int> {8} );
}


TEST_CASE( "MergeSort" ) {
    vector<int> source {2, 5, 3, 4, 7, 1, 6, 8};
    vector<int> goal {1, 2, 3, 4, 5, 6, 7, 8};

    mergeSort(source);
    INFO(to_string(source));
    REQUIRE( source == goal );
}


