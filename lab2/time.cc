#include "time.h"
#include <string>

bool is_valid(Time const& t) { 
    // always use const initally, 
    // ampersand to not make a copy / make 
    // reference instead (performance)
    return (t.hours   >= 0 and t.hours   <= 23 and
            t.minutes >= 0 and t.minutes <= 59 and
            t.seconds >= 0 and t.seconds <= 59); 
            // someone said on the lecture you could do this! :)
}

std::string to_string(Time const& t, bool format_am_pm) {

    std::string time_string{};

    if (format_am_pm) { 
        int pm_hours{}; // only declare it if it is needed
    
        pm_hours = t.hours % 12;
        // converts 24 hour to am-pm by checking what's the 
        // rest after dividing with 12 (modulus)
        if (pm_hours == 0) {
            pm_hours = 12; // since 0 or 24 hours is 12 am
        }

        if (pm_hours < 10) { 
        // adds zero so that the formatting is correct
            time_string ="0"+std::to_string(pm_hours)+":";
            // normal to_string function, found on cpp-references
            // after googling how to convert int to string :)
        }
        else {
            time_string = std::to_string(pm_hours)+":";
        }
    }
    else { // here is 24 hour time
        if (t.hours <10) {
             time_string ="0"+std::to_string(t.hours)+":";
        }
        else {
            time_string = std::to_string(t.hours)+":";
        }
    }

    if (t.minutes < 10) { 
    // minutes and seconds are the same for 24 hour or am-pm
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

    if (format_am_pm) { 
    // since the string is concatenated from left to right this can't
    // be in the "am-pm" if-block above.
        if (t.hours > 11) {
            time_string += " pm";
        }
        else {
            time_string += " am";
        }
    }

    return time_string;

}
    // very repetitive :( maybe create a function for this? ask at lab session

bool is_am(Time const& t) {
 
    return t.hours < 12;
    // quite simple, if the 24 hour clock is less than 12 it is am (true)
    // otherwise pm (false)
        
}

Time operator+(Time const& t, int const& add_seconds) {

    Time new_time{};
    
    // if you add something larger that 60 seconds it should 
    // add onto minutes and hours
    new_time.seconds = t.seconds + (add_seconds % 60);
    new_time.minutes = t.minutes + ((add_seconds - new_time.seconds)/60) % 60;
    new_time.hours   = t.hours   + (((add_seconds - new_time.seconds)/60)
                                      - new_time.minutes) % 60;

    return new_time;

}

Time operator+(int const& add_seconds, Time const& t) {

    Time new_time{};
    
    // if you add something larger that 60 seconds it should 
    // add onto minutes and hours
    new_time.seconds = t.seconds + (add_seconds % 60);
    new_time.minutes = t.minutes + ((add_seconds - new_time.seconds)/60) % 60;
    new_time.hours   = t.hours   + (((add_seconds - new_time.seconds)/60)
                                      - new_time.minutes) % 60;

    return new_time;

}
