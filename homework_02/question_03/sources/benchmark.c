#include "benchmark.h"

double get_time()
{
	struct timeval value;
	struct timezone zone;
	gettimeofday(&value, &zone);

	return value.tv_sec + value.tv_usec*1e-6;
}

double get_time_elapsed(double initial_time)
{
	return get_time() - initial_time;
}
