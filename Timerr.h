#ifndef TIMERR_H
#define TIMERR_H

#include "utility.h"

class Timerr
{
public:
	Timerr();
	double elapsed_timee();
	void reset();

private:
	clock_t start_time;
};
#endif //TIMERR_H
