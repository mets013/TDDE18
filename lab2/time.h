#ifndef TIME_H
#define TIME_H
#include <string>

struct Time {
    int hours, 
        minutes, 
        seconds;
};

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

Time operator++(Time& t, int);

#endif //TIME_H
