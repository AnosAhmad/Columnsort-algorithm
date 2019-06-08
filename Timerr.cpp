#include "Timerr.h"

//measure the running time in seconds

Timerr::Timerr()
{
	start_time = clock();
}

double Timerr::elapsed_timee()
{
	clock_t end_time = clock();

	return ((double)(end_time - start_time)) / ((double)CLK_TCK);
}

void Timerr::reset()
{
	start_time = clock();
}
