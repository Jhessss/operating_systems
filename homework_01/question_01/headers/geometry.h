#include <stdlib.h>
#include <math.h>
#include "cartesian_structs.h"
#include "boolean.h"

#ifndef GEOMETRY_H
#define GEOMETRY_H

double *size_of_sides(CartesianTriangle triangle);
Boolean exists(CartesianTriangle triangle);
double perimeter(CartesianTriangle triangle);
double area(CartesianTriangle triangle);

#endif // GEOMETRY_H
