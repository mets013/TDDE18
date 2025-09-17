#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>

struct Time {
    int hours, 
        minutes, 
        seconds;
};

int convert_to_seconds(Time const& t);
// convert the time into seconds for easier handling

bool is_valid(Time const& t); 
// always const initally, 
// ampersand to not copy and make reference (performance)

std::string to_string(Time const& t, bool format_am_pm = false);
// 24 hour format will be default (we live in sweden duuuu)
// if they want am they will have to make it true

bool is_am(Time const& t);

Time operator+(Time const& t, int const& add_seconds);

Time operator+(int const& add_seconds, Time const& t);

Time operator-(Time const& t, int const& remove_seconds);   

Time& operator++(Time& t); 
// having & at Time not inside the () allows us to 
// reference the function so that doing ++(++t) 
// works without making a copy

Time operator++(Time& t, int);
// that is not needed here since doing t++ gives the value
// before incrementing it and a copy is needed, but
// t should still be incremented

Time& operator--(Time& t);

Time operator--(Time& t, int);

bool operator>(Time const& t1, Time const& t2);

std::ostream& operator<<(std::ostream& os, Time const& t);

#endif //TIME_H
