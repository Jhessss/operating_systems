#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H

#include <pthread.h>

struct thread_w_arguments
{
	int* vector_v;
	int* vector_w;
	int vector_position;
};

struct second_step_threads_arguments
{
	int* vector_v;
	int* vector_w;
	int first_position;
	int second_position;
};


void* fill_vector_w(void* thread_arguments);
void create_threads_w(pthread_t* threads, struct thread_w_arguments* thread_args, int* vector_v,
	int* vector_w, int threads_amount);
void join_threads(pthread_t* threads, int threads_amount);
void create_second_step_threads(pthread_t* threads, struct second_step_threads_arguments* thread_args,
	int* vector_v, int* vector_w, int integers_amount);
void create_third_step_threads(pthread_t* threads, struct thread_w_arguments* thread_args, int* vector_v,
	int* vector_w, int threads_amount);
void* second_step(void* thread_arguments);

#endif