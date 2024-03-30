#include "my_matrix.h"

int my_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = OK;

  if (result == NULL || rows <= 0 || columns <= 0)
    error_code = INCORRECT_MATRIX;
  else {
    size_t size = rows * columns * sizeof(double) + rows * sizeof(double *);
    result->matrix = malloc(size);

    if (result->matrix != NULL) {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) result->matrix[i] = ptr + columns * i;

      result->rows = rows;
      result->columns = columns;
      for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) result->matrix[i][j] = 0;
    } else
      error_code = CALCULATION_ERROR;
  }

  return error_code;
}