#include <iostream>
#include "funcs.h"

int main()
{
	Time now = {10, 30};
	Time later = {13, 40};
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	Movie movie3 = {"Jaws", THRILLER, 124};
	Movie movie4 = {"Titanic", ROMANCE, 194};
	Movie movie5 = {"Parasite", DRAMA, 132};
	TimeSlot morning = {movie1, {9, 15}};
	TimeSlot daytime = {movie2, {12, 15}};
	TimeSlot evening = {movie2, {16, 45}};
	TimeSlot early_afternoon = {movie3, {13, 5}};
	TimeSlot mid_afternoon = {movie4, {14, 30}};
	TimeSlot late_afternoon = {movie5, {16, 35}};
	
	std::cout << "Task A: " << std::endl;
	std::cout << minutesSinceMidnight(now) << " min since midnight" << std::endl;
	std::cout << minutesUntil(now, later) << " min between the two times" << std::endl;
	
	std::cout << "Task B: " << std::endl;
	Time add = addMinutes(now, 60);
	std::cout << "Time: " << printTime(add) << std::endl;
	
	std::cout << "Task C: " << std::endl;
	std::cout << getTimeSlot(morning) << std::endl;
	
	std::cout << "Task D: " << std::endl;
	TimeSlot nextMovie = scheduleAfter(morning, movie2);
	std::cout << printMovie(nextMovie.movie) << " starts at " << printTime(nextMovie.startTime) << std::endl;
	
	std::cout << "Task E: " << std::endl;
	bool check = timeOverlap(evening, late_afternoon);
	std::cout << "Do the timeSlots late_afternoon and evening overlap?: " << check << std::endl; // true
	
	return 0;
}
