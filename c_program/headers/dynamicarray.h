#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a dynamic linear array of specified size.
 *
 * @param size The number of elements in the array
 * @param actual_size Pointer to store the actual size of the created array.
 * @return Pointer to the created array, or NULL if allocation falied.
 */

int *create_dynamic_linear_array(int size, int *actual_size);
int **create_dynamic_matrix(int rows, int cols, int *actual_rows,
                            int *actual_cols);
/**
 * Prints the content of a dynamic array.
 *
 * @param arr The array to print.
 * @param size The number of elements in the array.
 */

void print_dynamic_array(const int *arr, int size);
void print_dynamic_matrix(int **matrix, int rows, int cols);

void dynamic_linear_array(void);
void dynamic_matrix_array(void);

#endif
