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

//Include your .h files
#include "Circle.h"

#include <cmath>
using namespace std;



TEST_CASE( "Circle/No-arg constructor" ) {
    Circle c1;
    CHECK( c1.getX() == 0 ); //NO NO NO
    CHECK( c1.getY() == Approx(0) );
    CHECK( c1.getRadius() == Approx(1) );
}

TEST_CASE( "Circle/1-arg constructor" ) {
    Circle c1(3.3);
    CHECK( c1.getX() == Approx(0) );
    CHECK( c1.getY() == Approx(0) );
    CHECK( c1.getRadius() == Approx(3.3) );

    Circle c2(-4); //test negative value - should be made positive
    CHECK( c2.getRadius() == Approx(4) );
}

TEST_CASE( "Circle/3-arg constructor" ) {
    Circle c1(3.0, 4.1, 5.2);
    CHECK( c1.getX() == Approx(4.1) );
    CHECK( c1.getY() == Approx(5.2) );
    CHECK( c1.getRadius() == Approx(3.0) );
}

TEST_CASE( "Circle/getArea" ) {
    Circle c1(5, 0, 0);
    double area = c1.getArea();
    CHECK( area == Approx(78.5) );
}

TEST_CASE( "Circle/setRadius" ) {
    Circle c1;
    c1.setRadius(4);
    CHECK( c1.getRadius() == Approx(4) );
}

TEST_CASE( "Circle/setRadius negative" ) {
    Circle c1;
    c1.setRadius(-2);   //should be converted to +2
    CHECK( c1.getRadius() == Approx(2) );
}
