#include "user_interface.h"

MainOption get_main_option(CartesianTriangle triangle);
void handle_main_option(MainOption main_input, CartesianTriangle *triangle);

void set_triangle(CartesianTriangle *triangle);
void show_size_of_sides(CartesianTriangle triangle);
void show_existence(CartesianTriangle triangle);
void show_perimeter(CartesianTriangle triangle);
void show_area(CartesianTriangle triangle);

int main()
{
	show_intro();

	// Main Loop
	CartesianTriangle triangle;
	triangle.a.x = triangle.a.y = triangle.b.x = triangle.b.y
		= triangle.c.x = triangle.c.y = 0.0;
	MainOption main_input = EXIT;
	do
	{
		main_input = get_main_option(triangle);
		handle_main_option(main_input, &triangle);
	} while(main_input != EXIT);

	return 0;
}

/*
 *	Main Screen
 */
MainOption get_main_option(CartesianTriangle triangle)
{
	// Validating Main User's Option Input
	MainOption main_input = BAD_INPUT;
	do
	{
		show_main_options_instructions(triangle);
		main_input = get_main_options_input();
	} while(main_input == BAD_INPUT);

	// Show Option Input to the User
	show_main_options_output(main_input);

	// Return User's Option
	return main_input;
}

/*
 *	Go to Feature chose by User
 */
void handle_main_option(MainOption main_input, CartesianTriangle *triangle)
{
	switch(main_input)
	{
		case SET_TRIANGLE:
			set_triangle(triangle);
			break;

		case SHOW_SIZE_OF_SIDES:
			show_size_of_sides(*triangle);
			break;

		case SHOW_EXISTENCE:
			show_existence(*triangle);
			break;

		case SHOW_PERIMETER:
			show_perimeter(*triangle);
			break;

		case SHOW_AREA:
			show_area(*triangle);
			break;

		case BAD_INPUT:
			break;

		case EXIT:
			break;
	}
}

void set_triangle(CartesianTriangle *triangle)
{
	show_set_triangle_instructions();
	*triangle = get_triangle_input();
	show_set_triangle_output(*triangle);
}

void show_size_of_sides(CartesianTriangle triangle)
{
	show_size_of_sides_instructions();
	double *sides_size = size_of_sides(triangle);
	show_size_of_sides_output(sides_size);
}

void show_existence(CartesianTriangle triangle)
{
	show_existence_instructions();
	show_existence_output(exists(triangle));
}

void show_perimeter(CartesianTriangle triangle)
{
	show_perimeter_instructions();
	show_perimeter_output(perimeter(triangle));
}

void show_area(CartesianTriangle triangle)
{
	show_area_instructions();
	show_area_output(area(triangle));
}
