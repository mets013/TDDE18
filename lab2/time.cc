#include "time.h"
#include <string>
#include <iostream>
#include <istream>
#include <ostream>

int convert_to_seconds(Time const& t) {
   
    return ((t.hours * 3600 + t.minutes * 60 + t.seconds)% 86400);
   // conver the time into seconds adding % 86400 to make sure
   // that the time "flips over" if it becomes a new day

}

Time convert_to_time(int const& seconds) {
// convert the time from seconds back to "time"
    Time new_time{};

    new_time.hours   = (seconds/3600) % 24;
    new_time.minutes = (seconds/60) % 60;
    new_time.seconds = (seconds) % 60;
    // "apperently" int trunctates when we do division that
    // would produce floats, which is nice in this case
    // since we want whole numbers 5.9999 is 5 minutes and
    // 59 seconds (and some miliseconds) but never rounded
    // to 6 minutes.

    return new_time;

}

std::string format_clock_00(int const& t) {
    
    if (t < 10) { 
        // adds zero so that the formatting is correct
        return "0"+std::to_string(t);
            // normal to_string function, found on cpp-references
            // after googling how to convert int to string :)
    }
    else {
        return std::to_string(t);
    }

}

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

        time_string = format_clock_00(pm_hours)+":";
    }
    else { // here is 24 hour time
        time_string = format_clock_00(t.hours)+":";
    }

    time_string += format_clock_00(t.minutes)+":";
    time_string += format_clock_00(t.seconds);
    // seconds and minutes are the same for am-pm and 24 hour time

    if (format_am_pm) { 
    // since the string is concatenated from left to right this can't
    // be in the "am-pm" if-block above.
        if (t.hours > 11) {
            time_string += "[pm]";
        }
        else {
            time_string += "[am]";
        }
    }
    
    return time_string;

}

bool is_am(Time const& t) {
 
    return t.hours < 12;
    // quite simple, if the 24 hour clock is less than 12 it is am (true)
    // otherwise pm (false)
        
}

Time operator+(Time const& t, int const& add_seconds) {

    int total_seconds{};

    total_seconds = convert_to_seconds(t) + add_seconds;
                    // convert the time struct into just
                    // seconds and then add the added seconds

    return convert_to_time(total_seconds);

}

Time operator+(int const& add_seconds, Time const& t) {
    
    return t + add_seconds; 
    // found this on google, since we want it to be
    // commutative doing 5+t = t+5 so this works well
}

Time operator-(Time const& t, int const& remove_seconds) {
// almost same as for operator+, but we want it to go around
// an entire day if we remove for example 24*60*60 seconds
    int total_seconds{};

    total_seconds = ((convert_to_seconds(t) - remove_seconds) 
                    + 86400) % 86400;
    // to keep the time positive we add "one day" 
    // and then modulus with one day again to get the correct time

    return convert_to_time(total_seconds);
    // subtraction is not commutative and it doesn't really
    // show that  5 - t should be possible, what would
    // that give? should 5 seconds as an integer 
    // be the same as 00:00:05? se what lab-assistant says
}

Time& operator++(Time& t) {
// same approach as with the operator+ but 
// it will always be +1 instead of whatever
    int total_seconds{};

    total_seconds = convert_to_seconds(t) + 1;

    t = convert_to_time(total_seconds);
    // Cant just write return convert_to_time since
    // the function is reference/chain, but
    // covner_to_time is not.
    return t;
}

Time operator++(Time& t, int) {
    // from lecture one, a++ is suppose to
    // increment the value but return the value
    // before incrementing it
    Time before_increment{};
    before_increment = t;
    ++t;
    return before_increment;
}

Time& operator--(Time& t) {
    // same as operator- but just always -1
    int total_seconds{};

    total_seconds = (convert_to_seconds(t)-1 + 86400) % 86400;

    t = convert_to_time(total_seconds);

    return t;  

}

Time operator--(Time& t, int) {

    Time before_decrease{};
    before_decrease = t;
    --t;
    return before_decrease;

}

bool operator>(Time const& t1, Time const& t2) {
// we turn it into seconds and then compare the times
    return convert_to_seconds(t1) > convert_to_seconds(t2);

}

bool operator<(Time const& t1, Time const& t2) {
// same as the other logic comparison operators,
// turn everything to seconds then compare
    return convert_to_seconds(t1) < convert_to_seconds(t2);

}

bool operator==(Time const& t1, Time const& t2) {
    
    return convert_to_seconds(t1) == convert_to_seconds(t2);

}

bool operator!=(Time const& t1, Time const& t2) {
    
    return convert_to_seconds(t1) != convert_to_seconds(t2);

}

bool operator<=(Time const& t1, Time const& t2) {
    
    return convert_to_seconds(t1) <= convert_to_seconds(t2);

}

bool operator>=(Time const& t1, Time const& t2) {
    
    return convert_to_seconds(t1) >= convert_to_seconds(t2);

}

std::ostream& operator<<(std::ostream& os, Time const& t) {

    os << to_string(t);

    return os;

}

std::istream& operator>>(std::istream& is, Time& t) {

    char dump1, dump2;
    // we us chars inbetween the numbers and check that they are ":"

    is >> t.hours >> dump1 >> t.minutes >> dump2 >> t.seconds;
    if (is_valid(t) and dump1 == ':' and dump2 == ':') {

        return is;

    }
    else {

        is.setstate(std::ios_base::failbit);
        // raise th fail-flag if it is not the wanted format
        // i.e. HH:MM:SS
        return is;

    }


}