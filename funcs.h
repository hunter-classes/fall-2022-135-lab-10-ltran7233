#ifndef FUNCS_H
#define FUNCS_H

#include "time.h"
#include "movie.h"
#include "timeslot.h"

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);

#endif
