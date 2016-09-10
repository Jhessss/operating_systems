#include "benchmark.h"
#include "matrix_multiply.h"
#include <stdio.h>
#include <pthread.h>

// Main functions
void get_matrices();
void setup_result_matrix();
void show_result_matrix();
void free_data();

void setup_threads();
void* thread_multiply_cell(void *parameters);
void join_threads();

int get_cpu_quantity();

// Thread Struct
struct parameters
{
	int row;
	int column;
};

// Global Variables
struct timespec initial_time;
int i,j;

int** first_matrix;
int* first_matrix_size;

int** second_matrix;
int* second_matrix_size;

int** result_matrix;
int* result_matrix_size;

int main()
{
	get_matrices();
	setup_result_matrix();

	if(result_matrix != NULL)
	{
		// Quantity of CPUs
		int cpu_quantity = get_cpu_quantity();

		// Threads Setup
		pthread_t* threads;
		struct parameters* params;

		threads = malloc(cpu_quantity*sizeof(pthread_t));
		params = malloc(cpu_quantity*sizeof(struct parameters));

		initial_time = get_time();

		// Critical Section
		int total_active_threads = 0;
		int threads_activated = 0;
		int total_operations = result_matrix_size[0]*result_matrix_size[1];
		for(i = 0; i < result_matrix_size[0]; i++)
		{
			for(j = 0; j < result_matrix_size[1]; j++)
			{
				if(total_active_threads < cpu_quantity
					&& threads_activated < total_operations)
				{
					// Since Second Matrix is Transposed,
					// second_matrix[j] is the column j, not row.
					params[total_active_threads].row = i;
					params[total_active_threads].column = j;
					pthread_create(&threads[total_active_threads], NULL,
						thread_multiply_cell, &params[total_active_threads]);

					total_active_threads++;
					threads_activated++;
				}

				if(total_active_threads >= cpu_quantity || threads_activated >= total_operations)
				{
					while(total_active_threads > 0)
					{
						pthread_join(threads[total_active_threads-1], NULL);
						total_active_threads--;
					}
				}
			}
		}

		unsigned long long int elapsed = get_time_elapsed(initial_time);

		free(threads);
		free(params);

		// Results
		printf("\n\nElapsed Time: %llu ns\n\n", elapsed);

		show_result_matrix();
	}
	else
	{
		printf("\nInvalid Input.\n");
	}

	free_data();

	return 0;
}

void get_matrices()
{
	// First Matrix
	first_matrix_size = malloc(2*sizeof(int));
	scanf("%d %d", &first_matrix_size[0], &first_matrix_size[1]);

	first_matrix = alloc_matrix(first_matrix_size);
	for(i = 0; i < first_matrix_size[0]; i++)
	{
		for(j = 0; j < first_matrix_size[1]; j++)
		{
			scanf("%d", &first_matrix[i][j]);
		}
	}

	// Second Matrix is TRANSPOSED
	second_matrix_size = malloc(2*sizeof(int));
	scanf("%d %d", &second_matrix_size[1], &second_matrix_size[0]);

	second_matrix = alloc_matrix(second_matrix_size);
	for(i = 0; i < second_matrix_size[1]; i++)
	{
		for(j = 0; j < second_matrix_size[0]; j++)
		{
			scanf("%d", &second_matrix[j][i]);
		}
	}
}

void setup_result_matrix()
{
	result_matrix_size = get_result_matrix_size(first_matrix_size, second_matrix_size);

	if(result_matrix_size[0] != 0 && result_matrix_size[1] != 0)
	{
		result_matrix = alloc_matrix(result_matrix_size);
	}
}

void show_result_matrix()
{
	for(i = 0; i < result_matrix_size[0]; i++)
	{
		for(j = 0; j < result_matrix_size[1]; j++)
		{
			printf("%d", result_matrix[i][j]);
			if(j == result_matrix_size[1]-1)
			{
				printf("\n");
			}
			else
			{
				printf("\t");
			}
		}
	}
}

void free_data()
{
	free(first_matrix);
	free(first_matrix_size);
	free(second_matrix);
	free(second_matrix_size);
	free(result_matrix);
	free(result_matrix_size);
}

void* thread_multiply_cell(void *params)
{
	struct parameters* p = (struct parameters*) params;

	result_matrix[p->row][p->column] = multiply_cell(first_matrix[p->row], second_matrix[p->column], first_matrix_size[1]);

	return NULL;
}

int get_cpu_quantity()
{
	int cpu_quantity = 0;

	FILE* file = popen("cat /proc/cpuinfo | grep -c processor", "r");

	fscanf(file, "%d", &cpu_quantity);

	pclose(file);

	return cpu_quantity;
}
