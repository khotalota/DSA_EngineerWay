#include "../headers/lineararray.h"

void linear_declaration() {
  int arr[5] = {10, 12, 13, 14, 15};

  int arr1[] = {1, 2, 34, 6, 5, 6, 7, 7};

  for (int i = 0; i < 5; i++) {
    printf("%d %d\n", arr[i], arr1[i]);
  }

  printf("\n");
}

void matrix_declaration() {
  int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  printf("%d\n", matrix[2][3]);

  char buffer[50];
  sprintf(buffer, "%d", matrix[2][3]);
  puts(buffer);
}
