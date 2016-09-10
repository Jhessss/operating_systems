#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "vector_handler.h"
#include "thread_handler.h"

int* initialize_vectors(int integers_amount)
{
	int* vector = (int*) malloc(integers_amount * sizeof(int));

	return vector;
}

pthread_t* initialize_thread_vectors(int threads_amount)
{
	pthread_t* vector = (pthread_t*) malloc(threads_amount * sizeof(pthread_t));
	return vector;
}

struct thread_w_arguments* initialize_thread_w_arguments_vectors(int arguments_amount)
{
	struct thread_w_arguments* args_vector = (struct thread_w_arguments*) malloc(arguments_amount * 
		sizeof(struct thread_w_arguments));

	return args_vector;
}

struct second_step_threads_arguments* initialize_second_threads_arguments(int arguments_amount)
{
	struct second_step_threads_arguments* args_vector = (struct second_step_threads_arguments*)
		malloc(arguments_amount * sizeof(struct second_step_threads_arguments));

	return args_vector;
}

void print_vector(int* vector, int integers_amount)
{
	int counter = 0;
	while(counter < integers_amount) {
		printf("%d ", vector[counter]);
		counter++;
	}

	printf("\n");

	return;
}