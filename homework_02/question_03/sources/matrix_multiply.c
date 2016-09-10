#include "matrix_multiply.h"

int* get_result_matrix_size(int* first_matrix_size, int* second_matrix_size)
{
	// Second Matrix must be Transposed
	int* size = malloc(2*sizeof(int));
	size[0] = 0;
	size[1] = 0;

	if(first_matrix_size[1] == second_matrix_size[1])
	{
		size[0] = first_matrix_size[0];
		size[1] = second_matrix_size[0];
	}

	return size;
}

int** alloc_matrix(int* matrix_size)
{
	int** matrix = malloc(matrix_size[0]*sizeof(int*));
	int i;
	for(i = 0; i < matrix_size[0]; i++)
	{
		matrix[i] = malloc(matrix_size[1]*sizeof(int));
	}

	return matrix;
}

int multiply_cell(int* row, int* column, int size)
{
	int result = 0;

	int i;
	for(i = 0; i < size; i++)
	{
		result += row[i]*column[i];
	}

	return result;
}
