#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Task A tests")
{
	Time one = {8, 45};
	Time two = {9, 5};
	CHECK(minutesSinceMidnight(one)==525);
	CHECK(minutesSinceMidnight(two)==545);
	
	CHECK(minutesUntil(one, two)==20);
	CHECK(minutesUntil(two, one)==-20);
}

TEST_CASE("Task B tests")
{
	Time one = {11, 30};
	Time two = {13, 25};
	
	Time add = addMinutes(one, 45);
	CHECK(printTime(add)=="12:15");
	
	Time add2 = addMinutes(two, 50);
	CHECK(printTime(add2)=="14:15");
}

TEST_CASE("Task C tests")
{
	Movie movie3 = {"Jaws", THRILLER, 124};
	Movie movie4 = {"Titanic", ROMANCE, 194};
	
	TimeSlot early_afternoon = {movie3, {13, 5}};
	TimeSlot mid_afternoon = {movie4, {14, 30}};
	
	CHECK(getTimeSlot(early_afternoon)=="Jaws THRILLER (124 min) [starts at 13:05, ends by 15:09]");
	CHECK(getTimeSlot(mid_afternoon)=="Titanic ROMANCE (194 min) [starts at 14:30, ends by 17:44]");
}

TEST_CASE("Task D tests")
{
	Movie movie2 = {"Black Panther", ACTION, 134};
	Movie movie5 = {"Parasite", DRAMA, 132};
	TimeSlot daytime = {movie2, {12, 15}};
	
	TimeSlot nextMovie = scheduleAfter(daytime, movie5);
	
	CHECK(printMovie(nextMovie.movie)=="Parasite DRAMA (132 min)");
	CHECK(printTime(nextMovie.startTime)=="14:29");
}

TEST_CASE("Task E tests")
{
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	Movie movie3 = {"Jaws", THRILLER, 124};
	
	TimeSlot morning = {movie1, {9, 15}};
	TimeSlot daytime = {movie2, {12, 15}};
	TimeSlot early_afternoon = {movie3, {13, 5}};
	
	CHECK(timeOverlap(morning, daytime)==0);
	CHECK(timeOverlap(daytime, early_afternoon)==1);
	CHECK(timeOverlap(early_afternoon, morning)==0);
}
