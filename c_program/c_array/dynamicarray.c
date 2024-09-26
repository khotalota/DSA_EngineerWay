#include "../headers/dynamicarray.h"

// Function of an 1D array type
int *create_dynamic_linear_array(int size, int *actual_size) {
  if (size <= 0) {
    fprintf(stderr, "Invaild size. Must be greater than 0.\n");
    *actual_size = 0;
    return NULL;
  }

  int *dynamicarray = malloc(size * sizeof(int));

  if (dynamicarray == NULL) {
    fprintf(stderr, "Memeory allocation failed!\n");
    *actual_size = 0;
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    dynamicarray[i] = i * 10;
  }

  *actual_size = size;
  return dynamicarray;
}

// Print 1D array type
void print_dynamic_array(const int *arr, int size) {
  if (arr == NULL || size <= 0) {
    fprintf(stderr, "Invalid array or size.\n");
    return;
  }

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function implementation for 1D array
void dynamic_linear_array() {
  int size = 10;
  int actual_size;
  int *dynamicarray = create_dynamic_linear_array(size, &actual_size);

  if (dynamicarray != NULL) {
    print_dynamic_array(dynamicarray, actual_size);
    free(dynamicarray);
  }
}

// Function to a 2D(Matrix) array type
int **create_dynamic_matrix(int rows, int cols, int *actual_rows,
                            int *actual_cols) {
  if (rows <= 0 || cols <= 0) {
    fprintf(stderr,
            "Invalid matrix size. Rows and columns must be greater than 0.\n");
    *actual_rows = 0;
    *actual_cols = 0;
    return NULL;
  }

  int **matrix = malloc(rows * sizeof(int *));

  if (matrix == NULL) {
    fprintf(stderr, "Memeory allocation for matrix failed!\n");
    *actual_rows = 0;
    *actual_cols = 0;
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
    if (matrix[i] == NULL) {
      fprintf(stderr, "Memeory allocation for row %d failed!\n", i);
      *actual_rows = 0;
      *actual_cols = 0;
      return NULL;
    }

    // Put some values (ex:- i+j)
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = (i + 1) * (j + 1);
    }
  }
  *actual_rows = rows;
  *actual_cols = cols;
  return matrix;
}

// Print Matrix
void print_dynamic_matrix(int **matrix, int rows, int cols) {
  if (matrix == NULL || rows <= 0 || cols <= 0) {
    fprintf(stderr, "Invalid matrix or size.\n");
    return;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Matrix implementation
void dynamic_matrix_array() {
  int rows = 3;
  int cols = 4;
  int actual_rows, actual_cols;

  int **matrix = create_dynamic_matrix(rows, cols, &actual_rows, &actual_cols);

  if (matrix != NULL) {
    print_dynamic_matrix(matrix, actual_rows, actual_cols);

    // Free stuff
    for (int i = 0; i < actual_rows; i++) {
      free(matrix[i]);
    }
    free(matrix);
  }
}
