#include <iostream>
#include "funcs.h"

int main()
{
	Time now = {10, 30};
	Time later = {13, 40};
	std::cout << "Task A: " << std::endl;
	std::cout << minutesSinceMidnight(now) << " minutes since midnight" << std::endl;
	std::cout << minutesUntil(now, later) << " between the two times" << std::endl;
	return 0;
}
