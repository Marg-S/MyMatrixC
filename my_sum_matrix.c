#include "my_matrix.h"

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || B == NULL || A->rows <= 0 || A->columns <= 0 ||
      B->rows <= 0 || B->columns <= 0 || A->matrix == NULL || B->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else if (A->rows != B->rows || A->columns != B->columns)
    error_code = CALCULATION_ERROR;
  else if ((error_code = my_create_matrix(A->rows, A->columns, result)) == OK)
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];

  return error_code;
}