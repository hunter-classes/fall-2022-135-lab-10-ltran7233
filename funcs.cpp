#include <iostream>
#include "funcs.h"
#include "time.h"

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
