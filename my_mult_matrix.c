#include "my_matrix.h"

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || B == NULL || A->rows <= 0 || A->columns <= 0 ||
      B->rows <= 0 || B->columns <= 0 || A->matrix == NULL || B->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else if (A->columns != B->rows)
    error_code = CALCULATION_ERROR;
  else {
    if ((error_code = my_create_matrix(A->rows, B->columns, result)) == OK)
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < B->columns; j++)
          for (int k = 0; k < A->columns; k++)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }

  return error_code;
}