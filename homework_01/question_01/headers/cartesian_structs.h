#include <stdlib.h>

#ifndef CARTESIAN_STRUCTS_H
#define CARTESIAN_STRUCTS_H

typedef struct
{
	long long x;
	long long y;
} CartesianPoint;

typedef struct
{
	CartesianPoint a;
	CartesianPoint b;
	CartesianPoint c;
} CartesianTriangle;
#endif // CARTESIAN_STRUCTS_H
