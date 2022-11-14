#include <iostream>
#include "funcs.h"

int main()
{
	Time now = {10, 30};
	Time later = {13, 40};
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	TimeSlot morning = {movie1, {9, 15}};
	TimeSlot daytime = {movie2, {12, 15}}; 
	TimeSlot evening = {movie2, {16, 45}}; 
	
	std::cout << "Task A: " << std::endl;
	std::cout << minutesSinceMidnight(now) << " min since midnight" << std::endl;
	std::cout << minutesUntil(now, later) << " min between the two times" << std::endl;
	
	std::cout << "Task B: " << std::endl;
	Time add = addMinutes(now, 60);
	std::cout << "Time: " << add.h << ":" << add.m << std::endl;
	printMovie(movie1);
	return 0;
}
