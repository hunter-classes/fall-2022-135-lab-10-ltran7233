#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int minutesSinceMidnight(Time time)
{
	int hours_convert = time.h * 60; 
	return hours_convert + time.m;
}

int minutesUntil(Time earlier, Time later)
{
	int earlier_hour = earlier.h * 60;
	int later_hour = later.h * 60;
	return (later_hour + later.m) - (earlier_hour + earlier.m);
}

Time addMinutes(Time time0, int min)
{
	int time0_add = ((time0.h * 60) + time0.m) + min;
	Time newTime = {time0_add/60, time0_add%60};
	return newTime;
}

void printMovie(Movie mv)
{
	std::string g;
	switch (mv.genre) {
		case ACTION		: g = "ACTION"; break;
		case COMEDY		: g = "COMEDY"; break;
		case DRAMA		: g = "DRAMA";  break;
		case ROMANCE	: g = "ROMANCE"; break;
		case THRILLER	: g = "THRILLER"; break;
	}
	std::cout << mv.title << " " << g << " (" << mv.duration << " min)" << std::endl;
}

