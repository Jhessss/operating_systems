#include <stdio.h>
#include <stdlib.h>

#include "arguments_handler.h"
#include "vector_handler.h"
#include "benchmark.h"

int main(int argc, char* argv[])
{
	int integers_amount;
	int* vector_v;
	int max;
	int position;

	struct timespec initial_time;

	if(argc < 3) {
		printf("número de argumentos inválido!\n");
		return 0;
	}
	else {
		initial_time = get_time();
		integers_amount = find_integers_amount(argc, argv);
		vector_v = tranlaste_arguments_to_vector(integers_amount, argv);
	}

	max = vector_v[0];
	position = 0;
	int counter = 0;

	while(counter < integers_amount) {
		if(vector_v[counter] > max) {
			max = vector_v[counter];
			position = counter;
		}
		counter++;
	}

	printf("Number of input values = %d\n", integers_amount);
	printf("Input values x = ");
	print_vector(vector_v, integers_amount);
	printf("Maximum = %d\n", max);
	printf("Location = %d\n", position);

	unsigned long long int elapsed = get_time_elapsed(initial_time);

	printf("\n\nElapsed time: %llu ns \n\n", elapsed);

	free(vector_v);

	return 0;

}