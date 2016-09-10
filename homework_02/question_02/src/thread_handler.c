#include "thread_handler.h"

#include <stdio.h>
#include <stdlib.h>

void* fill_vector_w(void* thread_arguments)
{
	struct thread_w_arguments* thread_args = (struct thread_w_arguments*) thread_arguments;
	thread_args->vector_w[thread_args->vector_position] = 1;
	return NULL;
}

void* verify_vector_w(void* thread_arguments)
{
	struct thread_w_arguments* thread_args = (struct thread_w_arguments*) thread_arguments;

	if(thread_args->vector_w[thread_args->vector_position] == 0) {
		pthread_exit(NULL);
	}
	else {
		printf("Maximum = %d\n", thread_args->vector_v[thread_args->vector_position]);
		printf("Location = %d\n", thread_args->vector_position);
	}

	return NULL;
}

void create_threads_w(pthread_t* threads, struct thread_w_arguments* thread_args, int* vector_v,
	int* vector_w, int threads_amount)
{
	int counter = 0;
	while(counter < threads_amount) {
		thread_args[counter].vector_w = vector_w;
		thread_args[counter].vector_v = vector_v;
		thread_args[counter].vector_position = counter;
		pthread_create(&threads[counter], NULL, &fill_vector_w, &thread_args[counter]);
		counter++;
	}
}

void create_second_step_threads(pthread_t* threads, struct second_step_threads_arguments* thread_args,
	int* vector_v, int* vector_w, int integers_amount)
{
	int i_counter = 0;
	int j_counter = 1;
	int vector_position = 0;

	while(i_counter < integers_amount - 1) {
		j_counter = i_counter + 1;
		while(j_counter < integers_amount) {
			thread_args[vector_position].vector_v = vector_v;
			thread_args[vector_position].vector_w = vector_w;
			thread_args[vector_position].first_position = i_counter;
			thread_args[vector_position].second_position = j_counter;
			
			pthread_create(&threads[vector_position], NULL, &second_step, &thread_args[vector_position]);

			j_counter++;
			vector_position++;

		}
		i_counter++;
	}
}

void create_third_step_threads(pthread_t* threads, struct thread_w_arguments* thread_args, int* vector_v,
	int* vector_w, int threads_amount)
	{
		int counter = 0;

		while(counter < threads_amount) {
			pthread_create(&threads[counter], NULL, &verify_vector_w, &thread_args[counter]);
			counter++;
		}
	}

void* second_step(void* thread_arguments)
{
	struct second_step_threads_arguments* thread_args = (struct second_step_threads_arguments*) thread_arguments;

	if(thread_args->vector_v[thread_args->first_position] < thread_args->vector_v[thread_args->second_position]) {
		thread_args->vector_w[thread_args->first_position] = 0;

		printf("Thread T(%d, %d) compares x[%d] = %d and x[%d] = %d, and writes 0 into w[%d]\n", thread_args->first_position, thread_args->second_position, 
		thread_args->first_position, thread_args->vector_v[thread_args->first_position],
		thread_args->second_position, thread_args->vector_v[thread_args->second_position], thread_args->first_position);
	}
	else {
		thread_args->vector_w[thread_args->second_position] = 0;
		printf("Thread T(%d, %d) compares x[%d] = %d and x[%d] = %d, and writes 0 into w[%d]\n", thread_args->first_position, thread_args->second_position, 
		thread_args->first_position, thread_args->vector_v[thread_args->first_position],
		thread_args->second_position, thread_args->vector_v[thread_args->second_position], thread_args->second_position);
	}

	return NULL;
}

void join_threads(pthread_t* threads, int threads_amount)
{
	int counter = 0;

	while(counter < threads_amount) {
		pthread_join(threads[counter], NULL);
		counter++;
	}
}