#include "catch_amalgamated.hpp"
#include "time.h"

TEST_CASE("is_valid") {
    // check stuff that should work
    CHECK( is_valid({10, 10, 10}) );
    CHECK( is_valid({ 0,  0,  0}) );
    CHECK( is_valid({23, 59, 59}) );

    // check stuff that shouldn't
    CHECK_FALSE( is_valid({ 24,  24,  24}) );
    CHECK_FALSE( is_valid({-10, -10, -10}) );
    CHECK_FALSE( is_valid({  1,  60,  60}) );
    CHECK_FALSE( is_valid({ 23,  59,  60}) );
    CHECK_FALSE( is_valid({  0,  -1,   0}) );
    CHECK_FALSE( is_valid({ -1,  59,  59}) );
}

TEST_CASE("to_string") {

    CHECK( to_string({1, 1, 1}, false) == "01:01:01" );
    CHECK( to_string({11, 11, 11}, true) == "11:11:11 am");
    CHECK( to_string({12, 12, 12}, true) == "12:12:12 pm");
    CHECK( to_string({23, 23, 23}, true) == "11:23:23 pm");
}