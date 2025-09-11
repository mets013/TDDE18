#include "time.h"
#include <string>

using namespace std;

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