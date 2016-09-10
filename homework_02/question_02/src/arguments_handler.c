#include <stdlib.h>

#include "arguments_handler.h"
#include "vector_handler.h"
#include "util.h"

int find_integers_amount(int argc, char* argv[])
{
	int integers_amount_parameter;
	int lowest_integers_amount;

	if(argc < 2) {
		return 0;
	}
	else {
		integers_amount_parameter = atoi(argv[INTEGERS_AMOUNT_PARAMETER_POSITION]);
	}

	lowest_integers_amount = lower_number(integers_amount_parameter, argc - FIRST_NUMBER_POSITION);
	lowest_integers_amount = lower_number(lowest_integers_amount, MAX_INTEGERS_NUMBER);

	return lowest_integers_amount;
}

int lower_number(int number1, int number2)
{
	if(number1 < number2) {
		return number1;
	}
	else {
		return number2;
	}
}

int* tranlaste_arguments_to_vector(int integers_amount, char* argv[])
{
	int* arguments_vector = initialize_vectors(integers_amount);

	int argument_counter = FIRST_NUMBER_POSITION;
	int vector_counter = 0;
	int current_value = 0;

	while(vector_counter < integers_amount) {
		current_value = atoi(argv[argument_counter]);
		arguments_vector[vector_counter] = current_value;

		vector_counter++;
		argument_counter++;
	}

	return arguments_vector;
}
