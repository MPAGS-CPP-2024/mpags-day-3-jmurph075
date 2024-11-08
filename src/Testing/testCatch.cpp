//! Test that catch works

// simple preprocessor define to tell Catch to provide a main() function for us
// this simplifies writing tests and will also provide several command line options 
// for the resulting executable (just like those we've been writing for mpags-cipher)
#define CATCH_CONFIG_MAIN
// just includes the single Catch header
#include "catch.hpp"

// args of TEST_CASE are strings describing the test and 
// "tags" that may be used to group tests.
TEST_CASE("Addition works", "[math]") {
    //inside, we add a boolean expression inside a REQUIRE call that asserts that the 
    // result of 1+1 is 2 (which should obviously be true)
    REQUIRE(1 + 1 == 2);
}
