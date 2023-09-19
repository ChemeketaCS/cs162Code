//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------

#include "binarySearch.h"

TEST_CASE( "BinarySearch/Find" ) {
    vector<int> smallNums {1, 3, 6, 8, 12, 13, 15, 17};

    //search for each item - confirm binarySearch finds it
    for(size_t i = 0; i < smallNums.size(); i++) {
        int value = smallNums[i];
        int loc = binarySearch(value, smallNums);
        INFO("Your location for " << value << " was " << loc);
        REQUIRE( loc != -1 );
        REQUIRE( smallNums[loc] == value );
    }
}

TEST_CASE( "BinarySearch/NonExistent" ) {
    vector<int> smallNums {1, 3, 6, 8, 12, 13, 15, 17};

    //Try a few non-existent items
    {
        int value = 0;
        int loc = binarySearch(value, smallNums);
        INFO("Your location for " << value << " was " << loc);
        REQUIRE( loc == -1 );
    }
    {
        int value = 9;
        int loc = binarySearch(value, smallNums);
        INFO("Your location for " << value << " was " << loc);
        REQUIRE( loc == -1 );
    }
    {
        int value = 22;
        int loc = binarySearch(value, smallNums);
        INFO("Your location for " << value << " was " << loc);
        REQUIRE( loc == -1 );
    }
}
