#include <iostream>
#include <string>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

std::string printTime(Time time)
{
	std::string ti = "";
	ti += std::to_string(time.h);
	ti += ":";
	if (time.m<10)
	{
		ti += "0";
	}
	ti += std::to_string(time.m);
	return ti;
}

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

std::string printMovie(Movie mv)
{
	std::string movie = "";
	std::string g;
	switch (mv.genre) {
		case ACTION		: g = "ACTION"; break;
		case COMEDY		: g = "COMEDY"; break;
		case DRAMA		: g = "DRAMA";  break;
		case ROMANCE	: g = "ROMANCE"; break;
		case THRILLER	: g = "THRILLER"; break;
	}
	movie += mv.title;
	movie += " ";
	movie += g;
	movie += " (";
	movie += std::to_string(mv.duration);
	movie += " min)";
	return movie;
}

std::string getTimeSlot(TimeSlot ts)
{
	std::string timeSlot = printMovie(ts.movie);
	timeSlot += " [starts at ";
	timeSlot += printTime(ts.startTime);
	timeSlot += ", ends by ";
	Time newTime = addMinutes(ts.startTime, ts.movie.duration);
	timeSlot += printTime(newTime);
	timeSlot += "]";
	
	return timeSlot;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
	Time nextTime = addMinutes(ts.startTime, ts.movie.duration);
	TimeSlot newMovie = {nextMovie, nextTime};
	return newMovie;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	bool overlap = false;
	int earlyTime = 0;
	int lateTime = 0;
	if (minutesUntil(ts1.startTime, ts2.startTime)<0) // ts2-ts1 is negative
	{
		earlyTime = minutesSinceMidnight(ts2.startTime);
		lateTime = minutesSinceMidnight(ts1.startTime);
		if (ts2.movie.duration > (lateTime-earlyTime))
		{
			overlap = true;
		}
	}
	else
	{
		earlyTime = minutesSinceMidnight(ts1.startTime);
		lateTime = minutesSinceMidnight(ts2.startTime);
		if (ts1.movie.duration > (lateTime-earlyTime))
		{
			overlap = true;
		}
	}
	return overlap;
}
