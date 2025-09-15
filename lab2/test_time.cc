#include "catch_amalgamated.hpp"
#include "time.h"

TEST_CASE("is_valid") {
    // Should work
    CHECK( is_valid({10, 10, 10}) ); 
    CHECK( is_valid({ 0,  0,  0}) );  
    CHECK( is_valid({23, 59, 59}) );

    // Shoudln't
    CHECK_FALSE( is_valid({ 24,  24,  24}) );
    CHECK_FALSE( is_valid({-10, -10, -10}) );
    CHECK_FALSE( is_valid({  1,  60,   0}) ); 
    CHECK_FALSE( is_valid({ 23,  59,  60}) );
}

TEST_CASE("to_string") {

    // am-pm tests, edge cases and stuff
    CHECK( to_string({ 0,  0,  0}, true)  == "12:00:00 am" );      
    CHECK( to_string({12,  0,  0}, true)  == "12:00:00 pm" );    
    CHECK( to_string({ 9,  5,  7}, true)  == "09:05:07 am" );   
    CHECK( to_string({23, 59, 59}, true)  == "11:59:59 pm" );
    CHECK( to_string({15,  7,  9}, true)  == "03:07:09 pm" );
    
    // some 24 hour tests
    CHECK( to_string({ 9,  5,  7}, false) == "09:05:07" ); 
    CHECK( to_string({ 0,  0,  0}, false) == "00:00:00" );   
}

TEST_CASE("is_am") {

    CHECK( is_am({ 0,  0,  0}) == true );
    CHECK( is_am({23, 23, 23}) == false );
    CHECK( is_am({11, 11, 11}) == true );
    CHECK( is_am({12, 12, 12}) == false );

    CHECK_FALSE( is_am({10, 10, 10}) == false);

}

TEST_CASE("operator+") {

    Time t{};

    // using to_string since == is not defined for Time struct.
    CHECK( to_string(t + 5, false) == "00:00:05" );
    CHECK( to_string(5 + t, false) == "00:00:05" );
    CHECK( to_string(61 + t, false) == "00:01:01" );
    CHECK( to_string(3700 + t, false) == "01:01:40" );
    CHECK( to_string(t + 3700, true) == "01:01:40 am");

    t = {12,12,12};

    CHECK( to_string(t+5, false) == "12:12:17" );
    CHECK( to_string(3700+t, true) == "01:13:52 pm");

}

TEST_CASE("operator-") {

    Time t{};

    CHECK( to_string(t -5, false) == "23:59:55" );

    t = {12,40,50};

    CHECK( to_string(t-3700, false) == "11:39:10" );

}
