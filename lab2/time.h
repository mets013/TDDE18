#ifndef TIME_H
#define TIME_H
#include <string>

struct Time {
    int hours, 
        minutes, 
        seconds;
};

bool is_valid(Time const& t); 
// always const initally, ampersand to not copy 

std::string to_string(Time t, bool format_am_pm = false);
// 24 hour format will be default, if they want am they will have to make it false
// hour_format not const or reference time since it will be changed

#endif //TIME_H
