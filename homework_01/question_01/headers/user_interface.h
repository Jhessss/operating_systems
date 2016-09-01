#include <stdio.h>
#include <stdio_ext.h>
#include "boolean.h"
#include "cartesian_structs.h"
#include "geometry.h"

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

typedef enum
{
	BAD_INPUT,
	SET_TRIANGLE,
	SHOW_SIZE_OF_SIDES,
	SHOW_EXISTENCE,
	SHOW_PERIMETER,
	SHOW_AREA,
	EXIT
} MainOption;

void show_intro();

void show_main_options_instructions();
MainOption get_main_options_input();
void show_main_options_output(MainOption option);

void show_set_triangle_instructions();
CartesianTriangle get_triangle_input();
void show_set_triangle_output(CartesianTriangle triangle);

void show_size_of_sides_instructions();
void show_size_of_sides_output(double* size_of_sides);

void show_existence_instructions();
void show_existence_output(Boolean exists);

void show_perimeter_instructions();
void show_perimeter_output(double perimeter);

void show_area_instructions();
void show_area_output(double area);

#endif // USER_INTERFACE_H
