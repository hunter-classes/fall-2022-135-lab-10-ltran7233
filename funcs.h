#ifndef FUNCS_H
#define FUNCS_H

#include "time.h"
#include "movie.h"
#include "timeslot.h"

std::string printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string printMovie(Movie mv);
std::string getTimeSlot(TimeSlot ts);

#endif
