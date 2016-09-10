#include <sys/time.h>
#include <sys/resource.h>

#ifndef BENCHMARK_H
#define BENCHMARK_H

double get_time();
double get_time_elapsed(double initial_time);

#endif
