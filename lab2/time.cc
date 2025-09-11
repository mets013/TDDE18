#include "time.h"
#include <string>

bool is_valid(Time const& t) { 
    // always use const initally, 
    // ampersand to not make a copy (performance) 
   if (t.hours   >= 0 and t.hours   <= 23 and
       t.minutes >= 0 and t.minutes <= 59 and
       t.seconds >= 0 and t.seconds <= 59) {
       return true;
       }
    return false;
}

std::string to_string(Time const& t, bool hour_format) {

    std::string time_string{};

    if (t.hours < 10) { // adds 0 to the time for formatting
        time_string = "0"+std::to_string(t.hours)+":";
    }
    else {
        time_string = std::to_string(t.hours)+":";
    }

    if (t.minutes < 10) {
        time_string += "0"+std::to_string(t.minutes)+":";
    }
    else {
        time_string += std::to_string(t.minutes)+":";
    }

    if (t.seconds < 10) {
        time_string += "0"+std::to_string(t.seconds);
    }
    else {
        time_string += std::to_string(t.seconds);
    }

    if (hour_format == true) {
        if (t.hours > 11) {
            time_string += " pm";
        }
        else {
            time_string += " am";
        }
    }

    }
    // very repetitive :(


    return time_string;

}
