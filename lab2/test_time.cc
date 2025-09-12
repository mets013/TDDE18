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
