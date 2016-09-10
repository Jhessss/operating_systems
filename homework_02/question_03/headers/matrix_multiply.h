#include <stdlib.h>

#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

int* get_matrix_size(int** matrix);
int* get_result_matrix_size(int* first_matrix_size, int* second_matrix_size);
int** alloc_matrix(int* matrix_size);
int multiply_cell(int* line, int* column, int size);

#endif
